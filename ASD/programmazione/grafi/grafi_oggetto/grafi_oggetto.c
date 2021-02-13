#include <stdio.h>
#include <stdlib.h>

#include "lista_interi.h"
#include "error.h"
#include "grafi_oggetto.h"


grafo_oggetti* crea_grafo(){

  grafo_oggetti* new_grafo = (grafo_oggetti*)malloc(sizeof(grafo_oggetti));

  new_grafo->numero_nodi = 0;
  new_grafo->numero_archi = 0;
  new_grafo->archi = NULL;
  new_grafo->nodi = NULL;

  return new_grafo;
}

void stampa_nodo(nodo* n) {

	printf("il nodo %d ha archi:",n->id);
	elem_archi* la = n->archi;
	while( la != NULL) {
		printf(" %d",la->info->id);
		la = la->next;
	}
	printf("\n");
}

void stampa_arco(arco* a) {

	printf("l'arco %d va da %d a %d\n",
			a->id,
			a->from->id,
			a->to->id);
}

void stampa_grafo(grafo_oggetti* g) {

	printf("Stampo un grafo con %d nodi e %d archi\n",
		    g->numero_nodi,
		    g->numero_archi);

	elem_nodi* ln = g->nodi;
	while( ln != NULL) {
		stampa_nodo(ln->info);
		ln = ln->next;
	}

	elem_archi* la = g->archi;
	while( la != NULL) {
		stampa_arco(la->info);
		la = la->next;
	}
}


nodo* aggiungi_nodo(grafo_oggetti* g, int val){

  nodo* nuovo_nodo = (nodo*)malloc(sizeof(nodo));

  nuovo_nodo->id = val;
  nuovo_nodo->color = 0;
  nuovo_nodo->archi = NULL;

  elem_nodi* new_lista = (elem_nodi*)malloc(sizeof(elem_nodi));
  new_lista->prev = NULL;
  new_lista->next = g->nodi;
  new_lista->info = nuovo_nodo;


  if(g->nodi != NULL){
    g->nodi->prev = new_lista;
  }

  g->nodi = new_lista;
  nuovo_nodo->pos = new_lista;

  g->numero_nodi++;
  return nuovo_nodo;

}

/*arco* aggiungi_arco(grafo_oggetti* g, nodo* from, nodo* to, int val){

  arco* nuovo_arco = (arco*)malloc(sizeof(arco));
  nuovo_arco->id = val;
  nuovo_arco->from = from;
  nuovo_arco->to = to;

  elem_archi* cella_arco = (elem_archi*)malloc(sizeof(elem_archi));
  cella_arco->info = nuovo_arco;
  cella_arco->prev = NULL;
  cella_arco->next = g->archi;


  if(g->archi != NULL){
    g->archi->prev = cella_arco;
  }
  nuovo_arco->pos = cella_arco;

  g->numero_archi++;
  g->archi = cella_arco;
  return nuovo_arco;
}*/

// aggiunge un arco tra i due nodi specificati //
elem_archi* inserisci_arco_in_lista(elem_archi** pla, arco* a) {

	elem_archi* e = (elem_archi*)malloc(sizeof(elem_archi));
	e->info = a;
	e->prev = NULL;
	e->next = (*pla);

	if( (*pla) != NULL ) {
		(*pla)->prev = e;
	}
	(*pla) = e;
	return e;
}

arco* aggiungi_arco(grafo_oggetti* g, nodo* from, nodo* to, int val) {

	arco* a = (arco*)malloc(sizeof(arco));

	a->id = val;

    a->from = from;
    a->to = to;

    a->pos = inserisci_arco_in_lista(&(g->archi),a);
    a->frompos = inserisci_arco_in_lista(&(from->archi),a);
    a->topos = inserisci_arco_in_lista(&(to->archi),a);

    return a;
}

void rimuovi_arco(grafo_oggetti* g, arco* e){
  g->archi = e->pos->next;
  e->frompos = NULL;
  e->topos = NULL;

  g->numero_archi--;
  free(e);

}

void dfs_oggetti(grafo_oggetti* g, nodo* n){

  elem_nodi* ln = g->nodi;
  while(ln != NULL){
    ln->info->color = 0;
    ln = ln->next;
  }
  if(g->numero_nodi > 0)
      dfs_visit_oggetti(n);
}

/*funzione che ritorna il nodo adiacente dat oun nodo ed un arco*/
nodo* opposto(nodo* n, arco* a){
  nodo* nodo_adiacente = a->from;
  if(n == nodo_adiacente)
      nodo_adiacente = a->to;

  return nodo_adiacente;

}


void dfs_visit_oggetti(nodo* n){
    n->color = 1;

    elem_archi* la = n->archi;

    while(la != NULL){
        nodo* adiacente = opposto(n, la->info);
        if(adiacente->color == 0)
            dfs_visit_oggetti(adiacente);

        la = la->next;
    }

}

/* finzione che ritorna la dimensione di una componente di un grafo*/
int dfs_size_oggetti(nodo* n){
  int conta = 1;
  n->color = 1;

  elem_archi* la = n->archi;
  while(la != NULL){
    nodo* adiacente = opposto(n, la->info);
    if(adiacente->color == 0)
      conta = conta + dfs_size_oggetti(adiacente);

    la = la->next;
  }

  return conta;
}

litem* calcolo_nodi_ogni_componente_oggetti(grafo_oggetti* g){
  litem* lista_componenti = NULL;

  elem_nodi* ln = g->nodi;
  while(ln != NULL){
    ln->info->color = 0;
    ln = ln->next;
  }
  ln = g->nodi;
  while(ln != NULL){
    if(ln->info->color == 0)
      insert_lista_interi(&lista_componenti, dfs_size_oggetti(ln->info));
    ln = ln->next;
  }
  return lista_componenti;
}


/* funzione che conte il numero di componenti connesse in un grafo ad oggetti*/
int numero_componenti_grafi_oggetti(grafo_oggetti* g){
  int componenti = 0;

  elem_nodi* ln = g->nodi;
  while(ln != NULL){
    ln->info->color = 0;
    ln = ln->next;
  }
  ln = g->nodi;
  while(ln != NULL){
    if(ln->info->color == 0){
      componenti++;
      dfs_visit_oggetti(ln->info);
    }
    ln = ln->next;
  }
  return componenti;

}
