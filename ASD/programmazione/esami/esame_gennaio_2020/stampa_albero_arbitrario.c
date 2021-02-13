#include <stdlib.h>
#include <stdio.h>
#include "esercizi_alberi_arbitrari.h"
#include "stampa_albero_arbitrario.h"


int __depth(nodo* root) {

    if (root == NULL) return -1;
    int l = __depth(root->sx);
    int r = __depth(root->dx);
    l = l+1;
    if( l > r ) return l;
    return r;
}

/*
	Prende in input un array "prefix" e la sua lunghezza "n".
    L'array ha un "1" per ogni antenato che ha un figlio
    che deve essere disegnato sotto la linea corrente e ha "0" altrimenti.
*/

void indenta_ascii(int* prefix, int prof) {
    int i;
    for(i = 0; i < prof; i++) {
        if(prefix[i] == 1) {
             printf("|   ");
		} else {
             printf("    ");
		}
    }
}

void stampa_albero_arbitrario_ricorsiva(nodo* n, int* prefix, int prof) {
    indenta_ascii(prefix, prof);
    if(n->dx == NULL) {
        printf("`---%d\n", n->info);
        prefix[prof] = 0;
    } else {
        printf("|---%d\n", n->info);
        prefix[prof] = 1;
    }

    if (n->sx != NULL) {
        stampa_albero_arbitrario_ricorsiva(n->sx, prefix, prof + 1);
    }

    if (n->dx != NULL) {
        stampa_albero_arbitrario_ricorsiva(n->dx, prefix, prof);
    }

}


void stampa_albero_arbitrario(nodo* root) {
    if (root == NULL) return;
    int d = __depth(root);
    int* prefix = (int*)calloc(d,sizeof(int));
    printf("%d\n", root->info);
    if (root->sx != NULL) {
        stampa_albero_arbitrario_ricorsiva(root->sx, prefix, 0);  // zero e' la profondita
    }
    free(prefix);
}
