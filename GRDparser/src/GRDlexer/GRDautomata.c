#include <string.h>

#include "GRDlexer\GRDautomata.h"


char* GRDterminal2string(enum GRDterminal x) {
  switch (x)
  {
  case GRD_WRITE: return "write";
  case GRD_WHILE: return "while";
  case GRD_UNTIL: return "until";
  case GRD_TO: return "to";
  case GRD_THEN: return "then";
  case GRD_STRING: return "string";
  case GRD_REPEAT: return "repeat";
  case GRD_REAL: return "real";
  case GRD_READ: return "read";
  case GRD_PROGRAM: return "program";
  case GRD_PROCEDURE: return "procedure";
  case GRD_OR: return "or";
  case GRD_OF: return "of";
  case GRD_INTEGER: return "integer";
  case GRD_IF: return "if";
  case GRD_FOR: return "for";
  case GRD_END: return "end";
  case GRD_ELSE: return "else";
  case GRD_DO: return "do";
  case GRD_DECLARAVARIAVEIS: return "declaravariaveis";
  case GRD_CONST: return "const";
  case GRD_CHAR: return "char";
  case GRD_CHAMAPROCEDURE: return "chamaprocedure";
  case GRD_BEGIN: return "begin";
  case GRD_ARRAY: return "array";
  case GRD_AND: return "and";
  case GRD_EQUAL: return "equal";
  case GRD_RBRACKET: return "]";
  case GRD_LBRACKET: return "[";
  case GRD_SEMICOLON: return ";";
  case GRD_COLON: return ":";
  case GRD_COMMA: return ",";
  case GRD_STAR: return "*";
  case GRD_RPARENTHESIS: return ")";
  case GRD_LPARENTHESIS: return "(";
  case GRD_DOLLAR: return "$";
  case GRD_GT: return ">";
  case GRD_GTE: return ">=";
  case GRD_LT: return "<";
  case GRD_LTE: return "<=";
  case GRD_DIF: return "<>";
  case GRD_PLUS: return "+";
  case GRD_MIN: return "-";
  case GRD_DIV: return "/";
  case GRD_L_REAL: return "REAL";
  case GRD_L_INT: return "INT";
  case GRD_L_STR: return "STR";
  case GRD_L_CHAR: return "CHAR";
  case GRD_CL: return "COMENTLINHA";
  case GRD_CB: return "COMENTBLOCO";
  case GRD_EMPTY: return "EMPTY";
  case GRD_ID: return "id";
  case GRD_DOT: return ".";
  case GRD_DDOT: return "..";
  case GRD_ERR_PLUS: return "GRD_ERR_PLUS";
  case GRD_ERR_MINUS: return "GRD_ERR_MINUS";
  case GRD_ERR_DOT: return "GRD_ERR_DOT";
  case GRD_ERR_EX: return "GRD_ERR_EX";
  case GRD_ERR_STR: return "GRD_ERR_STR";
  case GRD_ERR_CHAR: return "GRD_ERR_CHAR";
  case GRD_ERR_ESCS: return "GRD_ERR_ESCS";
  case GRD_ERR_ESCC: return "GRD_ERR_ESCC";
  default: return "N/A";
  }
}

