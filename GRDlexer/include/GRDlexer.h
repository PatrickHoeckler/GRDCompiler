#ifndef GRDLEXER_H
#define GRDLEXER_H

#include "GRDautomata.h"

#define GRD_BUFFERSIZE 512

//Estrutura definindo um token
//  code - enumerador indicando qual token
//  value - string que representa o lexema lido
//  line - linha aonde o token foi lido
struct GRDtoken {
  enum GRDcode code;
  unsigned char* value;
  unsigned int line;
};

//funcao do analisador lexico - armazena no endereco _tokens um vetor
//de todos os tokens do programa; armazena em nTokens o tamanho do vetor de tokens
int GRDlexer(char* filename, struct GRDtoken **_tokens, unsigned int *nTokens);

#endif