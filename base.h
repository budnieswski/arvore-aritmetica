typedef struct Arvore
{
  char dado;
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


Arvore *insere_no_arvore(Arvore *pai, Arvore *filho, char dado) {
  if(filho == NULL)
  {
    filho = criaArvore();          
    filho->dir = NULL;          
    filho->esq = NULL;
    filho->dado = dado;

    if(pai == NULL) // inserção do primeiro nodo                
      return filho;          

    if(dado < pai->dado) //verifica se insere no direita ou esquerda da sub-árvore              
      pai->esq = filho;          
    else              
      pai->dir = filho;          

    return filho;
  }

  if(dado < filho->dado)            
    insere_no_arvore(filho, filho->esq, dado);     
  else            
    insere_no_arvore(filho, filho->dir, dado);     

  return filho;
}


void imprime_inordem(Arvore *arv)
{
  if(!arv)
    return;

  imprime_inordem(arv->esq);
  printf("\n%c", arv->dado);
  imprime_inordem(arv->dir);
}