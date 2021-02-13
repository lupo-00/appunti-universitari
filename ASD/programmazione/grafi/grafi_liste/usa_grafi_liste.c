#include <stdio.h>
#include <stdlib.h>

#include "grafi_liste.h"

int main(){

  grafo_lista* primo_grafo = nuovo_grafo_lista(6);

     inserisci_arco(primo_grafo, 0, 1);
     inserisci_arco(primo_grafo, 1, 2);
     inserisci_arco(primo_grafo, 2, 3);
     /*inserisci_arco(primo_grafo, 0, 4);
     inserisci_arco(primo_grafo, 0, 5);
     inserisci_arco(primo_grafo, 0, 6);
     inserisci_arco(primo_grafo, 0, 7);
     inserisci_arco(primo_grafo, 0, 8);
     inserisci_arco(primo_grafo, 0, 9);

     inserisci_arco(primo_grafo, 1, 9);
     inserisci_arco(primo_grafo, 1, 9);
     inserisci_arco(primo_grafo, 1, 9);
     inserisci_arco(primo_grafo, 2, 9);
     inserisci_arco(primo_grafo, 3, 9);*/
     inserisci_arco(primo_grafo, 4, 5);
     stampa_grafo_lista(primo_grafo);

     /*int nodo = 0;
     printf("Il grado di uscita del nodo %d é: %d\n ",nodo, grado_uscita(primo_grafo, nodo));

     //printf("Il grafo è semplice = %d\n", grafo_semplice(primo_grafo));

     int* parent = albero_ricoprente(primo_grafo);

     printf("L'array parent é: ");
     for(int i = 0; i < primo_grafo->numero_nodi; i++){
       printf("%d ", parent[i]);
     }
     printf("\n");*/

     //int* color = (int*)malloc(sizeof(int)*primo_grafo->numero_nodi);

     printf("Il numero delle componenti connesse è: %d\n", numero_componenti_connesse(primo_grafo));


     litem* numero_componenti = calcolo_nodi_ogni_componente(primo_grafo);

     while(numero_componenti != NULL){
       printf(" %d ", numero_componenti->info);
       numero_componenti = numero_componenti->next;
     }


}