enum GRDterminal GRDstate2terminal(enum GRDstate x) {
  switch (x)
  {
  case GRD_ST_VAZIO: return GRD_EMPTY;
  case GRD_ST_ID: return GRD_ID;
  case GRD_ST_WRITE: return GRD_WRITE;
  case GRD_ST_WHILE: return GRD_WHILE;
  case GRD_ST_UNTIL: return GRD_UNTIL;
  case GRD_ST_TO: return GRD_TO;
  case GRD_ST_THEN: return GRD_THEN;
  case GRD_ST_STRING: return GRD_STRING;
  case GRD_ST_REPEAT: return GRD_REPEAT;
  case GRD_ST_REAL: return GRD_REAL;
  case GRD_ST_READ: return GRD_READ;
  case GRD_ST_PROGRAM: return GRD_PROGRAM;
  case GRD_ST_PROCEDURE: return GRD_PROCEDURE;
  case GRD_ST_OR: return GRD_OR;
  case GRD_ST_OF: return GRD_OF;
  case GRD_ST_INTEGER: return GRD_INTEGER;
  case GRD_ST_IF: return GRD_IF;
  case GRD_ST_FOR: return GRD_FOR;
  case GRD_ST_END: return GRD_END;
  case GRD_ST_ELSE: return GRD_ELSE;
  case GRD_ST_DO: return GRD_DO;
  case GRD_ST_DECLARAVARIAVEIS: return GRD_DECLARAVARIAVEIS;
  case GRD_ST_CONST: return GRD_CONST;
  case GRD_ST_CHAR: return GRD_CHAR;
  case GRD_ST_CHAMAPROCEDURE: return GRD_CHAMAPROCEDURE;
  case GRD_ST_BEGIN: return GRD_BEGIN;
  case GRD_ST_ARRAY: return GRD_ARRAY;
  case GRD_ST_AND: return GRD_AND;
  case GRD_ST_EQUAL: return GRD_EQUAL;
  case GRD_ST_RBRACKET: return GRD_RBRACKET;
  case GRD_ST_LBRACKET: return GRD_LBRACKET;
  case GRD_ST_SEMICOLON: return GRD_SEMICOLON;
  case GRD_ST_COLON: return GRD_COLON;
  case GRD_ST_COMMA: return GRD_COMMA;
  case GRD_ST_STAR: return GRD_STAR;
  case GRD_ST_RPARENTHESIS: return GRD_RPARENTHESIS;
  case GRD_ST_LPARENTHESIS: return GRD_LPARENTHESIS;
  case GRD_ST_DOLLAR: return GRD_DOLLAR;
  case GRD_ST_CL: return GRD_CL;
  case GRD_ST_CB1: return GRD_CB;
  case GRD_ST_CB2: return GRD_CB;
  case GRD_ST_CB3: return GRD_CB;
  case GRD_ST_PLUS: return GRD_PLUS;
  case GRD_ST_MIN: return GRD_MIN;
  case GRD_ST_DIV: return GRD_DIV;
  case GRD_ST_GT: return GRD_GT;
  case GRD_ST_GTE: return GRD_GTE;
  case GRD_ST_LT: return GRD_LT;
  case GRD_ST_LTE: return GRD_LTE;
  case GRD_ST_DIF: return GRD_DIF;
  case GRD_ST_L_INT: return GRD_L_INT;
  case GRD_ST_L_REAL: return GRD_L_REAL;
  case GRD_ST_L_STR: return GRD_L_STR;
  case GRD_ST_L_CHAR: return GRD_L_CHAR;
  case GRD_ST_DOT: return GRD_DOT;
  case GRD_ST_DDOT: return GRD_DDOT;
  case GRD_ST_ERR_EX: return GRD_ERR_EX;
  case GRD_ST_ERR_PLUS: return GRD_ERR_PLUS;
  case GRD_ST_ERR_MIN: return GRD_ERR_MINUS;
  case GRD_ST_ERR_DOT: return GRD_ERR_DOT;
  case GRD_ST_ERR_STR: return GRD_ERR_STR;
  case GRD_ST_ERR_CHAR: return GRD_ERR_CHAR;
  case GRD_ST_ERR_ESCS: return GRD_ERR_ESCS;
  case GRD_ST_ERR_ESCC: return GRD_ERR_ESCC;
  default: return GRD_NULL;
  }
}

