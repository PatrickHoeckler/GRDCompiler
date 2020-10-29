#include "GRDparser\GRDrules.h"

const int nTerminals    = 53;
const int nNonTerminals = 27;
const int nProductions  = 73;

int parseTable[27][53] = {
//  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52
  {-1, -1, -1, -1, -1, -1, -1, -1, -1,  0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
  {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  1,  1, -1, -1,  1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
  {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  3,  2, -1, -1,  3, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
  {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  4, -1, -1, -1, -1, -1,  5, -1, -1, -1,  5, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
  {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  6, -1, -1, -1,  7, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
  {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,  8, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
  {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 10, -1, -1, -1,  9, -1, 10, -1, -1, -1},
  {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, 12, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 12, -1, -1, -1},
  {-1, -1, -1, -1, -1, 15, -1, 16, -1, -1, -1, -1, -1, -1, 13, -1, -1, -1, -1, -1, -1, -1, -1, -1, 14, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
  {-1, -1, -1, -1, -1, 20, -1, 21, -1, -1, -1, -1, -1, -1, 18, -1, -1, -1, -1, -1, -1, -1, -1, -1, 19, -1, -1, 17, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
  {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 22, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 23, 23, -1, -1, 23, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
  {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 25, -1, -1, -1, 25, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 24, -1, -1},
  {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 26, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
  {27, 27, 28, -1, -1, -1, 27, -1, 27, -1, -1, -1, -1, -1, -1, 27, 27, -1, 27, 28, -1, -1, -1, -1, -1, 27, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 27, 27, 27, 27, -1, -1, 27, -1, -1, -1, -1, -1, -1, -1, 27, -1, -1},
  {34, 30, -1, -1, -1, -1, 31, -1, 32, -1, -1, -1, -1, -1, -1, 29, 72, -1, 35, -1, -1, -1, -1, -1, -1, 33, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 72, 72, 72, 72, -1, -1, 36, -1, -1, -1, -1, -1, -1, -1, 72, -1, -1},
  {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 38, -1, -1, -1, -1, -1, -1, -1, 37, -1, -1},
  {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 39, -1, 40, -1, -1, -1},
  {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 41, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 41, 41, 41, 41, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 41, -1, -1},
  {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 42, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 42, 42, 42, 42, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 42, -1, -1},
  {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 44, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 47, 43, 45, 46, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 48, -1, -1},
  {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 52, 51, 49, 54, 53, 50, -1, -1, -1, -1, -1, 55, -1, 55, -1, -1, -1, -1, 55, -1, 55, -1, -1, -1},
  {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 58, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 56, 58, 58, 58, 58, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 58, -1, 57},
  {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 61, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 62, 62, 62, 62, 62, 62, 59, -1, -1, -1, -1, 62, -1, 62, -1, -1, -1, -1, 62, -1, 62, -1, -1, 60},
  {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 66, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 65, 66, 66, 66, 66, 66, 66, 66, -1, -1, -1, -1, 66, -1, 66, -1, 64, -1, -1, 66, 63, 66, -1, -1, 66},
  {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 67, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 68, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
  {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 69, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
  {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 70, -1, 71, -1, -1, -1}
};

int productions[73][13] = {
  // | <---- 1 int ----> | <--- 10 ints ---> |
  // | production length | production values |
  { 5, GRD_PROGRAM, GRD_ID, GRD_SEMICOLON, GRD_R_BLOCO, GRD_DOT},
  { 4, GRD_R_DCLPROC, GRD_R_DCLCONST, GRD_R_DCLVAR, GRD_R_CORPO},
  { 6, GRD_CONST, GRD_ID, GRD_EQUAL, GRD_R_TIPO, GRD_SEMICOLON, GRD_R_LDCONST},
  { 0},
  { 5, GRD_ID, GRD_EQUAL, GRD_R_TIPO, GRD_SEMICOLON, GRD_R_LDCONST},
  { 0},
  { 6, GRD_DECLARAVARIAVEIS, GRD_R_LID, GRD_COLON, GRD_R_TIPO, GRD_SEMICOLON, GRD_R_LDVAR},
  { 0},
  { 2, GRD_ID, GRD_R_REPIDENT},
  { 3, GRD_COMMA, GRD_ID, GRD_R_REPIDENT},
  { 0},
  { 5, GRD_R_LID, GRD_COLON, GRD_R_TIPO, GRD_SEMICOLON, GRD_R_LDVAR},
  { 0},
  { 1, GRD_INTEGER},
  { 1, GRD_CHAR},
  { 1, GRD_STRING},
  { 1, GRD_REAL},
  { 8, GRD_ARRAY, GRD_LBRACKET, GRD_L_INT, GRD_DDOT, GRD_L_INT, GRD_RBRACKET, GRD_OF, GRD_R_TIPOARRAY},
  { 1, GRD_INTEGER},
  { 1, GRD_CHAR},
  { 1, GRD_STRING},
  { 1, GRD_REAL},
  { 7, GRD_PROCEDURE, GRD_ID, GRD_R_DEFPAR, GRD_R_DCLVAR, GRD_R_CORPO, GRD_SEMICOLON, GRD_R_DCLPROC},
  { 0},
  { 7, GRD_LPARENTHESIS, GRD_R_LID, GRD_COLON, GRD_R_TIPO, GRD_SEMICOLON, GRD_R_LDVAR, GRD_RPARENTHESIS},
  { 0},
  { 5, GRD_BEGIN, GRD_R_COMANDO, GRD_SEMICOLON, GRD_R_REPCOMANDO, GRD_END},
  { 3, GRD_R_COMANDO, GRD_SEMICOLON, GRD_R_REPCOMANDO},
  { 0},
  { 7, GRD_IF, GRD_LBRACKET, GRD_R_EXPRESSAO, GRD_RBRACKET, GRD_THEN, GRD_R_CORPO, GRD_R_ELSEPARTE},
  { 6, GRD_WHILE, GRD_LBRACKET, GRD_R_EXPRESSAO, GRD_RBRACKET, GRD_DO, GRD_R_CORPO},
  { 8, GRD_REPEAT, GRD_R_COMANDO, GRD_SEMICOLON, GRD_R_REPCOMANDO, GRD_UNTIL, GRD_LBRACKET, GRD_R_EXPRESSAO, GRD_RBRACKET},
  { 4, GRD_READ, GRD_LPARENTHESIS, GRD_R_VARIAVEL, GRD_RPARENTHESIS},
  { 3, GRD_CHAMAPROCEDURE, GRD_ID, GRD_R_PARAMETROS},
  { 5, GRD_WRITE, GRD_LPARENTHESIS, GRD_R_EXPRESSAO, GRD_R_REPITEM, GRD_RPARENTHESIS},
  {12, GRD_FOR, GRD_LBRACKET, GRD_ID, GRD_EQUAL, GRD_R_EXPRESSAO, GRD_RBRACKET, GRD_TO, GRD_LBRACKET, GRD_R_EXPRESSAO, GRD_RBRACKET, GRD_DO, GRD_R_CORPO},
  { 0},
  { 3, GRD_LPARENTHESIS, GRD_R_LID, GRD_RPARENTHESIS},
  { 0},
  { 3, GRD_COMMA, GRD_R_EXPRESSAO, GRD_R_REPITEM},
  { 0},
  { 3, GRD_R_TERMO, GRD_R_REPEXP, GRD_R_REPEXPSIMP},
  { 2, GRD_R_FATOR, GRD_R_REPTERMO},
  { 1, GRD_L_INT},
  { 1, GRD_ID},
  { 1, GRD_L_STR},
  { 1, GRD_L_CHAR},
  { 1, GRD_L_REAL},
  { 3, GRD_LPARENTHESIS, GRD_R_EXPRESSAO, GRD_RPARENTHESIS},
  { 2, GRD_EQUAL, GRD_R_EXPSIMP},
  { 2, GRD_LT,    GRD_R_EXPSIMP},
  { 2, GRD_GT,    GRD_R_EXPSIMP},
  { 2, GRD_GTE,   GRD_R_EXPSIMP},
  { 2, GRD_LTE,   GRD_R_EXPSIMP},
  { 2, GRD_DIF,   GRD_R_EXPSIMP},
  { 0},
  { 3, GRD_PLUS, GRD_R_TERMO, GRD_R_REPEXP},
  { 3, GRD_MIN,  GRD_R_TERMO, GRD_R_REPEXP},
  { 2,           GRD_R_TERMO, GRD_R_REPEXP},
  { 3, GRD_PLUS, GRD_R_TERMO, GRD_R_REPEXP},
  { 3, GRD_MIN,  GRD_R_TERMO, GRD_R_REPEXP},
  { 3, GRD_OR,   GRD_R_TERMO, GRD_R_REPEXP},
  { 0},
  { 3, GRD_STAR, GRD_R_FATOR, GRD_R_REPTERMO},
  { 3, GRD_DIV,  GRD_R_FATOR, GRD_R_REPTERMO},
  { 3, GRD_AND,  GRD_R_FATOR, GRD_R_REPTERMO},
  { 0},
  { 2, GRD_ELSE, GRD_R_CORPO},
  { 0},
  { 2, GRD_ID, GRD_R_REPVARIAVEL},
  { 3, GRD_COMMA, GRD_ID, GRD_R_REPVARIAVEL},
  { 0},
  { 1, GRD_R_EXPRESSAO} //<COMANDO> ::= <EXPRESSAO>
};

const enum GRDnonTerminal startRule = GRD_R_PROGRAMA;

char* GRDnonTerminal2string(enum GRDnonTerminal x) {
  switch (x)
  {
  case GRD_R_PROGRAMA : return "<PROGRAMA>";
  case GRD_R_BLOCO : return "<BLOCO>";
  case GRD_R_DCLCONST : return "<DCLCONST>";
  case GRD_R_LDCONST : return "<LDCONST>";
  case GRD_R_DCLVAR : return "<DCLVAR>";
  case GRD_R_LID : return "<LID>";
  case GRD_R_REPIDENT : return "<REPIDENT>";
  case GRD_R_LDVAR : return "<LDVAR>";
  case GRD_R_TIPOARRAY : return "<TIPOARRAY>";
  case GRD_R_TIPO : return "<TIPO>";
  case GRD_R_DCLPROC : return "<DCLPROC>";
  case GRD_R_DEFPAR : return "<DEFPAR>";
  case GRD_R_CORPO : return "<CORPO>";
  case GRD_R_REPCOMANDO : return "<REPCOMANDO>";
  case GRD_R_COMANDO : return "<COMANDO>";
  case GRD_R_PARAMETROS : return "<PARAMETROS>";
  case GRD_R_REPITEM : return "<REPITEM>";
  case GRD_R_EXPRESSAO : return "<EXPRESSAO>";
  case GRD_R_TERMO : return "<TERMO>";
  case GRD_R_FATOR : return "<FATOR>";
  case GRD_R_REPEXPSIMP : return "<REPEXPSIMP>";
  case GRD_R_EXPSIMP : return "<EXPSIMP>";
  case GRD_R_REPEXP : return "<REPEXP>";
  case GRD_R_REPTERMO : return "<REPTERMO>";
  case GRD_R_ELSEPARTE : return "<ELSEPARTE>";
  case GRD_R_VARIAVEL : return "<VARIAVEL>";
  case GRD_R_REPVARIAVEL : return "<REPVARIALVEL>";
  default: return "N/A";
  }
}