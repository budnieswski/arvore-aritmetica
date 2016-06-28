#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base.h"
#include "pilha.h"


int main(int argc, char **argv)
{
  // Arvore *arv;
  // inicializa(&arv);

  // int dado;
  // printf("\nInforme um número positivo ou zero para parar:");
  // scanf("%d", &dado);
  // while(dado != 0)
  // {
  //   arv = insere_no_arvore(arv, arv, dado);
  //   printf("\nInforme um número positivo ou zero para parar:");
  //   scanf("%d", &dado);
  // }

  // imprime_inordem(arv);


  // Expressao
  char expressao[100];
  fgets(expressao, sizeof(expressao), stdin);

  Pilha resultado = NPR(expressao);

  imprimirPilha(&resultado);

  return 0;
}