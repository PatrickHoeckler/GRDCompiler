#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "GRDlexer.h"

int main(int argc, char** argv) {
   struct GRDtoken *tokens = NULL;
   unsigned int nTokens, line = 0;
   int r = GRDlexer(argv[1], &tokens, &nTokens);
   if (r != 0) {
      if (r == ENOMEM) printf("ERRO: falhou em alocar memoria para a operacao\n");
      else printf("ERRO: erro abrindo arquivo de entrada\n");
      return -1;
   }

   //Imprime todos os tokens e as linhas que estao presentes
   printf("\n\n=================PROGRAMA EM TOKENS====================\n\n\n");
   printf("Linha| Tokens");
   for (int i = 0; i < nTokens; i++) {
      for (;line < tokens[i].line;)
         printf("\n %-3d | ", ++line);
      printf("%s ", GRDcode2string(tokens[i].code));
   }
   
   //Imprime os detalhes de todos os tokens
   printf("\n\n\n=================DETALHES DOS TOKENS====================\n\n\n");
   printf(" Codigo Token |    Nome Token     | Linha | Lexema\n");
   for (int i = 0; i < nTokens; i++) {
      printf("      %-7d | %-17s | %-5d | %s\n", tokens[i].code, GRDcode2string(tokens[i].code), tokens[i].line, tokens[i].value);
   }

   //libera memoria
   for (int i = 0; i < nTokens; i++) free(tokens[i].value);
   free(tokens);
   return 0;
}