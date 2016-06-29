typedef struct Arvore {
  char dado;
  struct Arvore *esq, *dir;
} Arvore;


Arvore * criaArvore() {
  Arvore *nova;
  nova = (Arvore *) malloc(sizeof(Arvore));

  if (!nova) {
    printf("Erro na alocacao");
    exit(0);
  }

  return nova;
}


/**
 * Recebe a expressao POLONESA
 * Insere do ultimo ao primeiro
 */
Arvore * parseArvore(Pilha *p) {
  
  Arvore *a = criaArvore();
  int dado;
  int tamanho = (sizeof(p->item)-2);

  // Ultimo elemento    
  dado = pop(p);

  a->dado = dado;

  switch(dado) {
    case MAIS: case MENOS:
    case MULT: case DIV:
    case EXPO:
    case LOG: case SQRT:
      a->dir = parseArvore( p );
      a->esq = parseArvore( p );
    break;
    default:
      a->esq = NULL;
      a->dir = NULL;
    break;
  }
    
  return a;
}


void arvore_imprime_pre (Arvore *arv) {
  if (!arv) return;
  
  printf("%c", arv->dado);
  arvore_imprime_pre( arv->esq );
  arvore_imprime_pre( arv->dir );
}


void arvore_imprime_pos (Arvore *arv) {
  if (!arv) return;
  
  arvore_imprime_pos( arv->esq );
  arvore_imprime_pos( arv->dir );
  printf("%c", arv->dado);
}


void arvore_imprime_in (Arvore *arv) {
  if (!arv) return;
  
  arvore_imprime_in( arv->esq );
  printf("%c", arv->dado);
  arvore_imprime_in( arv->dir );
}


int arvore_calculo (Arvore *arv) {
  if (!arv) return 0;

  int result_esq = 0;
  int result_dir = 0;
  int result = 0;
  
  result_esq = arvore_calculo( arv->esq );
  result_dir = arvore_calculo( arv->dir );

  switch (arv->dado) {
    case MAIS:
      result = (result_esq - '0') + (result_dir - '0');

      printf("SOMANDO: %c+%c / RETORNO: %d\n", result_esq, result_dir, result);
      return result;
    break;
    case MENOS:
      result = (result_esq - '0') - (result_dir - '0');
      return result;
    break;
    case MULT:
      result = (result_esq - '0') * (result_dir - '0');
      
      printf("MULTIPLICANDO: %c*%d / RETORNO: %d\n", result_esq, result_dir, result);
      return result;
    break;
    case DIV:
      result = (result_esq - '0') / (result_dir - '0');
      printf("DIVIDINDO: %c/%c / RETORNO: %d\n", result_esq, result_dir, result);
      return result;
    break;
    default: return (int) arv->dado; break;
  }
}
