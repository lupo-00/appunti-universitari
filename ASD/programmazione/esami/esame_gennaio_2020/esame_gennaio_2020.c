#include <stdio.h>
#include <stdlib.h>

#include "esame_gennaio_2020.h"


int conta_figli_di_un_nodo(albero t){

  int contatore = 0;
  nodo_albero* x = t->left;
  while(x != NULL){
    contatore++;
    x = x->right;
  }

  return contatore ;

}

int dfs_size(nodo* n){
  n->color = 1;

}

int verifica_ric(nodo_albero* t, grafo* g){

}

int verifica(nodo_albero* a, grafo* g){
  if(a == NULL || g == NULL)
      return 0;

  return verifica_ric;
}
