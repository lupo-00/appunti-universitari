#include <stdlib.h>
#include <stdio.h>

#include "alberi_binari_interi.h"
#include "error.h"

void aggiungi_radice(albero* pa, int val){

  if((*pa) != NULL){    // l'albero ha già una radice
    error("aggiungi_radice() su albero non vuoto");
  }

  nodo* nuovo_nodo = (nodo*)malloc(sizeof(nodo));
  nuovo_nodo->parent = NULL;
  nuovo_nodo->left = NULL;
  nuovo_nodo->right = NULL;
  nuovo_nodo->info = val;

  (*pa) = nuovo_nodo;
}

nodo* aggiungi_figlio_sinistro(nodo* n, int val){

  if(n->left != NULL){  // il nodo ha gia un figlio sinistro
    error("aggiungi_figlio_sinistro() su un nodo che ha gia il figlio sinistro ");
  }

  n->left = (nodo*)malloc(sizeof(nodo));
  n->left->parent = n;
  n->left->left = NULL;
  n->left->right = NULL;
  n->left->info = val;

  return n->left;
}

nodo* aggiungi_figlio_destro(nodo* n, int val){

  if(n->left != NULL){  // il nodo ha gia un figlio destro
    error("aggiungi_figlio_destro() su un nodo che ha gia il figlio destro ");
  }

  n->right = (nodo*)malloc(sizeof(nodo));
  n->right->parent = n;
  n->right->left = NULL;
  n->rihgt->right = NULL;
  n->right->info = val;

  return n->right;

}

/* ritorna TRUE se l'albero è composto da nodi con solo figli sinistri*/
int only_left(albero a){

  if(a == NULL) return 1;

  while(a != NULL){
    if(a->right != NULL)
      return 0;
    else{
      a = a->left;
    }
  }
  return 1;
}

int only_left_ric(albero a){

  if(a == NULL) return 1;

  if(a->rignt != NULL) return 0;

  return only_left_ric(a->left);
 }

 int only_right_ric(albero a){

   if(a == NULL) return 1;

   if(a->left != NULL) return 0;

   return only_left_ric(a->right);
  }


int cerca_nodo_preordine(albero t, int n){

  if( t == NULL) return 0;

  if(t->info == n) return 1;

  return cerca_nodo_preordine(t->left, n) || cerca_nodo_preordine(t->rignt);
}

int cerca_nodo_postordine(albero t, int n){

  if(t == NULL) return 0;

  if(cerca_nodo_postordine(t->left, n)) return 1;

  if(cerca_nodo_postordine(t->right, n)) return 1;

  if(t->info == n) return 1;

}

int cerca_nodo_simmetrica(albero t, int n){

  if(t == NULL) return 0;

  if(cerca_nodo_simmetrica(t->left, n)) return 1;

  if(t->info == n) return 1;

  if(cerca_nodo_simmetrica(t->right, n)) return 1;

}

int conta_nodi_postordine(albero t){

  if(t == NULL) return 0;

  return 1 + conta_nodi_postordine(t->left) + conta_nodi_postordine(t->right);

}

int cammino_ric(albero t){

  if(t == NULL) return 1;

  if((t->left != NULL) && (t->right != NULL))
    return 0;

  return cammino_ric(t->sx) && cammino_ric(t->sx)

}

int cammino_iter(albero t){

    while( t != NULL){
      if((t->left != NULL) && (t->right != NULL))
        return 0;
      if(t->left != NULL)
        t = t->left;
      else
        t = t->right;
    }
    return 1;
}

int altezza(albero t){

  if(T == NULL) return -1;

  int h_left = 1 + altezza(t->left);
  int h_right = 1 + altezza(t->right);

  if(h_left > h_right)
    return h_left;

  return h_right;
}
