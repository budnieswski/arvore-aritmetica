typedef struct Lista
{
  Pilha expressao;
  struct Lista *prox;
} Lista;

Lista * criaLista ()
{
  Lista *l;
  l = (Lista *) malloc( sizeof(Lista) );
 
  if (!l)
  {
    printf("Erro durante a alocação\n");
    exit(0);
  }
 
  return l;
}


void addLista (Lista **l, Pilha p)
{
  Lista *n;
 
  n = criaLista();
  n->expressao = p;
  n->prox = *l;
 
  *l = n;
}


int printLista (Lista *l)
{
  Lista *aux;
 
  if (l == NULL) {
    printf("Lista vazia\n");
    return 0;
  }

  for (aux=l; aux != NULL; aux = aux->prox)
    printf("%s\n", aux->expressao.item);
}