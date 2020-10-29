#ifndef GRDPARSER_H
#define GRDPARSER_H

#include "GRDlexer\GRDlexer.h"
#include "GRDparser\GRDrules.h"
#include "GRDerror.h"

void printStep(char option, int code, struct GRDtoken token, int* stack, int stackSize);
int GRDparser(struct GRDtoken *tokens, unsigned int nTokens, struct GRDerror_parser **_errors, unsigned int *_nErrors);

#endif