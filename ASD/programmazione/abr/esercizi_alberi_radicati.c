#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "esercizi_alberi_radicati.h"
#include "error.h"

nodo* new_tree(){

    nodo* tree = NULL;

    return tree;
}

int is_empty(albero t){

  if(t == NULL)
    return 1;

  return 0;
}

int root(albero t){
    return t->info;
}


nodo* root_id(albero t){
    return t;
}

/*ritorna il nodo sinistro del nodo n*/
nodo* left(nodo* t, nodo* n){

    if(t == NULL)
        return 0;

    if(t->info == n->info)
        return n->sx;

    left(t->sx,n);
    left(t->dx,n);

    return 0;
}

/*ritorna il nodo destro del nodo n*/
nodo* right(nodo* t, nodo* n){

    if(t == NULL)
        return 0;

    if(t->info == n->info)
        return n->dx;

    right(t->sx,n);
    right(t->dx,n);

    return 0;
}

int info(nodo* t, nodo* n){

  if(t == NULL)
      return 0;

    info(t->sx,n);
    info(t->dx,n);

  if(t->info == n->info)
      return n->info;

  return 0;
}

int two_children(nodo* t, nodo* n){

  if(t == NULL)
    return 0;

  if((t->info == n->info) && (n->sx != NULL) && (n->dx != NULL) )
      return 1;
  return two_children(t->sx,n) || two_children(t->dx,n);
}

//---

void add_root(albero* pa, int z){

    nodo* nuovo_nodo = (nodo*)malloc(sizeof(nodo));

    nuovo_nodo->info = z;
    nuovo_nodo->parent = NULL;
    nuovo_nodo->sx = NULL;
    nuovo_nodo->dx = NULL;

    *pa = nuovo_nodo;
}

nodo* add_left(albero t, int z){

    t->sx = (nodo*)malloc(sizeof(nodo));

    t->sx->info = z;
    t->sx->parent = t;
    t->sx->sx = NULL;
    t->sx->dx = NULL;

    return t->sx;
}

nodo* add_right(albero t, int z){

  t->dx = (nodo*)malloc(sizeof(nodo));

  t->dx->info = z;
  t->dx->parent = t;
  t->dx->sx = NULL;
  t->dx->dx = NULL;

  return t->dx;
}

//cammino con soli figli sinistri
int only_left(albero t){

  if(t == NULL)
      return 1;
  if(t->dx != NULL)
      return 0;
  return only_left(t->sx);
}

//cammino con soli figli destri
int only_right(albero t){

    if(t == NULL)
        return 1;
    if(t->sx != NULL)
        return 0;
    return only_right(t->dx);
}

//---


int cerca_pre(albero t, int n){

    if(t == NULL) return 0;

    if(t->info == n) return 1;

    return cerca_pre(t->sx, n) || cerca_pre(t->dx,n);
}

int cerca_post(albero t, int n){

    if(t == NULL)
        return 0;

    if(cerca_post(t->sx,n))
        return 1;

    if(cerca_post(t->dx, n))
        return 1;

    return (t->info == n);
}

/*
int cerca_post(albero t, int n){
    int trovato;

    if(t == NULL)
        trovato = 0;
    if(cerca_post(t->sx, n))
        trovato = 1;
    if(cerca_post(t->dx, n))
        trovato = 1;
    if(t->info == n)
        trovato = 1;

    return trovato;
}
*/

/*
int cerca_pre(albero t, int n){

    if(t == NULL)
        return 0;

    if(t->info == n)
          return 1;

    if(cerca_post(t->sx, n))
        return 1;

    if(cerca_post(t->dx, n))
        return 1;
}
*/
int cerca_simm(albero t, int n){

    if(t == NULL)
        return 0;
    if(cerca_simm(t->sx,n))
        return 1;
    if(t->info==n)
        return 1;

    return (cerca_simm(t->dx,n));
}

int conta_nodi_post(albero t){

    if(t == NULL)
        return 0;

    return 1+conta_nodi_post(t->sx)+conta_nodi_post(t->dx);
}

int cammino_ric(albero t){

    if(t == NULL)
        return 1;
    if((t->sx != NULL) && (t->dx != NULL))
        return 0;
    return cammino_ric(t->sx) && cammino_ric(t->dx);
}

int cammino_ite(albero t){

      while(t != NULL){
          if((t->sx != NULL) && (t->dx != NULL)){
              return 0;
          }
          if(t->sx != NULL){
              t = t->sx;
          }
          else
              t = t->dx;
      }
      return 1;
}

int altezza(albero t){

    if(t == NULL)
        return -1;

    int h_sx = altezza(t->sx);
    int h_dx = altezza(t->dx);

    if(h_sx > h_dx)
        return 1+h_sx;

    return 1+h_dx;
}

int somma_info_nodi(albero t){

  if(t == NULL)
      return 0;

  return (t->info)+somma_info_nodi(t->sx)+somma_info_nodi(t->dx);
}


