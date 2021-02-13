#include <stdio.h>
#include <stdlib.h>

#include "esame_luglio_A.h"

int conta_nodi_prof(albero t, int prof){

  if( t == NULL)
    return 0;
  if(prof == 0)
    return 1;

  return conta_nodi_prof(t->left, prof-1) + conta_nodi_prof(t->right, prof-1);
}

int altezza_a(albero a){
  if(a == NULL)
    return -1;

    int left = altezza_a(a->left);
    int right = altezza_a(a->right);

  if(left > right)
    return left + 1;

  return right + 1;
}

int verifica(albero a){
  int depth = altezza_a(a);

  while(depth <= 0){// ERRORE qui avevo scritto "!=" invece di "<="
    if(depth == conta_nodi_prof(a, depth))
      return 1;
    depth--;
  }
  return 0;

}

/* alternativa ricorsiva*/

int verifica2(albero a){

  if(a == NULL)
    return 0;
  int depth = altezza_a(a);

  return (depth == conta_nodi_prof(a, depth)) || verifica2(a->left) || verifica(a->right);
}
