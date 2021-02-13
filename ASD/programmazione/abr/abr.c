#include <stdio.h>
#include <stdlib.h>

#include "stampa_albero_binario.h"
#include "esercizi_alberi_radicati.h"

#include "abr.h"

int is_abr_pre(nodo* t){

  if(t == NULL)
   return 0;

   if((t->sx->info < t->info) && (t->dx->info > t->info))
      return 1;

    return 0;

    return is_abr_pre(t->sx) && is_abr_pre(t->dx);
}

int is_abr_post(nodo* t){

  if(t == NULL)
   return 0;

   int left = is_abr_pre(t->sx);
   int right = is_abr_pre(t->dx);

    return (t->sx->info < t->info) && (t->sx->info > t->info) && left && right;

}

nodo* inserisci(nodo* tree, int val){

    if(tree == NULL){
      add_root(&tree, val);
    }
    else{
      if(val > tree->info){
          if(tree->sx == NULL){
            tree->sx->info = val;
            tree->sx->sx = NULL;
            tree->sx->dx = NULL;
            tree->sx->parent = tree;
          }
          else{
              inserisci(tree->sx, val);
          }
      }
    else if(val < tree->info){
        if(tree->dx == NULL){
          tree->dx->info = val;
          tree->dx->sx = NULL;
          tree->dx->dx = NULL;
          tree->dx->parent = tree;
        }
        else{
          inserisci(tree->sx, val);
        }

    }

  }
    return tree;
}

/* funzione che aggiunge nodo in un abr*/
void aggiungi_nodo_contratto(nodo** pn, int val, nodo* parent) {

	if ((*pn)==NULL)  {
		(*pn) = (nodo*)malloc(sizeof(nodo));
		(*pn)->parent = parent;
		(*pn)->sx = NULL;
		(*pn)->dx = NULL;
		(*pn)->info = val;
		return;
	}

	// se val giÃ  c'Ã¨ esco
	if( (*pn)->info == val )
		return;   // il nodo da aggiungere c'era giÃ

	if( (*pn)->info > val )
		aggiungi_nodo_contratto( &((*pn)->sx) , val, (*pn));
	else
		aggiungi_nodo_contratto( &((*pn)->dx) , val, (*pn));
}

int tree_to_array_ric(int* A, nodo* t, int size, int pos){

    if( t == NULL)
        return pos;

    pos = tree_to_array_ric(A, t->sx, size, pos);
    A[pos] = t->info;
    return tree_to_array_ric(A, t->dx, size, pos+1);
}


 void tree_to_array(int* A, nodo* t, int size){
   tree_to_array_ric( A, t, size, 0);
}

void tree_sort(int* A, int length){
    nodo* tree = NULL;

    for(int i = 0; i < length; i++){
      aggiungi_nodo_contratto(&tree, A[i], NULL);
    }
    tree_to_array(A, tree, length);
}

/*funzione che cancella un nodo con un solo figlio
void delete_sigle_tBR(root r, node* n){​​​​​
    printf("removing %d \n",n->key);
    printf("ha uno o zero figli \n");
    node* temp = (node*)malloc(sizeof(node));
    //se il figlio è sx
    if(n->left != NULL)
        temp = n->left;
    //se il figlio è dx
    else
        temp = n->right;
    //se ha un figlio
    if(temp != NULL)
        temp->parent = n->parent;
    if(n->parent != NULL){​​​​​
        //se era un figlio sx
        if(n == n->parent->left){​​​​​
            n->parent->left = temp;
        //se era un figlio dx
        }​​​​​else{​​​​​
            n->parent->right = temp;
        }​​​​​
    }​​​​​else //era radice
        r = temp;
}​​​​​*/