float average_info(albero t){

    return (float)somma_info_nodi(t)/conta_nodi_post(t);
}

int completo(albero t){

    if(t == NULL)
        return 1;

    if((t->sx == NULL && t->dx != NULL) || (t->sx != NULL && t->dx == NULL))
        return 0;

    return (completo(t->sx) && completo(t->dx));
}

//verifica se l'albero binario è completo
//il numero di nodi di un albero completo è (2^(h))-1
int completo_h(albero t){

    return pow(2, altezza(t)+1)-1 == conta_nodi_post(t);
}

//dealloca tutti i nodi dell'albero, essa deve essere realizzata in post ordine

void DeallocaABR(albero a)
{
	if(a == NULL)
		free(a);
	else
	{
		DeallocaABR(a->sx);
		DeallocaABR(a->dx);
		free(a);
	}
}


void dealloca(albero t){


    if(t == NULL)
        return;

    dealloca(t->sx);
    dealloca(t->dx);

    if((t->sx == NULL) && (t->dx == NULL))
        free(t);

}

nodo* cerca_id_nodo(albero t, int z){

    if(t->info == z){
        nodo* nuovo_nodo = t;
        return nuovo_nodo;
    }

    if(t->sx != NULL)
        return cerca_id_nodo(t->sx, z);

    if(t->dx != NULL)
        return cerca_id_nodo(t->dx, z);

    return NULL;
}

//pota l'albero radicato al nodo con campo info==z
void pota(albero t, int z){

    if(t == NULL)
        error("pota su albero vuoto!\n");

    nodo* n_trovato = cerca_id_nodo(t, z);
    if(n_trovato == NULL)
        error("non puoi potare su nodo inesistente!\n");

    n_trovato->sx = NULL;
    n_trovato->dx = NULL;

    printf("Ho potato l'albero al di sotto del nodo %d\n", z);
}

//pota l'albero sotto la profondità specificata
void pota_prof(albero t, int prof){

    if(t == NULL)
        return;

    pota_prof(t->sx, prof-1);
    pota_prof(t->dx, prof-1);

    if(prof == 0)
        pota(t,t->info);

}

int valore_nonno(albero t){

    if(t == NULL)
        return 0;

    //int left;
    //int right;

    if (t->parent != NULL) {
        if(t->parent->parent != NULL){
          if(t->parent->parent->info == t->info)
              return 1;

        }

    }
    return valore_nonno(t->sx)+valore_nonno(t->dx);
}

int due_figli(albero t){

    if(t==NULL)
        return 0;

    int left = due_figli(t->sx);
    int right = due_figli(t->dx);

    return ((t->sx != NULL) && (t->dx!=NULL))+left+right;
}

int ho_due_figli(nodo* n){

    if(n==NULL)
        return 0;

    return ((n->sx != NULL) && (n->dx!=NULL));
}

int quattro_nipoti(albero t){

    if(t==NULL)
        return 0;

    return   (ho_due_figli(t->sx) && ho_due_figli(t->dx))+quattro_nipoti(t->sx)+quattro_nipoti(t->dx);
}

//funzione che ti trova un nodo e ritorna il puntatore al nodo trovato
nodo* cerca_post_p(albero t, int n){

    if(t == NULL)
        return NULL;

    nodo* nodo_trovato = cerca_post_p(t->sx, n);

    if(nodo_trovato != NULL)
        return nodo_trovato;

    nodo_trovato = cerca_post_p(t->dx, n);

    if(nodo_trovato != NULL)
        return nodo_trovato;

    if(t->info == n)
        return t;

    return NULL;
}

litem* cammino(albero t, int n){

    if(t== NULL)
        return NULL;

    nodo* nodo_trovato = cerca_post_p(t, n);


    litem* lista = NULL;

    insert_lista_interi(&lista, nodo_trovato->info);

    if(t->info == n)
        return lista;

    nodo_trovato = nodo_trovato->parent;

    while(nodo_trovato != t){
        insert_lista_interi(&lista, nodo_trovato->info);
        nodo_trovato = nodo_trovato->parent;
    }

    insert_lista_interi(&lista, t->info);

    return lista;
}

int conta_elementi_lista(lista_interi lista){
    int lunghezza = 0;

    while (lista != NULL){
          lunghezza++;
          lista = lista->next;
    }
    return lunghezza;
}

int parentela(albero t, nodo* n1, nodo* n2){

    if(t==NULL)
        error("parentela su albero vuoto\n");

     litem* cammino_parentela1 = cammino(t, n1->info);
     litem* cammino_parentela2 = cammino(t, n2->info);

     while(cammino_parentela1->info == cammino_parentela2->info){
          cammino_parentela1 = cammino_parentela1->next;
          cammino_parentela2 = cammino_parentela2->next;
     }
     return conta_elementi_lista(cammino_parentela1)+conta_elementi_lista(cammino_parentela2);
}
