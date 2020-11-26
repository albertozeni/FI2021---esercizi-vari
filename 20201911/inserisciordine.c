#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct node{
        int n;
        struct node *next;
};

typedef struct node *list;

list inserisciTesta(list l, int val);
void printLista(list l);
list inserisciInOrdine(list l, int val);

int main(){

	list l = NULL;
	int i;	
	int valore;
	
	srand(time(NULL));


	for(i = 0; i < 5; i++){
		valore = rand()%50;
		printf("Inserisco: %d\n", valore);
		l = inserisciInOrdine(l, valore);


	}

	printLista(l);	
	return 0;
}

void printLista(list l){
	
	if(l==NULL)
		printf("FINE\n");
	else{
		printf("%d -> ", l->n);
		printLista(l->next);
	}	
}


list inserisciTesta(list l, int val){

        struct node *tmp = malloc(sizeof(struct node)); 
        tmp->n = val;
        tmp->next = l;
        return tmp; 

}

list inserisciInOrdine(list l, int val){


	struct node *corrente, *prec;
	
	corrente = l;
	prec = NULL;
	while(corrente != NULL && corrente->n < val){
		prec = corrente;
		corrente = corrente->next;
	}

	if(prec == NULL){
		l = inserisciTesta(corrente, val);
	}
	else{
		prec->next = inserisciTesta(corrente, val);
	}

	return l;

}
