#ifndef GRAFI_OGGETTO_H
#define GRAFI_OGGETTO_H

#include "lista_interi.h"

typedef struct elem_lista_nodi elem_nodi;   // forward declaration
typedef struct elem_lista_archi elem_archi; // forward declaration

typedef struct nodo_struct {
	elem_nodi* pos;  /* posizione nodo nella lista del grafo */
	elem_archi* archi;   // lista archi incidenti
  int color;
  int id;
} nodo;

typedef struct arco_struct {
	elem_archi* pos;  // pos. arco lista grafo
	nodo* from;
	nodo* to;
	elem_archi* frompos;  // pos. arco nodo from
	elem_archi* topos;       // pos. arco nodo to
  int id;
} arco;

typedef struct elem_lista_nodi {
	struct elem_lista_nodi* prev;
	struct elem_lista_nodi* next;
	nodo* info;
} elem_nodi;   // elemento di una lista di nodi

typedef struct elem_lista_archi {
	struct elem_lista_archi* prev;
	struct elem_lista_archi* next;
	arco* info;
} elem_archi;  // elemento di una lista di archi

typedef struct {
	int numero_nodi;
	int numero_archi;
	elem_archi* archi;  // lista degli archi
	elem_nodi* nodi;    // lista dei nodi
} grafo_oggetti;

void stampa_grafo(grafo_oggetti* g);

grafo_oggetti* crea_grafo();

nodo* aggiungi_nodo(grafo_oggetti* g, int val);

arco* aggiungi_arco(grafo_oggetti* g, nodo* from, nodo* to, int val);

void rimuovi_arco(grafo_oggetti* g, arco* e);

void rimuovi_nodo(grafo_oggetti* g, nodo* n);//ancora da implementare

void dfs_oggetti(grafo_oggetti* g, nodo* n);

void dfs_visit_oggetti(nodo* n);

nodo* opposto(nodo* n, arco* a);

int dfs_size_oggetti(nodo* n);

int numero_componenti_grafi_oggetti(grafo_oggetti* g);

litem* calcolo_nodi_ogni_componente_oggetti(grafo_oggetti* g);

#endif
