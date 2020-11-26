#include <stdio.h>
#include <stdlib.h>
struct nodo{
  int n;
  //struct nodo *pre;
  struct nodo *suc;
};
typedef struct nodo *lista;
lista Inserisci(lista l,int a);
void Stampa(lista l);
int main(){
  lista l=NULL;
  l=Inserisci(l,6);
  l=Inserisci(l,3);
  l=Inserisci(l,5);
  l=Inserisci(l,4);
  Stampa(l);
  //printf("%d",l->n);
}
lista Inserisci(lista l,int a){
  if(l==NULL || l->n>a){
    struct nodo *temp=malloc(sizeof(struct nodo));
    temp->n=a;
    temp->suc=l;
    return temp;
  }
  else{
      l->suc=Inserisci(l->suc,a);
  }
  return l;
}
void Stampa(lista l){
  if(l==NULL){
    printf("FINE\n");
  }
  else{
    printf("%d ->",l->n);
    Stampa(l->suc);
  }
}
