#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "GRDlexer\GRDlexer.h"
#include "GRDparser\GRDparser.h"
#include "GRDerror.h"

int main(int argc, char** argv) {
   if (argc != 2) {
      if (argc < 2) printf("ERRO: nenhum arquivo de entrada\n");
      else printf("ERRO: mais de um arquivo de entrada\n");
      return -1;
   }

   struct GRDtoken *tokens = NULL;
   unsigned int nTokens;
   int r = GRDlexer(argv[1], &tokens, &nTokens);
   if (r != 0) {
      if (r == ENOMEM) printf("ERRO: falhou em alocar memoria para a operacao\n");
      else printf("ERRO: erro abrindo arquivo de entrada\n");
      return -1;
   }

   //*--
   struct GRDerror_parser *error_parser;
   unsigned int nerror_parser;
   r = GRDparser(tokens, nTokens, &error_parser, &nerror_parser);
   if (r == ENOMEM) {
      printf("\n\nERRO: falhou em alocar memoria para a operacao\n");
      for (unsigned int i = 0; i < nTokens; i++) free(tokens[i].value);
      free(tokens); free(error_parser);
   }

   //Imprime os erros lexicos e sintaticos na tela
   printf("\n");
   reportLexErrors(tokens, nTokens);
   reportParserErrors(error_parser, nerror_parser);
   if (r == EFAULT) printf("\nRetornou %d. Encontrou erros no codigo\n", r);
   else if (r == 0) printf("\n\nRetornou 0. Codigo esta correto\n");
   //--*/

   //libera memoria
   for (unsigned int i = 0; i < nTokens; i++) free(tokens[i].value);
   free(tokens); free(error_parser);

   printf("\n");
   return 0;
}