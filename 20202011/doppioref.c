#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct nodo{
   int dato;
   struct nodo *pre;
   struct nodo *suc;
};

typedef struct nodo elem;
typedef elem *lista;

void stampa(lista l);
lista inserisci(lista l, int val);

int main(){

	lista l = NULL;
	int i;

	srand(time(NULL));
	for(i = 0; i<10; i++){
		l = inserisci(l,rand()%100);
	}

	stampa(l);
	return 0;
}

void stampa(lista l){

	if(l==NULL)
		printf("La lista a vuota");
	else
	{
		while(l!= NULL){
			printf("val: %d", l->dato);

			if(l->pre == NULL)
				printf("(pre = NULL, ");
			else
				printf("(pre = %d, ", l->pre->dato);
			if(l->suc == NULL)
                                printf(" suc = NULL), ");
                        else
                                printf(" suc = %d)\n", l->suc->dato);

			l=l->suc;
		}
	}

}



lista inserisci(lista l, int val){

	elem *toInsert, *cur, *prec;

	prec = NULL;
	cur = l;

	while(cur != NULL && val > cur->dato){
		prec = cur;
		cur = cur->suc;
	}

	if(cur == NULL || val != cur->dato){

		toInsert = malloc(sizeof(elem));	
		toInsert->dato = val;
		toInsert->suc = cur;
		toInsert->pre = prec;
		if(cur != NULL){
		//Se sono qua e' perche' non sono alla fine 
			cur->pre = toInsert;
		}
		if(prec != NULL){
		//Se sono qua e' perche' la lista e' riempita
		//e sono tra due valori e non sono all'inizio
			prec->suc = toInsert;
		}
		else{
		//Se sono qua la lista era vuota
			l = toInsert;
		}
	}
	return l;

}





