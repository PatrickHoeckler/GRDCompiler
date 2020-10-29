#ifndef GRDERROR_H
#define GRDERROR_H

#include "GRDlexer\GRDlexer.h"
#include "GRDparser\GRDrules.h"

struct GRDerror_parser {
  int stackTop;
  struct GRDtoken token;
};

int reportLexErrors(struct GRDtoken *tokens, unsigned int nTokens);
void reportParserErrors(struct GRDerror_parser *errors, unsigned int nErrors);

#endif