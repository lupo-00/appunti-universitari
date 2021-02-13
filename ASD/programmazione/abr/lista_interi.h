#ifndef _LISTA_INTERI_H
#define _LISTA_INTERI_H

typedef struct litem {

	int info;
	struct litem* next;
	struct litem* prev;

} litem;

typedef litem* lista_interi;

/*
	struct litem* mia_lista = NULL;  // già lo potevo fare
    litem*        mia_lista = NULL;  // ho creato una lista vuota
    lista_interi  mia_lista = NULL;  // da adesso in poi posso fare cosi'
*/

void insert_lista_interi(lista_interi* pl, int val);

int delete_first_lista_interi(lista_interi* pl);

litem* search_lista_interi(lista_interi l, int val);

void delete_lista_interi(lista_interi* pl, litem* pi);

void print_lista_interi(lista_interi l);

void insert_lista_interi_ordinata(lista_interi* pl, int val);

lista_interi merge_di_liste_interi_ordinate(lista_interi l1, lista_interi l2);

int lunghezza_lista_interi(lista_interi l);

void dealloca_lista_interi(lista_interi l);


#endif