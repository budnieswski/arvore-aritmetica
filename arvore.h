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


Arvore * parseArvore(char expression[]) {
  Arvore *a = criaArvore();
  char dado;
  int tamanho = (strlen(expression)-1);

  // Ultimo elemento    
  dado = expression[ tamanho ];

  // Retirando 1 -- pop
  expression[ tamanho ] = 0;

  a->dado = dado;
    
  switch(dado) {
    case '+': case '-':
    case '*': case '/':
    case '^':
      a->dir = parseArvore( expression );
      a->esq = parseArvore( expression );
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
