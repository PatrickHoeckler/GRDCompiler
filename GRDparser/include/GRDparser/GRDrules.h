#ifndef GRDRULES_H
#define GRDRULES_H

#include "GRDlexer\GRDautomata.h"

enum GRDnonTerminal {
  GRD_R_PROGRAMA = 53,
  GRD_R_BLOCO,
  GRD_R_DCLCONST,
  GRD_R_LDCONST,
  GRD_R_DCLVAR,
  GRD_R_LID,
  GRD_R_REPIDENT,
  GRD_R_LDVAR,
  GRD_R_TIPOARRAY,
  GRD_R_TIPO,
  GRD_R_DCLPROC,
  GRD_R_DEFPAR,
  GRD_R_CORPO,
  GRD_R_REPCOMANDO,
  GRD_R_COMANDO,
  GRD_R_PARAMETROS,
  GRD_R_REPITEM,
  GRD_R_EXPRESSAO,
  GRD_R_TERMO,
  GRD_R_FATOR,
  GRD_R_REPEXPSIMP,
  GRD_R_EXPSIMP,
  GRD_R_REPEXP,
  GRD_R_REPTERMO,
  GRD_R_ELSEPARTE,
  GRD_R_VARIAVEL,
  GRD_R_REPVARIAVEL
};

extern const enum GRDnonTerminal startRule;
extern const int nTerminals;
extern const int nProductions;
extern const int nNonTerminals;
extern int parseTable[27][53];
extern int productions[73][13];

char* GRDnonTerminal2string(enum GRDnonTerminal x);

#endif
