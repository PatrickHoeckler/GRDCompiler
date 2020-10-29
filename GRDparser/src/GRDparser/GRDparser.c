#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "GRDerror.h"
#include "GRDlexer\GRDlexer.h"
#include "GRDparser\GRDrules.h"
#include "GRDparser\GRDparser.h"

const unsigned int GRD_STACKSIZE = 128;
extern const enum GRDnonTerminal startRule;
extern int parseTable[27][53];
extern int productions[73][13];
extern const int nTerminals;
extern const int nProductions;
extern const int nNonTerminals;

int GRDparser(struct GRDtoken *tokens, unsigned int nTokens, struct GRDerror_parser **_errors, unsigned int *_nErrors) {
  if (tokens == NULL) return -1;

  //declarando vetor de erros
  struct GRDerror_parser *errors = NULL;
  unsigned int errorsMax = 0;
  unsigned int nErrors = 0;
  //alocando memoria para o vetor de tokens
  int *stack = (int*)malloc(GRD_STACKSIZE * sizeof(int));
  if (stack == NULL) {return ENOMEM;}
  unsigned int stackMax = GRD_STACKSIZE; //tamanho do vetor alocado
  unsigned int stackSize = 2; //quantidade de elementos na pilha
  stack[0] = GRD_DOLLAR;  //adiciona o simbolo base
  stack[1] = startRule;   //adiciona a regra inicial
  int *stackTop = stack + 1;  //endereco do topo da pilha

  //imprime cabecalho da tabela do passo a passo -- DELETAR ISSO QUANDO FOR FAZER O SINTATICO
  printf(" LINHA |          ACAO           |   SIMBOLO ATUAL  | VALOR DO SIMBOLO |  PILHA\n");

  unsigned int i = 0;
  int nextProduction, symbol;
  int errorBefore = 0, errorSeen = 0;
  while (1) {
    if (stackSize == 1) break;
    if (tokens[i].code < 0) {errorBefore = 1; i++; continue;}
    if (i < nTokens ) symbol = tokens[i].code;
    else {symbol = -1; errorBefore = 0;}

    //se topo da pilha contem um terminal
    if (*stackTop < GRD_R_PROGRAMA) {
      //se o token atual combina com o topo da pilha
      //retira o simbolo da pilha e avanca para o proximo token
      if (*stackTop == symbol) {
        printStep(1, *stackTop, tokens[i], stack, stackSize);
        i++;
        stackTop--;
        stackSize--;
        errorBefore = 0;
      }
      //senao: erro sintatico
      else {
        if (i < nTokens ) printStep(-1, 0, tokens[i], stack, stackSize);
        if (!errorBefore) {
          //--Adiciona ao vetor de erros--
          //redimensiona vetor se necessario
          if (nErrors == errorsMax) {
            errorsMax += 20;
            struct GRDerror_parser *temp = (struct GRDerror_parser *)realloc(errors, errorsMax * sizeof(struct GRDerror_parser));
            if (temp == NULL) {
              free(stack);
              free(errors);
              return ENOMEM;
            } errors = temp;
          }
          errors[nErrors].stackTop = *stackTop;
          if (i < nTokens ) errors[nErrors++].token = tokens[i];
          else errors[nErrors++].token.line = 0;
        }
        //desimpilha topo que causou erro
        errorBefore = 1;
        errorSeen = 1;
        stackTop--;
        stackSize--;
        continue;
      }
    }

    //se o topo contem um nao terminal
    else {
      if (symbol == -1) {
        stackTop--;
        stackSize--;
        continue;
      }

      nextProduction = parseTable[*stackTop - GRD_R_PROGRAMA][symbol];
      //se erro sintatico
      if (nextProduction == -1) {
        printStep(-2, 0, tokens[i], stack, stackSize);
        //--Adiciona ao vetor de erros se nao ocorreu erros imediatamente antes desse--
        if (!errorBefore) {
          //redimensiona vetor se necessario
          if (nErrors == errorsMax) {
            errorsMax += 20;
            struct GRDerror_parser *temp = (struct GRDerror_parser *)realloc(errors, errorsMax * sizeof(struct GRDerror_parser));
            if (temp == NULL) {
              free(stack);
              free(errors);
              return ENOMEM;
            } errors = temp;
          }
          errors[nErrors].stackTop = *stackTop;
          errors[nErrors++].token = tokens[i];
        }
        //*Substitui por producao valida que tem o menor tamanho
        int _length = -1;
        for (int j = 0; j < nTerminals; j++) {
          int temp = parseTable[*stackTop - GRD_R_PROGRAMA][j];
          if (temp != -1) {
            if (productions[temp][0] < _length || _length == -1) {
              _length = productions[temp][0];
              nextProduction = temp;
            }
          }
        }
        errorBefore = 2;
        errorSeen = 1;
      }

      //Seleciona producao
      int *production = productions[nextProduction];
      int prodLen = production[0];

      //se producao leva ao simbolo vazio
      if (prodLen == 0) {
        if (errorBefore) errorBefore -= 1;
        if (!errorBefore)printStep(0, nextProduction, tokens[i], stack, stackSize);
        stackTop--;
        stackSize--;
        continue;
      }

      if (errorBefore) errorBefore -= 1;
      if (!errorBefore)printStep(0, nextProduction, tokens[i], stack, stackSize);
      //Redimensiona pilha se necessario
      if (stackSize + prodLen >= stackMax) {
        stackMax += GRD_STACKSIZE;
        int* temp = (int*)realloc(stack, stackMax * sizeof(int));
        if (temp == NULL) { free(stack); return ENOMEM; }
        stack = temp;
      }

      //Carrega producao na pilha, colocando na ordem reversa
      stackTop--; //volta 1 para substituir a producao pai
      for (int j = prodLen; j > 0; j--) {
        stackTop++;
        *stackTop = production[j];
      }
      stackSize += prodLen - 1;  //-1 pois substituiu a producao pai
    }
  }

  free(stack);
  *_errors = errors;
  *_nErrors = nErrors;
  //se a pilha terminou vazia
  if (stackSize == 1 && !errorSeen) return 0;
  //senao erro lexico
  return EFAULT;
}

void printStep(char option, int code, struct GRDtoken token, int* stack, int stackSize) {
  char value[4];
  if (token.value == NULL) sprintf(value, "%d", token.code);
  if (option == -1)
    printf(" %-5d |          ERRO T         | %-16s | %-16.16s | ",
    token.line, GRDterminal2string(token.code), 
    token.value == NULL ? value : token.value);
  else if (option == -2)
    printf(" %-5d |          ERRO NT        | %-16s | %-16.16s | ",
    token.line, GRDterminal2string(token.code),
    token.value == NULL ? value : token.value);
  else if (option)
    printf(" %-5d | casou: %-16s | %-16s | %-16.16s | ",
    token.line, GRDterminal2string(code), GRDterminal2string(token.code),
    token.value == NULL ? value : token.value);
  else
    printf(" %-5d | producao: %-13d | %-16s | %-16.16s | ",
    token.line, code, GRDterminal2string(token.code),
    token.value == NULL ? value : token.value);
  for (int i = 0; i < stackSize; i++) {
    if (stack[i] < GRD_R_PROGRAMA)
      printf("%s ", GRDterminal2string(stack[i]));
    else
      printf("%s ", GRDnonTerminal2string(stack[i]));
  }
  printf("\n");
}