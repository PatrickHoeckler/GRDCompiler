#ifndef GRDAUTOMATA_H
#define GRDAUTOMATA_H

//Definindo os codigos de tokens da linguagem
enum GRDterminal {
  //Palavras reservadas
  //equivalente ao conjunto PALAVRA no documento do automato
  GRD_WRITE = 0,
  GRD_WHILE,
  GRD_UNTIL,
  GRD_TO,
  GRD_THEN,
  GRD_STRING,
  GRD_REPEAT,
  GRD_REAL,
  GRD_READ,
  GRD_PROGRAM,
  GRD_PROCEDURE,
  GRD_OR,
  GRD_OF,
  GRD_LITERAL, //SIMBOLO NAO UTILIZADO NA GRAMATICA
  GRD_INTEGER,
  GRD_IF,
  GRD_FOR = 18,
  GRD_END,
  GRD_ELSE,
  GRD_DO,
  GRD_DECLARAVARIAVEIS,
  GRD_CONST,
  GRD_CHAR,
  GRD_CHAMAPROCEDURE,
  GRD_BEGIN,
  GRD_ARRAY,
  GRD_AND,

  //Simbolos equivalentes ao conjunto SIMPLES no documento do automato
  GRD_EQUAL     = 31,    // =
  GRD_RBRACKET  = 40,    // ]
  GRD_LBRACKET  = 41,    // [
  GRD_SEMICOLON = 42,    // ;
  GRD_COLON     = 43,    // :
  GRD_COMMA     = 47,    // ,
  GRD_STAR      = 48,    // *
  GRD_DOLLAR    = 51,    // $
  GRD_RPARENTHESIS = 49, // )
  GRD_LPARENTHESIS = 50, // (

  //Comparadores
  GRD_GT  = 30, // >
  GRD_GTE = 29, // >=
  GRD_LT  = 34, // <
  GRD_LTE = 33, // <=
  GRD_DIF = 32, // <>

  //Operadores aritmeticos - multiplicacao esta incluso em GRD_ST_SIMPLES
  GRD_PLUS = 35, // +
  GRD_MIN  = 52, // -
  GRD_DIV  = 44, // /

  //Literais
  GRD_L_REAL = 36, // literal real
  GRD_L_INT  = 37, // literal inteiro
  GRD_L_STR  = 38, // literal string
  GRD_L_CHAR = 39, // literal char

  //Comentarios
  GRD_CL = -2, //comentario de linha //
  GRD_CB = -1, //comentario de bloco /**/

  //Outros
  GRD_EMPTY = 17, // î
  GRD_ID    = 16, // identificador
  GRD_DOT   = 46, // .
  GRD_DDOT  = 45, // ..
  GRD_ERR_PLUS   =  -4, // erro: repetidos +
  GRD_ERR_MINUS  =  -5, // erro: repetidos -
  GRD_ERR_DOT    =  -6, // erro: +. ou -.
  GRD_ERR_EX   =  -7, // erro: caracteres invalidos
  GRD_ERR_STR  =  -8, // erro: string nao fechada
  GRD_ERR_CHAR =  -9, // erro: char nao fechado
  GRD_ERR_ESCS = -10, // erro: sequencia de escape invalida em string
  GRD_ERR_ESCC = -11, // erro: sequencia de escape invalida em char
  GRD_NULL  = -3  //token inexistente
};

//Definindo os estados do automato
enum GRDstate {
  GRD_ST_NULL = 0, //estado inexistente

  //Palavras reservadas - equivalente ao conjunto PALAVRA no documento do automato
  GRD_ST_WRITE,
  GRD_ST_WHILE,
  GRD_ST_UNTIL,
  GRD_ST_TO,
  GRD_ST_THEN,
  GRD_ST_STRING,
  GRD_ST_REPEAT,
  GRD_ST_REAL,
  GRD_ST_READ,
  GRD_ST_PROGRAM,
  GRD_ST_PROCEDURE,
  GRD_ST_OR,
  GRD_ST_OF,
  GRD_ST_INTEGER,
  GRD_ST_IF,
  GRD_ST_FOR,
  GRD_ST_END,
  GRD_ST_ELSE,
  GRD_ST_DO,
  GRD_ST_DECLARAVARIAVEIS,
  GRD_ST_CONST,
  GRD_ST_CHAR,
  GRD_ST_CHAMAPROCEDURE,
  GRD_ST_BEGIN,
  GRD_ST_ARRAY,
  GRD_ST_AND,

  //Simbolos equivalentes ao conjunto SIMPLES no documento do automato
  GRD_ST_EQUAL,
  GRD_ST_RBRACKET,
  GRD_ST_LBRACKET,
  GRD_ST_SEMICOLON,
  GRD_ST_COLON,
  GRD_ST_COMMA,
  GRD_ST_STAR,
  GRD_ST_RPARENTHESIS,
  GRD_ST_LPARENTHESIS,
  GRD_ST_DOLLAR,

  //Comparadores
  GRD_ST_GT,
  GRD_ST_LT,
  GRD_ST_GTE,
  GRD_ST_LTE,
  GRD_ST_DIF,

  //Operadores aritmeticos - multiplicacao esta incluso em GRD_ST_SIMPLES
  GRD_ST_PLUS,
  GRD_ST_MIN,
  GRD_ST_DIV,

  //Literais
  GRD_ST_L_INT,
  GRD_ST_L_REAL,
  GRD_ST_L_STR,
  GRD_ST_L_CHAR,

  //Comentarios
  GRD_ST_CL,
  GRD_ST_CB1,
  GRD_ST_CB2,
  GRD_ST_CB3,

  //Outros
  GRD_ST_VAZIO, //estado inicial
  GRD_ST_ID,    //identificador
  GRD_ST_DOT,
  GRD_ST_DDOT,

  //Erros lexicos
  GRD_ST_ERR_EX,
  GRD_ST_ERR_PLUS,
  GRD_ST_ERR_MIN,
  GRD_ST_ERR_DOT,
  GRD_ST_ERR_STR,
  GRD_ST_ERR_CHAR,
  GRD_ST_ERR_ESCS,
  GRD_ST_ERR_ESCC
};

//converte um valor GRDcode que é representado por um int
//para uma string correspondente.
char* GRDterminal2string(enum GRDterminal x);

//retorna o token correspondente ao estado dado
//se nao é estado final, retorna GRD_ERROR
//se o estado é GRD_ST_NULL, retorn GRD_NULL
enum GRDcode GRDstate2terminal(enum GRDstate x);

//Retorna o token correspondente à palavra passada como argumento
//se a palavra nao ser palavra reservada, retorna GRD_ID
enum GRDterminal reservedWord(char *word);

//funcao que implementa o automato - recebe um estado e um byte de entrada
//retorna o novo estado que o automato assume aplicando a funcao
//de transicao em funcao do estado e byte passados.
//se nao existir transicao, retorna GRD_ST_NULL
enum GRDstate nierAutomata(enum GRDstate state, unsigned char byte);

#endif