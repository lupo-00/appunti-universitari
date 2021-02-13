#include <stdio.h>
#include <stdlib.h>

#include "esame_luglio_B.h"

int discendenti(nodo* t){
  if(t == NULL)
    return 0;

  int son = 0;
  nodo* n = t->left_child;
  while(n != NULL){
    son++;
    son = son + discendenti(n);
    n = n->right_sibling;
  }
  return son;
}

int conta(nodo* a){
  if(a == NULL)
    return 0;

  int quanti = 0;
 if(discendenti(a) == a->info)
   quanti = quanti + 1;

  return quanti + conta(a->left_child) + conta(a->right_sibling);
}
