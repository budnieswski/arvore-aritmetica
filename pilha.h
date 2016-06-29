#define MAX 100

typedef struct Pilha
{
  int item[MAX];
  int topo;
} Pilha;

int full(Pilha *p){
    if(p->topo==(MAX-1))
        return 1;
    else
        return 0;
}

int empty(Pilha *p){
    if(p->topo)
        return 0;
    else
        return 1;
}

int push(Pilha *p, char n){
    if(full(p))
        return 0;
    p->item[(p->topo)]=n;
    p->topo++;
    return p->topo;
}


int top(Pilha *p){
    if(empty(p))
        return 0;
      
    return p->item[(p->topo-1)];
}

int pop(Pilha *p){
    if(empty(p))
        return 0;
    p->item[p->topo]=0;
    p->topo--;
    return p->item[p->topo];
}

void printPilha(Pilha p){
    int i;
    for(i=0;i<p.topo;i++)
        printf("%c",p.item[i]);
        // printf("%c:%d - ",p.item[i],p.item[i]);
}


int prioridade(char operador)
{
  switch(operador)
  {
    case EXPO:
    case LOG:
    case SQRT:
      return 4;
    break;
    
    case MULT: // *
    case DIV: // /
      return 3;
    break;

    case MAIS: // +
    case MENOS: // -
      return 2;
    break;

    case PARENTESES_ABRE: // (
      return 1;
    break;
  }
}


Pilha NPR(char expressao[])
{
  Pilha P;
  Pilha S;

  S.topo = 0;
  P.topo = 0;

  int i;
  int tamanho = strlen(expressao)-1;
  for (i = 0; i < tamanho; i++)
  {
    int exp = expressao[i];

    // printf("Tamanho: %d\n", tamanho);

    // if (exp=='l' && expressao[i+1]=='o' && expressao[i+2]=='g')
    // {
    //   exp = LOG;
    //   i+=3;
    //   tamanho -= 3;
    // }

    // printf("%c\n", exp);
    switch(exp)
    {
      case MAIS: // +
      case MENOS: // -
      case MULT: // *
      case DIV: // /
      case EXPO: // ^
      // case LOG:
      // case SQRT:
        while(!empty(&P) && (prioridade(top(&P)) >= prioridade(exp)) ) {
            push(&S, pop(&P));
        }
        push(&P, exp);
      break;
      
      case PARENTESES_ABRE: // (
        push(&P, exp);
      break;

      case PARENTESES_FECHA: // )
        while(top(&P)!=PARENTESES_ABRE) {
          push(&S, pop(&P));
        }
        pop(&P);
      break;

      default:
        push(&S, exp);
      break;
    }

    // Debug
    // printf("\n Pilha P: ");
    // printPilha(P); // Sinais
    // printf("\n Pilha S: ");
    // printPilha(S);
    // printf("\n");
  }

  // Operadores finais
  while( !empty(&P) )
    push(&S, pop(&P));

  return S;
}