enum GRDterminal reservedWord(char *word) {
  if (strcmp(word, "write"           ) == 0) return GRD_WRITE;
  if (strcmp(word, "while"           ) == 0) return GRD_WHILE;
  if (strcmp(word, "until"           ) == 0) return GRD_UNTIL;
  if (strcmp(word, "to"              ) == 0) return GRD_TO;
  if (strcmp(word, "then"            ) == 0) return GRD_THEN;
  if (strcmp(word, "string"          ) == 0) return GRD_STRING;
  if (strcmp(word, "repeat"          ) == 0) return GRD_REPEAT;
  if (strcmp(word, "real"            ) == 0) return GRD_REAL;
  if (strcmp(word, "read"            ) == 0) return GRD_READ;
  if (strcmp(word, "program"         ) == 0) return GRD_PROGRAM;
  if (strcmp(word, "procedure"       ) == 0) return GRD_PROCEDURE;
  if (strcmp(word, "or"              ) == 0) return GRD_OR;
  if (strcmp(word, "of"              ) == 0) return GRD_OF;
  if (strcmp(word, "integer"         ) == 0) return GRD_INTEGER;
  if (strcmp(word, "if"              ) == 0) return GRD_IF;
  if (strcmp(word, "for"             ) == 0) return GRD_FOR;
  if (strcmp(word, "end"             ) == 0) return GRD_END;
  if (strcmp(word, "else"            ) == 0) return GRD_ELSE;
  if (strcmp(word, "do"              ) == 0) return GRD_DO;
  if (strcmp(word, "declaravariaveis") == 0) return GRD_DECLARAVARIAVEIS;
  if (strcmp(word, "const"           ) == 0) return GRD_CONST;
  if (strcmp(word, "char"            ) == 0) return GRD_CHAR;
  if (strcmp(word, "chamaprocedure"  ) == 0) return GRD_CHAMAPROCEDURE;
  if (strcmp(word, "begin"           ) == 0) return GRD_BEGIN;
  if (strcmp(word, "array"           ) == 0) return GRD_ARRAY;
  if (strcmp(word, "and"             ) == 0) return GRD_AND;
  return GRD_ID;
}

enum GRDstate nierAutomata(enum GRDstate state, unsigned char byte) {
  
  const unsigned char SIMPLES[] = {
    '=', ']', '[', ';', ':', ',', '*', ')', '(', 0
  };

  const unsigned char escapeFlags[] = {
    'a', 'b', 'e', 'f', 'n', 'r', 't', 'v', '\\', '\'','\"', '0', 0
  };

