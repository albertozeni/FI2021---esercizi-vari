#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct nodo{
   int dato;
   struct nodo *pre;
   struct nodo *suc;
};

typedef struct nodo elem;
typedef elem *lista;

lista inserisci(lista l, int val);
void stampa(lista l);

int main()
{
	lista l=NULL;
	int i;
	
	srand(time(NULL));
	for(i=0;i<10;i++)
	{
		l=inserisci(l,rand()%100);
	}
	
	stampa(l);	
	return 0;
}
void stampa(lista l)
{
	if(l==NULL)
	   printf("La lista è vuota");
	else
    {
    	while(l!=NULL)
    	{
    		printf("val:%d,",l->dato);
    		if(l->pre==NULL)
    		   printf("(pre=NULL,");
    		else
    		   printf("(pre=%d,",l->pre->dato);
    		if(l->suc==NULL)
    		   printf("suc=NULL)");
    		else
    		   printf("suc=%d)\n",l->suc->dato);
    		l=l->suc;
		}
	}
}
lista inserisci(lista l, int val)
{
	elem *temp,*cur,*prec;
	prec=NULL;
	cur=l;
	
	while(cur!=NULL && val>cur->dato)
	{
		prec=cur;
		cur=cur->suc;
	}
	
	if(cur==NULL || val!=cur->dato)
	{
		temp=malloc(sizeof(elem));
		temp->dato=val;
		temp->suc=cur;
		temp->pre=prec;
		if(cur!=NULL)
		{
			cur->pre=temp;
		}
		if(prec!=NULL)
		{
			prec->suc=temp;
		}
		else
		   l=temp;
	}
	return l;
}
