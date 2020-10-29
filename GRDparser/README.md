# GRDParser

This is the parser part of the GRDCompiler. The parser in a compiler is responsible for the syntax analysis of the code, it takes as input the tokens from the lexer and checks if they are ordered in a correct manner. For example, the following line of C code:
```C
int value = 5;
```

This line can be seen as being composed of the five tokens in order: `<INT> <ID> <EQUAL> <NUMBER> <SEMICOLON>`. The C parser would look at this line and conclude that it's valid C code because it is in the right order. Consider now this example:
```C
int value 5 = ;
```

The tokens for this line are: `<INT> <ID> <NUMBER> <EQUAL> <SEMICOLON>`. This is invalid code, the C parser would see these tokens and alert of an error because the tokens are out of order.

The order of the tokens is defined by the language grammar, this is what the parser will follow. For the grammar followed by the GRDParser you can check [this](../docs/grammar.xlsx) document for all it's rules and the parse table for the tokens.

## Running the program
As for the case with the GRDLexer, you can compile this program from a Visual Studio command prompt by running:
```
nmake
```

You can call the parser by running:
```
GRDParser <filename>
```

In the folder examples there are sample files with both correct and incorrect code, you can run these examples to undertand how the parser works. It will search for erros and alert in case any was found, it will also suggest possible fixes. If no error was found the parser will return 0 indicating that the code is syntactically correct.

