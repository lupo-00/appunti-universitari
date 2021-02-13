#include <stdio.h>
#include <stdlib.h>

#include "esame_settembre.h"


int conta_nodi_un_figlio(albero t){
  int out = 0;
  if(t == NULL)
    return out;

    if((t->left != NULL && t->right == NULL) || (t->right != NULL && t->left == NULL));
      out++;

  return out + conta_nodi_un_figlio(t->left) + conta_nodi_un_figlio(t->left);

}

nodo* opposto(nodo* n, arco* a){
  nodo* opp = a->to;
  if(opp == n)
    opp = a->from;

  return opp;
}

void dfs_mark( nodo* n, int mark){

  n->color = mark;

  elem_archi* la = n->archi;
  while(la != NULL){
    arco* a = la->info;
    nodo* nodo_adiacente = opposto(n, a);
    if(nodo_adiacente->color == 0){
      dfs_mark(nodo_adiacente, mark);
    }
    la = la->next;
  }
}
int componente_minima(grafo* g, int ncc ){
  int min = g->numero_nodi;
  int corrente = 0;

  elem_nodi* ln = g->nodi;
  while(ln != NULL){
    for(int i = 1; i <= ncc; i++){
      if(ln->info->color == i)
      corrente++;
    }
    if(corrente < min)
      min = corrente;
    ln = ln->next;
  }
  return min;
}

int numero_componenti_connesse(grafo* g){

  elem_nodi* ln = g->nodi;
  while(ln != NULL){
    ln->info->color = 0;
    ln = ln->next;
  }
  ln = g->nodi;
  int componenti = 0;
  while(ln != NULL){
    if(ln->info->color == 0){
      componenti++;
      dfs_mark( ln->info, componenti);
    }
    ln = ln->next;

  }

  return componenti;
}

int verifica(albero t, grafo* g){
  if(t == NULL || g == NULL)
    return 0;
    int ncc = numero_componenti_connesse(g);

  if(conta_nodi_un_figlio(t) == componente_minima(g, ncc))
    return 1;

  return 0;
}
