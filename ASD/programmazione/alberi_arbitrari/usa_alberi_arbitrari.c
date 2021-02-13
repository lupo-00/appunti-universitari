#include <stdio.h>
#include <stdlib.h>

#include "stampa_albero_arbitrario.h"
#include "stampa_albero_binario.h"
#include "esercizi_alberi_arbitrari.h"

int main(){

    albero a = NULL;  // questa volta e' un albero arbitrario

    add_root(&a, 1);
    int i;
    for(i = 1; i < 20; i++ ) {
       nodo* figlio = add_son(a,i);
       if( figlio->info % 10 == 0) {
        int j;
        for( j = 0; j < 5; j++) {
          add_son(figlio,20+j);
          printf("aggiungo il figlio %d a %d\n",20+j,figlio->info);
        }
       }
    }
    stampa_albero_arbitrario(a);

    printf("I nodi dell'albero arbitrario sono: %d\n", conta_nodi_arb(a));

    
}
