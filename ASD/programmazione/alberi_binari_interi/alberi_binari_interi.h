#ifndef ALBERI_BINARI_INTERI_H
#define ALBERI_BINARI_INTERI_H

typedef struct nodo{

  struct nodo* parent;
  struct nodo* left;
  struct nodo* right;
  int info;
}nodo;

typedef nodo* albero;

void aggiungi_radice(albero* pa, int val);

nodo* aggiungi_figlio_sinistro(nodo* n, int val);

nodo* aggiungi_figlio_destro(nodo* n, int val);

int only_left(albero a);

int only_right_ric(albero a);

int only_left_ric(albero a);

int cerca_nodo_preordine(albero t, int n);

int cerca_nodo_postordine(albero t, int n);

int cerca_nodo_simmetrica(albero t, int n);

int conta_nodi_postordine(albero t);

int cammino_ric(albero t);

int cammino_iter(albero t);

int altezza(albero t);



#endif
