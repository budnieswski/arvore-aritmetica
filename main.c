#include <stdio.h>
#include <stdlib.h>
#include "base.h"


int main(int argc, char **argv)
{
  Arvore *arvore;
  inicializa(&arvore);

  char expressao[100];
  fgets(expressao, sizeof(expressao), stdin);

  int i;
  for (i = 0; (expressao[i] != '\n'); ++i)
  {
    printf("%c > %d\n", expressao[i], expressao[i]);
  }
  

  return 0;
}