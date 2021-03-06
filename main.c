#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define LOG '@'
#define SQRT '#'

#define MAIS '+'
#define MENOS '-'
#define MULT '*'
#define DIV '/'
#define EXPO '^'
#define PARENTESES_ABRE '('
#define PARENTESES_FECHA ')'

#include "pilha.h"
#include "arvore.h"
#include "lista.h"


int main(int argc, char **argv)
{
  Lista *lista = NULL;
  int continuar = 1;

  system("cls");
  /*
   * Lendo as expressoes, transformando em Polonesa e armazenando na lista */
  printf("Insira a expressao ou S para sair\n");
  do {
    printf("Expressao: ");

    // Recebendo a expressao
    char expressao[100];
    fgets(expressao, sizeof(expressao), stdin);

    // Inserindo na lista de expressoes
    if (strlen(expressao) >= 3 && expressao[0] != 'S') {
      Pilha resultado = NPR(expressao);
      addLista(&lista, resultado);
      // printPilha(resultado); printf("\n");
    } else {
      continuar = 0;
    }

  } while (continuar);


  /*
   * Processando a listagem da arvore */
  Lista *aux;
 
  if (lista == NULL) {
    printf("Lista vazia\n");
    return 0;
  }

  printf("\n\n\n");
  for (aux=lista; aux != NULL; aux = aux->prox) {
    Arvore *arv = NULL;
    arv = parseArvore( &aux->expressao );

    printf("\nCalculo da expressao: %d", arvore_calculo(arv));

    printf("\nPre: [");
    arvore_imprime_pre(arv);
    printf("]");

    printf("\nPos: [");
    arvore_imprime_pos(arv);
    printf("]");

    printf("\nIn: [");
    arvore_imprime_in(arv);
    printf("]");
    printf("\n---------------------------------------\n\n");
  }

  return 0;
}