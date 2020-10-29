#include <stdio.h>

#include "GRDlexer\GRDautomata.h"
#include "GRDparser\GRDrules.h"
#include "GRDerror.h"

extern int parseTable[27][53];
extern int productions[73][13];
extern const int nTerminals;
extern const int nProductions;
extern const int nNonTerminals;

int reportLexErrors(struct GRDtoken *tokens, unsigned int nTokens) {
  if (tokens == NULL) return -1;
  int r = 0;
  for (unsigned int i = 0; i < nTokens; i++) {
    int code = tokens[i].code;
    if (code > GRD_NULL) continue;
    r++;
    if (code == GRD_NULL) {
      printf("ERRO: na linha %d. Erro nao reconhecido: `%s`\n",
      tokens[i].line, tokens[i].value);
    }
    else if (code == GRD_ERR_EX) {
      printf("ERRO: na linha %d. Caracteres invalidos utilizados: `%s`\n",
      tokens[i].line, tokens[i].value);
    }
    else if (code == GRD_ERR_STR) {
      printf("ERRO: na linha %d. literal string nao terminado: `%s`\n",
      tokens[i].line, tokens[i].value);
    }
    else if (code == GRD_ERR_CHAR) {
      printf("ERRO: na linha %d. literal char nao terminado: `%s`\n",
      tokens[i].line, tokens[i].value);
    }
    else if (code == GRD_ERR_ESCS || code == GRD_ERR_ESCC) {
      printf("ERRO: na linha %d. sequencia de escape inexistente: `%s`\n",
      tokens[i].line, tokens[i].value);
    }
    else {
      printf("ERRO: na linha %d. Sequencia invalida de caracteres: `%s`\n",
      tokens[i].line, tokens[i].value);
    }
  }
  return r;
}

void reportParserErrors(struct GRDerror_parser *errors, unsigned int nErrors) {
  for (unsigned int i = 0; i < nErrors; i++) {
    if (errors[i].token.line == 0) {
      printf("ERRO: Faltando `%s` no fim do codigo\n", 
      GRDterminal2string(errors[i].stackTop));
    }
    else if (errors[i].stackTop < GRD_R_PROGRAMA) {
      printf("ERRO: na linha %d. Esperava `%s`. Encontrou `%s`\n", errors[i].token.line,
      GRDterminal2string(errors[i].stackTop), GRDterminal2string(errors[i].token.code));
    }
    else {
      printf("ERRO: na linha %d. Esperava ", errors[i].token.line);
      char _flag = 0;
      int lastTerminal = -1;
      for (int j = 0; j < nTerminals; j++) {
        int temp = parseTable[errors[i].stackTop - GRD_R_PROGRAMA][j];
        if (temp != -1) {
          if (!_flag) {printf("`%s`", GRDterminal2string(j)); _flag = 1;}
          else {
            if (lastTerminal != -1) printf(", `%s`", GRDterminal2string(lastTerminal));
            lastTerminal = j;
          }
        }
      }
      printf(", ou `%s`", GRDterminal2string(lastTerminal));
      printf(". Encontrou `%s`\n", errors[i].token.value ?
      errors[i].token.value : GRDterminal2string(errors[i].token.code));
    }
  }
  return;
}