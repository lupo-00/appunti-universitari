#ifndef _ESERCIZI_ALBERI_RADICATI_H
#define _ESERCIZI_ALBERI_RADICATI_H

#include "lista_interi.h"
typedef struct nodo{

    struct nodo* parent;
    struct nodo* sx;
    struct nodo* dx;
    int info;

} nodo;

typedef nodo* albero;

nodo* new_tree();

int is_empty(albero t);

int root(albero t);

nodo* root_id(albero t);

nodo* sx(albero t, nodo* n);

nodo* dx(albero t, nodo* n);

int info(albero t, albero n);

int two_children(albero t, nodo* n);

//---
void add_root(albero* pa, int z);

nodo* add_sx(nodo* n, int z);

nodo* add_dx(nodo* n, int z);

int only_sx(albero t);

int only_dx(albero t);

//---

int cerca_pre(albero t, int n);

int cerca_post(albero t, int n);

int cerca_simm(albero t, int n);

int conta_nodi_post(albero t);

int cammino_ric(albero t);

int cammino_ite(albero t);

int altezza(albero t);

int somma_info_nodo(albero t);

float average_info(albero t);

int completo(albero t);

int completo_h(albero t);

void dealloca(albero t);

void pota(albero t, int z);

nodo* cerca_id_nodo(albero t, int z);

void pota_prof(albero t, int prof);

int valore_nonno(albero t);

int due_figli(albero t);

int quattro_nipoti(albero t);

litem* cammino(albero t, int n);

nodo* cerca_post_p(albero t, int n);

int conta_elementi_lista(lista_interi lista);

int parentela(albero t, nodo* n1, nodo* n2);

#endif
