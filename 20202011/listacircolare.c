#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct circular
{ 
	int data;
	struct circular* next;					
} circularList;

typedef circularList *lista;


lista inserisci(lista l, int val);
void stampa(lista l);


int main(){

	lista l = NULL;
	
	srand(time(NULL));
	int i;
	for(i = 0; i < 10; i++){
		l = inserisci(l, rand()%5);
		stampa(l);
	}

	return 0;
}

lista inserisci(lista l, int val){

	lista elem, cur, prec;
	int found = 0;

	if(l == NULL){
		elem = malloc(sizeof(circularList));
		elem -> data = val;
		elem -> next = elem;
		l = elem;
	}
	else{
		cur = l;
		do{
			if(cur->data == val)
				found = 1;
			prec = cur;
			cur = cur->next;	
		
		}while(found == 0 && cur!=l);

		if(found == 0){
			elem = malloc(sizeof(circularList));
                	elem -> data = val;
                	elem -> next = l;
			prec -> next = elem;
                	l = elem;
		}

	}
	return l;

}

void stampa(lista l){

	lista cur;
	printf("Lista circolare: ");
	if(l == NULL){
		printf(" vuota\n");
	}
	else{
		cur = l;
                do{
                       	printf(" %d", cur->data);
                   
                        cur = cur->next;

                }while(cur!=l);
		printf("\n");
	}


}
