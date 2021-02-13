#include <stdio.h>
#include <stdlib.h>

#include "grafi_oggetto.h"


int main(){

  grafo_oggetti* pgo = crea_grafo();

  nodo* n1 = aggiungi_nodo(pgo, 1);
  nodo* n2 = aggiungi_nodo(pgo, 2);
  nodo* n3 = aggiungi_nodo(pgo, 3);
  //nodo* n4 = aggiungi_nodo(pgo, 3);
  //nodo* n5 = aggiungi_nodo(pgo, 2);
  //nodo* n6 = aggiungi_nodo(pgo, 1);


  arco* a1 = aggiungi_arco(pgo, n1, n2, 1);
  //arco* a2 = aggiungi_arco(pgo, n2, n1, 2);

/*  stampa_grafo(pgo);

  rimuovi_arco(pgo, a1);

  stampa_grafo(pgo);*/

  printf("Il numero di componenti del grafo è: %d ", numero_componenti_grafi_oggetti(pgo));
  printf("\n");

litem* lcc = calcolo_nodi_ogni_componente_oggetti(pgo);


printf(" Stampo tutte le grandezze delle %d componenti commesse: ", numero_componenti_grafi_oggetti(pgo));
while(lcc != NULL){
  printf(" %d ", lcc->info);
  lcc = lcc->next;
}
printf("\n");
}
