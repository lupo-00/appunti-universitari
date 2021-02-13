#ifndef GRAFI_LISTE_H
#define GRAFI_LISTE_H

#include "lista_interi.h"

typedef struct nome_lista{

  int numero_nodi;
  lista_interi* lista;

}grafo_lista;

grafo_lista* nuovo_grafo_lista(int numero_nodi);

void stampa_grafo_lista(grafo_lista* g);

void inserisci_arco_lista(grafo_lista* g, int i, int j);

void aggiungi_arco(grafo_lista* g, int u, int v);

int grado_uscita(grafo_lista* g, int i);

int grafo_semplice(grafo_lista* g);

void DFS_parent(grafo_lista* g, int u, int* parent, int* color);

int* albero_ricoprente(grafo_lista* g);

void inserisci_arco(grafo_lista* g, int i, int j);

void dfs_liste(grafo_lista* g, int* color, int val);

void dfs_liste_color(grafo_lista* g, int* color, int val);

int numero_componenti_connesse(grafo_lista* g);

void dfs(grafo_lista* g);

void dfs_v(grafo_lista* g, int v);

void dfs_visit(grafo_lista* g, int i, int* color);

int componenti_connesse_liste(grafo_lista* g);

void bfs_liste_color(grafo_lista* g, int v,int* color);

void dfs_mark(grafo_lista* g, int i, int* color, int mark);

int dfs_lista_size(grafo_lista* g, int* color, int i);

litem* calcolo_nodi_ogni_componente(grafo_lista* g);

#endif