  switch (state)
  {
  case GRD_ST_VAZIO: {
    //Checa se byte pertence a SIMPLES
    for (int i = 0; SIMPLES[i]; i++)
      if (byte == SIMPLES[i]) return GRD_ST_EQUAL + i;
    
    //Checa se espaco em branco ou quebra de linha
    if (byte == ' ' || byte == '\n' || byte == '\r' || byte == '\t' || byte == 0)
      return GRD_ST_VAZIO;

    //Checa por identificador
    if (('A' <= byte && byte <= 'Z') || ('a' <= byte && byte <= 'z') || byte == '_')
      return GRD_ST_ID;
    
    //Checa por comparadores e operadores
    if (byte == '+') return GRD_ST_PLUS;
    if (byte == '-') return GRD_ST_MIN;
    if (byte == '/') return GRD_ST_DIV;
    if (byte == '>') return GRD_ST_GT;
    if (byte == '<') return GRD_ST_LT;

    //Checa por numeros
    if ('0' <= byte && byte <= '9') return GRD_ST_L_INT;
    if (byte == '.') return GRD_ST_DOT;

    //Checa por inicio de string ou char
    if (byte == '\"') return GRD_ST_ERR_STR;
    if (byte == '\'') return GRD_ST_ERR_CHAR;

    //Checa por simbolos do conjunto EXTRA
    if (byte  <  32 || byte > 122  || byte == '!' || byte == '#' ||
        byte == '%' || byte == '&' || byte == '?' || byte == '@' ||
        byte == '\\' || byte == '^' || byte == '`') return GRD_ST_ERR_EX;
    
    return GRD_ST_NULL;
  }
  case GRD_ST_ID: {
    //Checa por letras, numeros ou underline
    if (('A' <= byte && byte <= 'Z') || ('a' <= byte && byte <= 'z') ||
        ('0' <= byte && byte <= '9') || byte == '_') return GRD_ST_ID;
    return GRD_ST_NULL;
  }
  case GRD_ST_PLUS: {
    if (byte == '+') return GRD_ST_ERR_PLUS;
    if (byte == '.') return GRD_ST_ERR_DOT;
    if ('0' <= byte && byte <= '9') return GRD_ST_L_INT;
    return GRD_ST_NULL;
  }
  case GRD_ST_MIN: {
    if (byte == '-') return GRD_ST_ERR_MIN;
    if (byte == '.') return GRD_ST_ERR_DOT;
    if ('0' <= byte && byte <= '9') return GRD_ST_L_INT;
    return GRD_ST_NULL;
  }
  case GRD_ST_DIV: {
    if (byte == '/') return GRD_ST_CL;
    if (byte == '*') return GRD_ST_CB1;
    return GRD_ST_NULL;
  }
  case GRD_ST_GT: {
    if (byte == '=') return GRD_ST_GTE;
    return GRD_ST_NULL;
  }
  case GRD_ST_LT: {
    if (byte == '=') return GRD_ST_LTE;
    if (byte == '>') return GRD_ST_DIF;
    return GRD_ST_NULL;
  }
  case GRD_ST_L_INT: {
    if (byte == '.') return GRD_ST_L_REAL;
    if ('0' <= byte && byte <= '9') return GRD_ST_L_INT;
    return GRD_ST_NULL;
  };
  case GRD_ST_L_REAL: {
    if ('0' <= byte && byte <= '9') return GRD_ST_L_REAL;
    return GRD_ST_NULL;
  };
  case GRD_ST_DOT: {
    if ('0' <= byte && byte <= '9') return GRD_ST_L_REAL;
    if (byte == '.') return GRD_ST_DDOT;
    return GRD_ST_NULL;
  };
  case GRD_ST_CL: {
    if (byte == '\n' || byte == 0) return GRD_ST_NULL;
    return GRD_ST_CL;
  }
  case GRD_ST_CB1: {
    if (byte == '*') return GRD_ST_CB2;
    return GRD_ST_CB1;
  }
  case GRD_ST_CB2: {
    if (byte == '*') return GRD_ST_CB2;
    if (byte == '/') return GRD_ST_CB3;
    return GRD_ST_CB1;
  }
  case GRD_ST_ERR_PLUS: {
    if (byte == '+') return GRD_ST_ERR_PLUS;
    return GRD_ST_NULL;
  }
  case GRD_ST_ERR_MIN: {
    if (byte == '-') return GRD_ST_ERR_MIN;
    return GRD_ST_NULL;
  }
  case GRD_ST_ERR_DOT: {
    if ('0' <= byte && byte <= '9') return GRD_ST_L_REAL;
    return GRD_ST_NULL;
  }
  case GRD_ST_ERR_STR: {
    if (byte == '\\') return GRD_ST_ERR_ESCS;
    if (byte == '\"') return GRD_ST_L_STR;
    if (byte != 0 && byte != '\n') return GRD_ST_ERR_STR;
    return GRD_ST_NULL;
  }
  case GRD_ST_ERR_CHAR: {
    if (byte == '\\') return GRD_ST_ERR_ESCC;
    if (byte == '\'') return GRD_ST_L_CHAR;
    if (byte != 0 && byte != '\n') return GRD_ST_ERR_CHAR;
    return GRD_ST_NULL;
  }
  case GRD_ST_ERR_ESCS: {
    for (int i = 0; escapeFlags[i]; i++)
      if (byte == escapeFlags[i]) return GRD_ST_ERR_STR;
    return GRD_ST_NULL;
  }
  case GRD_ST_ERR_ESCC: {
    for (int i = 0; escapeFlags[i]; i++)
      if (byte == escapeFlags[i]) return GRD_ST_ERR_CHAR;
    return GRD_ST_NULL;
  }
  case GRD_ST_ERR_EX: {
    //Checa por simbolos do conjunto EXTRA
    if (byte == 0) return GRD_ST_NULL;
    if (byte  <  32 || byte > 122  || byte == '!' || byte == '#' ||
        byte == '%' || byte == '&' || byte == '?' || byte == '@' ||
        byte == '\\' || byte == '^' || byte == '`') return GRD_ST_ERR_EX;
    return GRD_ST_NULL;
  }
  default: return GRD_ST_NULL;
  }
}

