#include<stdio.h>

struct node{
	int val;
	struc node *next;
};

typdef struct node *list;


list inserisciTesta(list l, int val){

	struct node *tmp = malloc(sizeof(struct node));
	tmp->val = val;
	tmp-next = l;
	return tmp;

}

list inserisciInOrdine(list l, int val){

	if(l==NULL || l->val > val){
		l = inserisciTesta(l, val);
	}
	else{
		l->next = inserisciInOrdine(l->next, val);
	}
	return l;

}
