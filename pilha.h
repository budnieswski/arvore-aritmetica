#define MAX 100

typedef struct Pilha
{
  char item[MAX];
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

void imprimirPilha(Pilha *p){
    int i;
    for(i=0;i<p->topo;i++)
        printf("%c",p->item[i]);
}


int prioridade(char operador)
{
  switch(operador)
  {
    case '^':
      return 4;
    break;
    
    case '*':
    case '/':
      return 3;
    break;

    case '+':
    case '-':
      return 2;
    break;

    case '(':
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
  for (i = 0; i < (strlen(expressao)-1); ++i)
  {
    switch(expressao[i])
    {
      case '+':
      case '-':
      case '*':
      case '/':
      case '^':
        while(!empty(&P) && (prioridade(top(&P)) >= prioridade(expressao[i])) ) {
            push(&S, pop(&P));
        }
        push(&P, expressao[i]);
      break;
      
      case '(':
        push(&P, expressao[i]);
      break;

      case ')':
        while(top(&P)!='(') {
          push(&S, pop(&P));
        }
        pop(&P);
      break;

      default:
        push(&S, expressao[i]);
      break;
    }

    // Debug
    // printf("\n Pilha P: ");
    // imprimirPilha(&P); // Sinais
    // printf("\n Pilha S: ");
    // imprimirPilha(&S);
    // printf("\n");
  }

  // Operadores finais
  while( !empty(&P) )
    push(&S, pop(&P));

  return S;
}