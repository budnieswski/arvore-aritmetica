#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"
#include "arvore.h"
#include "lista.h"


int main(int argc, char **argv)
{
  // int c = ('2' - '0') + ('3' - '0');
  // printf("%d\n", c);
  
  Lista *lista = NULL;
  int continuar = 1;


  /*
   * Lendo as expressoes, transformando em Polonesa e armazenando na lista */
  do {
    printf("Insira a expressao ou S para sair: \n");

    // Recebendo a expressao
    char expressao[100];
    fgets(expressao, sizeof(expressao), stdin);

    // Inserindo na lista de expressoes
    if (strlen(expressao) >= 3 && expressao[0] != 'S') {
      Pilha resultado = NPR(expressao);
      addLista(&lista, resultado);
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

  for (aux=lista; aux != NULL; aux = aux->prox) {
    Arvore *arv = NULL;
    arv = parseArvore( aux->expressao.item );

    printf("\nPre: ");
    arvore_imprime_pre(arv);

    printf("\nPos: ");
    arvore_imprime_pos(arv);

    printf("\nIn: ");
    arvore_imprime_in(arv);
    printf("\n---------------------------------------\n\n");
  }

  return 0;
}