Running the parser with the `ex_bad2.grd` file you will get the following result, you can see with detail how the parse tree was constructed and the description for all the errors that were found.
```
> GRDparser examples\ex_bad2.grd

 LINHA |          ACAO           |   SIMBOLO ATUAL  | VALOR DO SIMBOLO |  PILHA
 1     | producao: 0             | program          | 9                | $ <PROGRAMA>
 1     | casou: program          | program          | 9                | $ . <BLOCO> ; id program
 1     | casou: id               | id               | ex_bad2          | $ . <BLOCO> ; id
 3     |          ERRO T         | procedure        | 10               | $ . <BLOCO> ;
 3     | producao: 1             | procedure        | 10               | $ . <BLOCO>
 3     | producao: 22            | procedure        | 10               | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC>
 3     | casou: procedure        | procedure        | 10               | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; <CORPO> <DCLVAR> <DEFPAR> id procedure
 3     | casou: id               | id               | proc1            | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; <CORPO> <DCLVAR> <DEFPAR> id
 3     | producao: 24            | (                | 50               | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; <CORPO> <DCLVAR> <DEFPAR>
 3     | casou: (                | (                | 50               | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; <CORPO> <DCLVAR> ) <LDVAR> ; <TIPO> : <LID> (
 3     | producao: 8             | id               | int1             | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; <CORPO> <DCLVAR> ) <LDVAR> ; <TIPO> : <LID>
 3     | casou: id               | id               | int1             | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; <CORPO> <DCLVAR> ) <LDVAR> ; <TIPO> : <REPIDENT> id
 3     | producao: 9             | ,                | 47               | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; <CORPO> <DCLVAR> ) <LDVAR> ; <TIPO> : <REPIDENT>
 3     | casou: ,                | ,                | 47               | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; <CORPO> <DCLVAR> ) <LDVAR> ; <TIPO> : <REPIDENT> id ,
 3     | casou: id               | id               | int2             | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; <CORPO> <DCLVAR> ) <LDVAR> ; <TIPO> : <REPIDENT> id
 3     | producao: 10            | :                | 43               | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; <CORPO> <DCLVAR> ) <LDVAR> ; <TIPO> : <REPIDENT>
 3     | casou: :                | :                | 43               | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; <CORPO> <DCLVAR> ) <LDVAR> ; <TIPO> :
 3     | producao: 18            | integer          | 14               | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; <CORPO> <DCLVAR> ) <LDVAR> ; <TIPO>
 3     | casou: integer          | integer          | 14               | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; <CORPO> <DCLVAR> ) <LDVAR> ; integer
 3     | casou: ;                | ;                | 42               | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; <CORPO> <DCLVAR> ) <LDVAR> ;
 3     | producao: 11            | id               | ch1              | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; <CORPO> <DCLVAR> ) <LDVAR>
 3     | producao: 8             | id               | ch1              | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; <CORPO> <DCLVAR> ) <LDVAR> ; <TIPO> : <LID>
 3     | casou: id               | id               | ch1              | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; <CORPO> <DCLVAR> ) <LDVAR> ; <TIPO> : <REPIDENT> id
 3     | producao: 10            | :                | 43               | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; <CORPO> <DCLVAR> ) <LDVAR> ; <TIPO> : <REPIDENT>
 3     | casou: :                | :                | 43               | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; <CORPO> <DCLVAR> ) <LDVAR> ; <TIPO> :
 3     | producao: 19            | char             | 24               | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; <CORPO> <DCLVAR> ) <LDVAR> ; <TIPO>
 3     | casou: char             | char             | 24               | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; <CORPO> <DCLVAR> ) <LDVAR> ; char
 3     | casou: ;                | ;                | 42               | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; <CORPO> <DCLVAR> ) <LDVAR> ;
 3     | producao: 12            | )                | 49               | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; <CORPO> <DCLVAR> ) <LDVAR>
 3     | casou: )                | )                | 49               | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; <CORPO> <DCLVAR> )
 5     |          ERRO NT        | id               | int1             | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; <CORPO> <DCLVAR>
 5     |          ERRO NT        | id               | int1             | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; <CORPO>
 5     |          ERRO T         | id               | int1             | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; end <REPCOMANDO> ; <COMANDO> begin
 5     | producao: 72            | id               | int1             | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; end <REPCOMANDO> ; <COMANDO>
 5     | producao: 41            | id               | int1             | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; end <REPCOMANDO> ; <EXPRESSAO>
 5     | producao: 42            | id               | int1             | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; end <REPCOMANDO> ; <REPEXPSIMP> <REPEXP> <TERMO>
 5     | producao: 44            | id               | int1             | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; end <REPCOMANDO> ; <REPEXPSIMP> <REPEXP> <REPTERMO> <FATOR>
 5     | casou: id               | id               | int1             | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; end <REPCOMANDO> ; <REPEXPSIMP> <REPEXP> <REPTERMO> id
 5     | producao: 66            | equal            | 31               | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; end <REPCOMANDO> ; <REPEXPSIMP> <REPEXP> <REPTERMO>
 5     | producao: 62            | equal            | 31               | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; end <REPCOMANDO> ; <REPEXPSIMP> <REPEXP>
 5     | producao: 49            | equal            | 31               | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; end <REPCOMANDO> ; <REPEXPSIMP>
 5     | casou: equal            | equal            | 31               | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; end <REPCOMANDO> ; <EXPSIMP> equal
 5     | producao: 58            | id               | int2             | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; end <REPCOMANDO> ; <EXPSIMP>
 5     | producao: 42            | id               | int2             | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; end <REPCOMANDO> ; <REPEXP> <TERMO>
 5     | producao: 44            | id               | int2             | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; end <REPCOMANDO> ; <REPEXP> <REPTERMO> <FATOR>
 5     | casou: id               | id               | int2             | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; end <REPCOMANDO> ; <REPEXP> <REPTERMO> id
 5     | producao: 63            | *                | 48               | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; end <REPCOMANDO> ; <REPEXP> <REPTERMO>
 5     | casou: *                | *                | 48               | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; end <REPCOMANDO> ; <REPEXP> <REPTERMO> <FATOR> *
 5     | producao: 44            | id               | ch1              | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; end <REPCOMANDO> ; <REPEXP> <REPTERMO> <FATOR>
 5     | casou: id               | id               | ch1              | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; end <REPCOMANDO> ; <REPEXP> <REPTERMO> id
 5     | producao: 66            | ;                | 42               | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; end <REPCOMANDO> ; <REPEXP> <REPTERMO>
 5     | producao: 62            | ;                | 42               | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; end <REPCOMANDO> ; <REPEXP>
 5     | casou: ;                | ;                | 42               | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; end <REPCOMANDO> ;
 6     | producao: 27            | write            | 0                | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; end <REPCOMANDO>
 6     | producao: 34            | write            | 0                | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; end <REPCOMANDO> ; <COMANDO>
 6     | casou: write            | write            | 0                | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; end <REPCOMANDO> ; ) <REPITEM> <EXPRESSAO> ( write
 6     | casou: (                | (                | 50               | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; end <REPCOMANDO> ; ) <REPITEM> <EXPRESSAO> (
 6     | producao: 41            | id               | int1             | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; end <REPCOMANDO> ; ) <REPITEM> <EXPRESSAO>
 6     | producao: 42            | id               | int1             | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; end <REPCOMANDO> ; ) <REPITEM> <REPEXPSIMP> <REPEXP> <TERMO>
 6     | producao: 44            | id               | int1             | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; end <REPCOMANDO> ; ) <REPITEM> <REPEXPSIMP> <REPEXP> <REPTERMO> <FATOR>
 6     | casou: id               | id               | int1             | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; end <REPCOMANDO> ; ) <REPITEM> <REPEXPSIMP> <REPEXP> <REPTERMO> id
 6     | producao: 66            | )                | 49               | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; end <REPCOMANDO> ; ) <REPITEM> <REPEXPSIMP> <REPEXP> <REPTERMO>
 6     | producao: 62            | )                | 49               | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; end <REPCOMANDO> ; ) <REPITEM> <REPEXPSIMP> <REPEXP>
 6     | producao: 55            | )                | 49               | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; end <REPCOMANDO> ; ) <REPITEM> <REPEXPSIMP>
 6     | producao: 40            | )                | 49               | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; end <REPCOMANDO> ; ) <REPITEM>
 6     | casou: )                | )                | 49               | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; end <REPCOMANDO> ; )
 6     | casou: ;                | ;                | 42               | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; end <REPCOMANDO> ;
 7     | producao: 27            | ;                | 42               | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; end <REPCOMANDO>
 7     | producao: 36            | ;                | 42               | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; end <REPCOMANDO> ; <COMANDO>
 7     | casou: ;                | ;                | 42               | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; end <REPCOMANDO> ;
 9     |          ERRO NT        | declaravariaveis | 22               | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; end <REPCOMANDO>
 9     |          ERRO T         | declaravariaveis | 22               | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ; end
 9     |          ERRO T         | declaravariaveis | 22               | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC> ;
 9     | producao: 23            | declaravariaveis | 22               | $ . <CORPO> <DCLVAR> <DCLCONST> <DCLPROC>
 9     | producao: 3             | declaravariaveis | 22               | $ . <CORPO> <DCLVAR> <DCLCONST>
 9     | producao: 6             | declaravariaveis | 22               | $ . <CORPO> <DCLVAR>
 9     | casou: declaravariaveis | declaravariaveis | 22               | $ . <CORPO> <LDVAR> ; <TIPO> : <LID> declaravariaveis
 10    | producao: 8             | id               | x                | $ . <CORPO> <LDVAR> ; <TIPO> : <LID>
 10    | casou: id               | id               | x                | $ . <CORPO> <LDVAR> ; <TIPO> : <REPIDENT> id
 10    | producao: 10            | :                | 43               | $ . <CORPO> <LDVAR> ; <TIPO> : <REPIDENT>
 10    | casou: :                | :                | 43               | $ . <CORPO> <LDVAR> ; <TIPO> :
 10    | producao: 18            | integer          | 14               | $ . <CORPO> <LDVAR> ; <TIPO>
 10    | casou: integer          | integer          | 14               | $ . <CORPO> <LDVAR> ; integer
 10    | casou: ;                | ;                | 42               | $ . <CORPO> <LDVAR> ;
 11    | producao: 11            | id               | s                | $ . <CORPO> <LDVAR>
 11    | producao: 8             | id               | s                | $ . <CORPO> <LDVAR> ; <TIPO> : <LID>
 11    | casou: id               | id               | s                | $ . <CORPO> <LDVAR> ; <TIPO> : <REPIDENT> id
 11    |          ERRO NT        | string           | 5                | $ . <CORPO> <LDVAR> ; <TIPO> : <REPIDENT>
 11    |          ERRO T         | string           | 5                | $ . <CORPO> <LDVAR> ; <TIPO> :
 11    | producao: 20            | string           | 5                | $ . <CORPO> <LDVAR> ; <TIPO>
 11    | casou: string           | string           | 5                | $ . <CORPO> <LDVAR> ; string
 11    | casou: ;                | ;                | 42               | $ . <CORPO> <LDVAR> ;
 13    | producao: 12            | begin            | 26               | $ . <CORPO> <LDVAR>
 13    | producao: 26            | begin            | 26               | $ . <CORPO>
 13    | casou: begin            | begin            | 26               | $ . end <REPCOMANDO> ; <COMANDO> begin
 14    | producao: 72            | id               | x                | $ . end <REPCOMANDO> ; <COMANDO>
 14    | producao: 41            | id               | x                | $ . end <REPCOMANDO> ; <EXPRESSAO>
 14    | producao: 42            | id               | x                | $ . end <REPCOMANDO> ; <REPEXPSIMP> <REPEXP> <TERMO>
 14    | producao: 44            | id               | x                | $ . end <REPCOMANDO> ; <REPEXPSIMP> <REPEXP> <REPTERMO> <FATOR>
 14    | casou: id               | id               | x                | $ . end <REPCOMANDO> ; <REPEXPSIMP> <REPEXP> <REPTERMO> id
 14    | producao: 66            | equal            | 31               | $ . end <REPCOMANDO> ; <REPEXPSIMP> <REPEXP> <REPTERMO>
 14    | producao: 62            | equal            | 31               | $ . end <REPCOMANDO> ; <REPEXPSIMP> <REPEXP>
 14    | producao: 49            | equal            | 31               | $ . end <REPCOMANDO> ; <REPEXPSIMP>
 14    | casou: equal            | equal            | 31               | $ . end <REPCOMANDO> ; <EXPSIMP> equal
 14    | producao: 58            | id               | x                | $ . end <REPCOMANDO> ; <EXPSIMP>
 14    | producao: 42            | id               | x                | $ . end <REPCOMANDO> ; <REPEXP> <TERMO>
 14    | producao: 44            | id               | x                | $ . end <REPCOMANDO> ; <REPEXP> <REPTERMO> <FATOR>
 14    | casou: id               | id               | x                | $ . end <REPCOMANDO> ; <REPEXP> <REPTERMO> id
 14    | producao: 66            | -                | 52               | $ . end <REPCOMANDO> ; <REPEXP> <REPTERMO>
 14    | producao: 60            | -                | 52               | $ . end <REPCOMANDO> ; <REPEXP>
 14    | casou: -                | -                | 52               | $ . end <REPCOMANDO> ; <REPEXP> <TERMO> -
 14    | producao: 42            | INT              | +2               | $ . end <REPCOMANDO> ; <REPEXP> <TERMO>
 14    | producao: 43            | INT              | +2               | $ . end <REPCOMANDO> ; <REPEXP> <REPTERMO> <FATOR>
 14    | casou: INT              | INT              | +2               | $ . end <REPCOMANDO> ; <REPEXP> <REPTERMO> INT 
 14    | producao: 66            | ;                | 42               | $ . end <REPCOMANDO> ; <REPEXP> <REPTERMO>
 14    | producao: 62            | ;                | 42               | $ . end <REPCOMANDO> ; <REPEXP>
 14    | casou: ;                | ;                | 42               | $ . end <REPCOMANDO> ;
 15    | producao: 27            | id               | x                | $ . end <REPCOMANDO>
 15    | producao: 72            | id               | x                | $ . end <REPCOMANDO> ; <COMANDO>
 15    | producao: 41            | id               | x                | $ . end <REPCOMANDO> ; <EXPRESSAO>
 15    | producao: 42            | id               | x                | $ . end <REPCOMANDO> ; <REPEXPSIMP> <REPEXP> <TERMO>
 15    | producao: 44            | id               | x                | $ . end <REPCOMANDO> ; <REPEXPSIMP> <REPEXP> <REPTERMO> <FATOR>
 15    | casou: id               | id               | x                | $ . end <REPCOMANDO> ; <REPEXPSIMP> <REPEXP> <REPTERMO> id
 15    | producao: 66            | equal            | 31               | $ . end <REPCOMANDO> ; <REPEXPSIMP> <REPEXP> <REPTERMO>
 15    | producao: 62            | equal            | 31               | $ . end <REPCOMANDO> ; <REPEXPSIMP> <REPEXP>
 15    | producao: 49            | equal            | 31               | $ . end <REPCOMANDO> ; <REPEXPSIMP>
 15    | casou: equal            | equal            | 31               | $ . end <REPCOMANDO> ; <EXPSIMP> equal
 15    | producao: 58            | INT              | 4                | $ . end <REPCOMANDO> ; <EXPSIMP>
 15    | producao: 42            | INT              | 4                | $ . end <REPCOMANDO> ; <REPEXP> <TERMO>
 15    | producao: 43            | INT              | 4                | $ . end <REPCOMANDO> ; <REPEXP> <REPTERMO> <FATOR>
 15    | casou: INT              | INT              | 4                | $ . end <REPCOMANDO> ; <REPEXP> <REPTERMO> INT 
 15    |          ERRO NT        | INT              | 6                | $ . end <REPCOMANDO> ; <REPEXP> <REPTERMO>
 15    |          ERRO NT        | INT              | 6                | $ . end <REPCOMANDO> ; <REPEXP>
 15    |          ERRO T         | INT              | 6                | $ . end <REPCOMANDO> ;
 15    | producao: 27            | INT              | 6                | $ . end <REPCOMANDO>
 15    | producao: 72            | INT              | 6                | $ . end <REPCOMANDO> ; <COMANDO>
 15    | producao: 41            | INT              | 6                | $ . end <REPCOMANDO> ; <EXPRESSAO>
 15    | producao: 42            | INT              | 6                | $ . end <REPCOMANDO> ; <REPEXPSIMP> <REPEXP> <TERMO>
 15    | producao: 43            | INT              | 6                | $ . end <REPCOMANDO> ; <REPEXPSIMP> <REPEXP> <REPTERMO> <FATOR>
 15    | casou: INT              | INT              | 6                | $ . end <REPCOMANDO> ; <REPEXPSIMP> <REPEXP> <REPTERMO> INT
 15    | producao: 66            | ;                | 42               | $ . end <REPCOMANDO> ; <REPEXPSIMP> <REPEXP> <REPTERMO>
 15    | producao: 62            | ;                | 42               | $ . end <REPCOMANDO> ; <REPEXPSIMP> <REPEXP>
 15    | producao: 55            | ;                | 42               | $ . end <REPCOMANDO> ; <REPEXPSIMP>
 15    | casou: ;                | ;                | 42               | $ . end <REPCOMANDO> ;
 17    | producao: 27            | repeat           | 6                | $ . end <REPCOMANDO>
 17    | producao: 31            | repeat           | 6                | $ . end <REPCOMANDO> ; <COMANDO>
 17    | casou: repeat           | repeat           | 6                | $ . end <REPCOMANDO> ; ] <EXPRESSAO> [ until <REPCOMANDO> ; <COMANDO> repeat
 18    | producao: 72            | id               | y                | $ . end <REPCOMANDO> ; ] <EXPRESSAO> [ until <REPCOMANDO> ; <COMANDO>
 18    | producao: 41            | id               | y                | $ . end <REPCOMANDO> ; ] <EXPRESSAO> [ until <REPCOMANDO> ; <EXPRESSAO>
 18    | producao: 42            | id               | y                | $ . end <REPCOMANDO> ; ] <EXPRESSAO> [ until <REPCOMANDO> ; <REPEXPSIMP> <REPEXP> <TERMO>
 18    | producao: 44            | id               | y                | $ . end <REPCOMANDO> ; ] <EXPRESSAO> [ until <REPCOMANDO> ; <REPEXPSIMP> <REPEXP> <REPTERMO> <FATOR>
 18    | casou: id               | id               | y                | $ . end <REPCOMANDO> ; ] <EXPRESSAO> [ until <REPCOMANDO> ; <REPEXPSIMP> <REPEXP> <REPTERMO> id
 18    | producao: 66            | equal            | 31               | $ . end <REPCOMANDO> ; ] <EXPRESSAO> [ until <REPCOMANDO> ; <REPEXPSIMP> <REPEXP> <REPTERMO>
 18    | producao: 62            | equal            | 31               | $ . end <REPCOMANDO> ; ] <EXPRESSAO> [ until <REPCOMANDO> ; <REPEXPSIMP> <REPEXP>
 18    | producao: 49            | equal            | 31               | $ . end <REPCOMANDO> ; ] <EXPRESSAO> [ until <REPCOMANDO> ; <REPEXPSIMP>
 18    | casou: equal            | equal            | 31               | $ . end <REPCOMANDO> ; ] <EXPRESSAO> [ until <REPCOMANDO> ; <EXPSIMP> equal
 18    | producao: 58            | id               | x                | $ . end <REPCOMANDO> ; ] <EXPRESSAO> [ until <REPCOMANDO> ; <EXPSIMP>
 18    | producao: 42            | id               | x                | $ . end <REPCOMANDO> ; ] <EXPRESSAO> [ until <REPCOMANDO> ; <REPEXP> <TERMO>
 18    | producao: 44            | id               | x                | $ . end <REPCOMANDO> ; ] <EXPRESSAO> [ until <REPCOMANDO> ; <REPEXP> <REPTERMO> <FATOR>
 18    | casou: id               | id               | x                | $ . end <REPCOMANDO> ; ] <EXPRESSAO> [ until <REPCOMANDO> ; <REPEXP> <REPTERMO> id
 18    | producao: 63            | *                | 48               | $ . end <REPCOMANDO> ; ] <EXPRESSAO> [ until <REPCOMANDO> ; <REPEXP> <REPTERMO>
 18    | casou: *                | *                | 48               | $ . end <REPCOMANDO> ; ] <EXPRESSAO> [ until <REPCOMANDO> ; <REPEXP> <REPTERMO> <FATOR> *
 18    | producao: 43            | INT              | 2                | $ . end <REPCOMANDO> ; ] <EXPRESSAO> [ until <REPCOMANDO> ; <REPEXP> <REPTERMO> <FATOR>
 18    | casou: INT              | INT              | 2                | $ . end <REPCOMANDO> ; ] <EXPRESSAO> [ until <REPCOMANDO> ; <REPEXP> <REPTERMO> INT
 19    |          ERRO NT        | until            | 2                | $ . end <REPCOMANDO> ; ] <EXPRESSAO> [ until <REPCOMANDO> ; <REPEXP> <REPTERMO>
 19    |          ERRO NT        | until            | 2                | $ . end <REPCOMANDO> ; ] <EXPRESSAO> [ until <REPCOMANDO> ; <REPEXP>
 19    |          ERRO T         | until            | 2                | $ . end <REPCOMANDO> ; ] <EXPRESSAO> [ until <REPCOMANDO> ;
 19    | producao: 28            | until            | 2                | $ . end <REPCOMANDO> ; ] <EXPRESSAO> [ until <REPCOMANDO>
 19    | casou: until            | until            | 2                | $ . end <REPCOMANDO> ; ] <EXPRESSAO> [ until
 19    | casou: [                | [                | 41               | $ . end <REPCOMANDO> ; ] <EXPRESSAO> [
 19    | producao: 41            | id               | x                | $ . end <REPCOMANDO> ; ] <EXPRESSAO>
 19    | producao: 42            | id               | x                | $ . end <REPCOMANDO> ; ] <REPEXPSIMP> <REPEXP> <TERMO>
 19    | producao: 44            | id               | x                | $ . end <REPCOMANDO> ; ] <REPEXPSIMP> <REPEXP> <REPTERMO> <FATOR>
 19    | casou: id               | id               | x                | $ . end <REPCOMANDO> ; ] <REPEXPSIMP> <REPEXP> <REPTERMO> id
 19    | producao: 66            | equal            | 31               | $ . end <REPCOMANDO> ; ] <REPEXPSIMP> <REPEXP> <REPTERMO>
 19    | producao: 62            | equal            | 31               | $ . end <REPCOMANDO> ; ] <REPEXPSIMP> <REPEXP> 
 19    | producao: 49            | equal            | 31               | $ . end <REPCOMANDO> ; ] <REPEXPSIMP>
 19    | casou: equal            | equal            | 31               | $ . end <REPCOMANDO> ; ] <EXPSIMP> equal
 19    | producao: 58            | INT              | 255              | $ . end <REPCOMANDO> ; ] <EXPSIMP>
 19    | producao: 42            | INT              | 255              | $ . end <REPCOMANDO> ; ] <REPEXP> <TERMO>
 19    | producao: 43            | INT              | 255              | $ . end <REPCOMANDO> ; ] <REPEXP> <REPTERMO> <FATOR>
 19    | casou: INT              | INT              | 255              | $ . end <REPCOMANDO> ; ] <REPEXP> <REPTERMO> INT
 19    | producao: 66            | ]                | 40               | $ . end <REPCOMANDO> ; ] <REPEXP> <REPTERMO>
 19    | producao: 62            | ]                | 40               | $ . end <REPCOMANDO> ; ] <REPEXP>
 19    | casou: ]                | ]                | 40               | $ . end <REPCOMANDO> ; ]
 21    |          ERRO T         | read             | 8                | $ . end <REPCOMANDO> ;
 21    | producao: 27            | read             | 8                | $ . end <REPCOMANDO>
 21    | producao: 32            | read             | 8                | $ . end <REPCOMANDO> ; <COMANDO>
 21    | casou: read             | read             | 8                | $ . end <REPCOMANDO> ; ) <VARIAVEL> ( read
 21    | casou: (                | (                | 50               | $ . end <REPCOMANDO> ; ) <VARIAVEL> (
 21    | producao: 69            | id               | y                | $ . end <REPCOMANDO> ; ) <VARIAVEL>
 21    | casou: id               | id               | y                | $ . end <REPCOMANDO> ; ) <REPVARIALVEL> id
 21    | producao: 71            | )                | 49               | $ . end <REPCOMANDO> ; ) <REPVARIALVEL>
 21    | casou: )                | )                | 49               | $ . end <REPCOMANDO> ; )
 21    | casou: ;                | ;                | 42               | $ . end <REPCOMANDO> ;
 23    |          ERRO NT        | .                | 46               | $ . end <REPCOMANDO>
 23    |          ERRO T         | .                | 46               | $ . end
 23    | casou: .                | .                | 46               | $ .

ERRO: na linha 15. Sequencia invalida de caracteres: `++`
ERRO: na linha 3. Esperava `;`. Encontrou `procedure`
ERRO: na linha 5. Esperava `declaravariaveis`, ou `begin`. Encontrou `int1`
ERRO: na linha 9. Esperava `write`, `while`, `until`, `repeat`, `read`, `if`, `id`, `for`, `end`, `chamaprocedure`, `REAL`, `INT`, `STR`, `CHAR`, `;`, ou `(`. Encontrou `declaravariaveis`
ERRO: na linha 11. Esperava `:`, `,`, ou `)`. Encontrou `string`
ERRO: na linha 19. Esperava `or`, `and`, `>=`, `>`, `equal`, `<>`, `<=`, `<`, `+`, `]`, `;`, `/`, `,`, `*`, `)`, ou `-`. Encontrou `until`
ERRO: na linha 21. Esperava `;`. Encontrou `read`
ERRO: na linha 23. Esperava `write`, `while`, `until`, `repeat`, `read`, `if`, `id`, `for`, `end`, `chamaprocedure`, `REAL`, `INT`, `STR`, `CHAR`, `;`, ou `(`. Encontrou `.`

Retornou 14. Encontrou erros no codigo
```