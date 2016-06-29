#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"
#include "arvore.h"


int main(int argc, char **argv)
{
  // char expression[] = {'A','B','C','+','*','D','/'}; // para testes

  // int c = ('2' - '0') + ('3' - '0');
  // printf("%d\n", c);

  Arvore *arv = NULL;
  char expressao[100];
  
  // Recebendo a expressao
  fgets(expressao, sizeof(expressao), stdin);

  Pilha resultado = NPR(expressao);
  // imprimirPilha(&resultado); // debug da pilha


  arv = parseArvore(resultado.item);
  
  printf("Pre: ");
  arvore_imprime_pre(arv);

  printf("\nPos: ");
  arvore_imprime_pos(arv);

  printf("\nIn: ");
  arvore_imprime_in(arv);
  printf("\n");

  return 0;
}