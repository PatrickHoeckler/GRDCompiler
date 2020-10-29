#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "GRDlexer\GRDautomata.h"
#include "GRDlexer\GRDlexer.h"

int GRDlexer(char* filename, struct GRDtoken** _tokens, unsigned int *_nTokens) {
  //abrindo arquivo e criando buffer para leitura
  FILE *file = fopen(filename, "r");
  if (file == NULL) return errno;
  char buffer[GRD_BUFFERSIZE];
  const int size = GRD_BUFFERSIZE;

  //alocando memoria para o vetor de tokens
  struct GRDtoken* tokens = malloc(100 * sizeof(struct GRDtoken));
  if (tokens == NULL) {fclose(file); return ENOMEM;}
  unsigned int tokenSize = 100; //tamanho do vetor alocado
  unsigned int nTokens = 0; //quantidade de tokens lidos

  //Analisando arquivo
  unsigned int line = 1;
  char wholeLine = 0; //indica se o buffer leu a linha inteira
  char *value = NULL; //valor do lexema
  enum GRDstate curState = GRD_ST_VAZIO; //estado do automato
  while (!feof(file)) {
    //preenche buffer e checa se foi o suficiente para ler toda a linha
    buffer[size - 1] = 'G';
    fgets(buffer, size, file);
    if ((buffer[size - 1] == 'G') || (buffer[size - 2] == '\n')) wholeLine = 1;

    struct GRDtoken token;
    int lexemeStart = 0;
    int lexemeLength = 0;
    //analisa buffer por tokens
    for (int i = 0; i < size; i++) {
      unsigned char byte = buffer[i];
      enum GRDstate nextState = nierAutomata(curState, byte);

      //ESSE IF É USADO PARA DETECTAR CASOS ESPECIAIS:
      //aonde existem operacoes de soma e subtracao e o numero que vem
      //depois do sinal nao esta separado por espaco
      if (
        (nextState == GRD_ST_PLUS || nextState == GRD_ST_MIN)
        &&
        (byte != buffer[i + 1])
        &&
        (tokens[nTokens - 1].code == GRD_L_INT || 
         tokens[nTokens - 1].code == GRD_L_REAL || 
         tokens[nTokens - 1].code == GRD_ID)
      ) {
        curState = nextState;
        nextState = GRD_ST_NULL;
        lexemeLength++;
        i++;
      }
      //ESSE IF É USADO PARA DETECTAR CASOS ESPECIAIS:
      //para separar coretamente INT .. INT em casos sem espaços separando
      //por exemplo: array[1..10]
      else if (nextState == GRD_ST_L_REAL && byte == '.' && buffer[i + 1] == '.')
        nextState = GRD_ST_NULL;
        
      //se GRD_ST_VAZIO lexema começa no proximo byte
      if (nextState == GRD_ST_VAZIO) lexemeStart = i + 1;
      //se GRD_ST_NULL, nao existe transicao de curState com byte
      //ou seja, o byte lido pertence ao proximo lexema
      else if (nextState != GRD_ST_NULL) {
        curState = nextState;
        lexemeLength++;
      }
      //senao, encontrou um token e deve adiciona-lo no vetor tokens
      else {
        token.code = GRDstate2terminal(curState);
        token.line = line;

        //se encontrou algo que deve ser ignorado
        if (token.code == GRD_CB || token.code == GRD_CL) {
          //reinicia o automato e o lexema
          curState = GRD_ST_VAZIO;
          lexemeStart = i--;
          lexemeLength = 0;
          if (byte == 0) break;
          continue;
        }

        //se encontrou sequencia de escape invalida
        //avanca leitura ate o fim da string ou da linha
        if (token.code == GRD_ERR_ESCC || token.code == GRD_ERR_ESCS) {
          char _stop = token.code == GRD_ERR_ESCC ? '\'' : '\"';
          while (i < size) {
            lexemeLength++;
            if (buffer[i++] == _stop) break;
          }
        }

        //se é preciso guardar a string que representa o token,
        //por exemplo, no caso de nome de variaveis, ou de literais.
        if (token.code == GRD_L_REAL || token.code == GRD_L_INT  ||
            token.code == GRD_L_STR  || token.code == GRD_L_CHAR ||
            token.code == GRD_ID     || token.code <= GRD_ERR_PLUS) {
          
          //Aloca memoria para armazenar valor
          char *temp = (char*)realloc(value, ((lexemeLength + 1) * sizeof(char)));
          if (temp == NULL) {
            for (unsigned int j = 0; j < nTokens; j++) free(tokens[j].value);
            free(value); free(tokens); fclose(file); return ENOMEM;
          } value = temp;

          //copia o lexema para value
          for (int j = 0; j < lexemeLength; j++) value[j] = buffer[lexemeStart + j];
          value[lexemeLength] = 0;

          //checa se o identificador representa palavra reservada e altera o token se sim
          if (token.code == GRD_ID) {
            token.code = reservedWord((char*)value);
            if (token.code != GRD_ID) {free(value); value = NULL;}
          }
          token.value = value;
          value = NULL;

        }
        else token.value = NULL;

        tokens[nTokens++] = token;
        //redimensiona vetor de tokens se necessario
        if (nTokens == tokenSize) {
          tokenSize *= 2;
          struct GRDtoken* temp = (struct GRDtoken*)realloc(tokens, tokenSize * sizeof(struct GRDtoken));
          if (temp == NULL) { free(tokens); fclose(file); return ENOMEM; }
          tokens = temp;
        }

        //reinicia o automato e o lexema
        curState = GRD_ST_VAZIO;
        lexemeStart = i--;
        lexemeLength = 0;
      }
      if (byte == 0) break;
    }
    if (wholeLine) { wholeLine = 0; line++;}
  }

  fclose(file);
  *_tokens = tokens;
  *_nTokens = nTokens;
  return 0;
}
