#include <stdio.h>
#include <stdlib.h>

#include "esercizi_alberi_arbitrari.h"
#include "error.h"

int conta_nodi_arb(albero t){
  if(t == NULL) return 0;

  int conteggio = 0;
  nodo* x = t->sx;
  while(x != NULL){
    conteggio = conteggio + conta_nodi_arb(x);
    x = x->dx;
  }

  return 1 + conteggio;
}

nodo* add_son(albero t, int n){

  if( t == NULL){
    error("add_son su nodo = NULL\n");
  }
  nodo* son = (nodo*)malloc(sizeof(nodo));
  son->parent = t;
  son->sx = NULL;
  son->dx = t->sx;
  son->info = n;

  t->sx = son;
  return son;

}

nodo* add_siblign(albero t, int n){
      if(t == NULL)
        error("add_sibling su albero vuoto\n");
      if(t->parent == NULL)
        error("add_sigling su nodo radice\n");

      nodo* sibling = (nodo*)malloc(sizeof(nodo));
      sibling->parent = t->parent;
      sibling->sx = NULL;
      sibling->dx = NULL;
      sibling->info = n;

      t->dx = sibling;

      return sibling;
}

nodo* cerca_arbi(albero t, int n){

    if(t == NULL) return NULL;

    if(t->info == n)
      return t;

    nodo* i = t->sx;

    while(i != NULL){
      nodo* nodo_trovato = cerca_arbi(i, n);
      if(nodo_trovato != NULL){
        return nodo_trovato;
      }
      i = i->dx;
    }
    return NULL;

}

int grado_massimo(albero t){

  if( t == NULL) return -1;

  int grado = 0;
  int massimo = 0;

  nodo* son = t->sx;

  while(son != NULL){
      grado = grado + 1;
      int grado_max_figlio = grado_massimo(son);
      if(grado_max_figlio > massimo)
          massimo = grado_max_figlio;

      son = son ->dx;
  }

  if(grado > massimo)
      return grado;
  return massimo;
}

int binario(albero t){

  if(t == NULL) return 0;

  nodo* son  = t->sx;

  while(son != NULL){
    if(two_children(son, son))
        return 1;
    son = son->dx;
  }

  return (two_children( t, t));
}

nodo* copia_albero(nodo* t){
    if(t==NULL)
        return t;
    nodo* temp=(nodo*) malloc(sizeof(nodo));
    temp->parent=t->parent;
    temp->info=t->info;
    temp->sx=copia_albero(t->sx);
    temp->dx=copia_albero(t->dx);
    return temp;
}
