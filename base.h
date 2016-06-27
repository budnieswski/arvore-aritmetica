typedef struct Arvore
{
  int dado;
  struct Arvore *dir;
  struct Arvore *esq;
} Arvore;


/**
 * Inicializa o nodo como vazio
 * @param N [Ponteiro da lista]
 */
void inicializa (Arvore **A)
{
  *A = NULL;
}


/**
 * Aloca espaco em memoria referente ao nodo
 * @return [Ponteiro de nodo]
 */
Arvore * criaArvore ()
{
  Arvore *a;
  a = (Arvore *) malloc( sizeof(Arvore) );
 
  if (!a)
  {
    printf("Erro durante a alocação\n");
    exit(0);
  }
 
  return a;
}
