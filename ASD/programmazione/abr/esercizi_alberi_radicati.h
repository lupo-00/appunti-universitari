#ifndef _ESERCIZI_ALBERI_RADICATI_H
#define _ESERCIZI_ALBERI_RADICATI_H

#include "lista_interi.h"

typedef struct nodo{

    struct nodo* sx;
    struct nodo* dx;
    struct nodo* parent;
    int info;

} nodo;



typedef nodo* albero;

nodo* new_tree();

int is_empty(albero t);

int root(albero t);

nodo* root_id(albero t);

nodo* left(albero t, nodo* n);

nodo* right(albero t, nodo* n);

int info(albero t, albero n);

int two_children(albero t, nodo* n);

//---
void add_root(albero *pa, int z);

nodo* add_left(albero t, int z);

nodo* add_right(albero t, int z);

int only_left(albero t);

int only_right(albero t);

//---

int cerca_pre(albero t, int n);

int cerca_post(albero t, int n);

int cerca_simm(albero t, int n);

int conta_nodi_post(albero t);

int cammino_ric(albero t);

int cammino_ite(albero t);

int altezza(albero t);

int somma_info_nodi(albero t);

float average_info(albero t);

int completo(albero t);

int completo_h(albero t);

void dealloca(albero t);

void DeallocaABR(albero t);

nodo* cerca_id_nodo(albero t, int z);

void pota(albero t, int z);

void pota_prof(albero t, int prof);

int valore_nonno(albero t);

int due_figli(albero t);

int quattro_nipoti(albero t);

litem* cammino(albero t, int n);

int parentela(albero t, nodo* n1, nodo* n2);

#endif
