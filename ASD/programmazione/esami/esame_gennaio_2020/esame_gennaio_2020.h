#ifndef ESAME_GENNAIO_2020_H
#define ESAME_GENNAIO_2020_H

//FORWARD DECLARATIO
typedef struct elem_lista_nodi elem_nodi;
typedef struct elem_lista_archi elem_archi;

typedef struct nodo_struct {
 elem_nodi* pos; /* posizione nodo nella lista del grafo */
 elem_archi* archi; // lista archi incidenti
 int color;
} nodo;

typedef struct arco_struct {
 elem_archi* pos; // pos. arco lista grafo
 nodo* from;
 nodo* to;
 elem_archi* frompos; // pos. arco nodo from
 elem_archi* topos; // pos. arco nodo to
} arco;

typedef struct elem_lista_nodi {
 struct elem_lista_nodi* prev;
 struct elem_lista_nodi* next;
 nodo* info;
} elem_nodi; // elemento di una lista di nodi

typedef struct elem_lista_archi {
 struct elem_lista_archi* prev;
 struct elem_lista_archi* next;
 arco* info;
} elem_archi; // elemento di una lista di archi

typedef struct {
 int numero_nodi;
 int numero_archi;
 elem_archi* archi; // lista degli archi
 elem_nodi* nodi; // lista dei nodi
} grafo;

/* struttura per l’albero di grado arbitrario */
typedef struct nodo_albero_struct {
 struct nodo_albero_struct* left;
 struct nodo_albero_struct* right;
 int info;
} nodo_albero;

typedef nodo_albero* albero;

int verifica(albero t, grafo* g);
#endif
