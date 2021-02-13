#include <stdlib.h>
#include <stdio.h>
#include "lista_interi.h"
#include "error.h"


void insert_lista_interi(lista_interi* pl, int val) {

  // pl è un puntatore alla lista, cioè un puntatore ad un puntatore a litem
  // (*pl) è proprio la lista esterna (come se fosse passata per riferimento)

 	litem* nuovo_elem = (litem*)malloc(sizeof(litem));
 	nuovo_elem->info = val;
 	nuovo_elem->next = (*pl);   // potrebbe essere NULL (se la lista era vuota)
 	nuovo_elem->prev = NULL;

 	if( (*pl) != NULL ) {  // c'era un elemento il lista
 		(*pl)->prev = nuovo_elem;
 	}
 	(*pl) = nuovo_elem;

}

int delete_first_lista_interi(lista_interi* pl) {

	if( (*pl) == NULL ) error("delete_first_lista_interi() su lista vuota");

	int output = (*pl)->info;
	lista_interi punt_primo_elem = (*pl);
	if( (*pl)->next != NULL ) {  // se c'era un elemento successivo (il 2°)
		(*pl)->next->prev = NULL;
	}
	(*pl) = (*pl)->next;
	free(punt_primo_elem);
	return output;
}

litem* search_lista_interi(lista_interi l, int val) {

	while (l != NULL) {
		if (l->info == val)
			return l;
		l = l-> next;
	}
	return NULL;
}

void delete_lista_interi(lista_interi* pl, litem* pi) {

	if( (*pl) == NULL ) error("delete_lista_interi() con lista NULL");
	if( pi == NULL ) error("delete_lista_interi() con puntatore NULL");

	/* AGGIORNAMENTO A MONTE */

	if( pi->prev != NULL ) {  // non sono il primo elemento
		pi->prev->next = pi->next;  // mi sono "saltato"
	} else {                  // sono il primo elemento
		(*pl) = pi->next;     // potrebbe essere NULL
	}

	/* AGGIORNAMENTO A VALLE */

	if( pi->next != NULL ) {   // non sono l'ultimo elemento
		pi->next->prev = pi->prev;
	}

	free(pi);
}

//inserimento in testa
void print_lista_interi(lista_interi l) {

	printf("lista = ");
	while( l != NULL) {
		printf("%d ", l->info);
		l = l->next;
	}
	printf("\n");
}

/* inserisce l'elemento val nella lista (che si suppone ordinata)
   in modo tale che la lista rimanga ordinata. */

void insert_lista_interi_ordinata(lista_interi* pl, int val) {

	/* caso della lista vuota (e' un semplice inserimento) */

    if( (*pl) == NULL ) {   // lista vuota
    	insert_lista_interi(pl, val);
    	return;
    }

	/* caso in cui c'e' almeno un elemento e val deve essere inserito
	   prima di questo elemento */

    if( (*pl)->info >= val ) {  // devo inserire val come primo elemento
    	insert_lista_interi(pl, val);
    	return;
    }

	/* caso generico (dall'eventuale secondo elemento in poi) in cui
	   confronto val con gli elementi della lista tenendomi un puntatore
	   all'elemento precedente (cosi' riesco anche ad inserire in coda) */

	litem* x = (*pl);  // comincio dal primo elemento della lista
	while( x->next != NULL ) {
		if( x->next->info >= val ) {  // inserisco tra x e x->next
			litem* nuovo = (litem*)malloc(sizeof(litem));
			nuovo->info = val;
			nuovo->prev = x;
			nuovo->next = x->next;
			x->next = nuovo;
			nuovo->next->prev = nuovo;
			return;
		}
		x = x->next;
	}
	// adesso x punta all'ultimo elemento della lista
	// inserimento in coda alla lista
	//
	litem* nuovo = (litem*)malloc(sizeof(litem));
	nuovo->info = val;
	nuovo->prev = x;
	nuovo->next = NULL;
	x->next = nuovo;
	return;
}


lista_interi merge_di_liste_interi_ordinate(lista_interi l1, lista_interi l2) {

	lista_interi l3 = NULL;   // lista vuota da riportare in output
	litem* i1 = l1;   // iteratore per la prima lista
	litem* i2 = l2;   // iteratore per la seconda lista
	litem* i3 = NULL; // puntatore all'ultimo elemento della treza lista

	// inserisco il primo elemento in l3 in maniera da avere un puntatore i3
	// all'ultimo elemento di l3 per fare i successivi inserimenti in coda

    if( (i1 == NULL) && (i2 == NULL) ) return l3;  // due liste vuote

    if( i1 == NULL ) {  // non e' NULL l2 e posso inserire il primo elemento da l2
		insert_lista_interi(&l3,i2->info);
		i2 = i2->next;
    }

    if( i2 == NULL ) {  // non e' NULL l1 e posso inserire il primo elemento da l1
		insert_lista_interi(&l3,i1->info);
		i1 = i1->next;
    }

	if( i1->info <= i2->info ) {
		insert_lista_interi(&l3,i1->info);
		i1 = i1->next;
	} else {
		insert_lista_interi(&l3,i2->info);
		i2 = i2->next;
	}
	i3 = l3;  // c'è solo un elemento: i3 punta all'ultimo elemento di l3


	while( (i1 != NULL) && (i2 != NULL) ) {
		if( i1->info <= i2->info ) {  // prendi l'elemento di l1 puntato da i1
			i3->next = (litem*)malloc(sizeof(litem));
			i3->next->prev = i3;
			i3->next->info = i1->info;
			i3->next->next = NULL;
			i3 = i3->next;

			i1 = i1->next;
		} else { // prendi l'elemento di l2 puntato da i2
			i3->next = (litem*)malloc(sizeof(litem));
			i3->next->prev = i3;
			i3->next->info = i2->info;
			i3->next->next = NULL;
			i3 = i3->next;

			i2 = i2->next;
		}

	}

	while( i1 != NULL ) {
		// prendi l'elemento i1 da l1
		i3->next = (litem*)malloc(sizeof(litem));
		i3->next->prev = i3;
		i3->next->info = i1->info;
		i3->next->next = NULL;
		i3 = i3->next;
		i1 = i1->next;
	}

	while( i2 != NULL ) {
		// prendi l'elemento i2 da l2
		i3->next = (litem*)malloc(sizeof(litem));
		i3->next->prev = i3;
		i3->next->info = i2->info;
		i3->next->next = NULL;
		i3 = i3->next;
		i2 = i2->next;
	}

	return l3;
}

int lunghezza_lista_interi(lista_interi l) {

	int output = 0;
	while (l != NULL) {
		output++;
		l = l->next;
	}
	return output;
}

void dealloca_lista_interi(lista_interi l) {

	if ( l == NULL ) return;

	dealloca_lista_interi(l->next);

	free(l);
}
