#include <stdlib.h>
#include <stdio.h>
#include "esercizi_alberi_radicati.h"
#include "stampa_albero_binario.h"

/*
	Prende in input un array "prefix" e la sua lunghezza "n".
    L'array ha un "1" per ogni antenato che ha un figlio
    che deve essere disegnato sotto la linea corrente e ha "0" altrimenti.
*/

void indenta(int* prefix, int prof) {
    int i;
    for(i = 0; i < prof; i++) {
        if(prefix[i] == 1) {
             printf("|  ");
		} else {
             printf("   ");
		}
    }
}

void stampa_figlio_sinistro(nodo* n, int* prefix, int prof) {

    if (n->dx != NULL) {
        prefix[prof+1] = 1;
        stampa_figlio_destro(n->dx, prefix, prof + 1);
    }

    indenta(prefix, prof);
    printf("`--%d\n", n->info);

    prefix[prof] = 0;  // l'arco che porta al tuo genitore non e' visto dal tuo sottoalbero sinistro
    if (n->sx != NULL) {
        prefix[prof+1] = 1;
        stampa_figlio_sinistro(n->sx, prefix, prof + 1);
    }

}

void stampa_figlio_destro(nodo* n, int* prefix, int prof) {

    prefix[prof] = 0;  // l'arco che porta al tuo genitore non e' visto dal tuo sottoalbero destro
    if (n->dx != NULL) {
        prefix[prof+1] = 1;
        stampa_figlio_destro(n->dx, prefix, prof + 1);
    }

    indenta(prefix, prof);
    printf(".--%d\n", n->info);
    prefix[prof] = 1;  // l'arco che porta al tuo genitore e' visto dal tuo sottoalbero sinistro

    if (n->sx != NULL) {
        prefix[prof+1] = 1;
        stampa_figlio_sinistro(n->sx, prefix, prof + 1);
    }

}


void stampa_albero_binario(nodo* root) {
    if (root == NULL) return;

    int d = altezza(root);
    int* prefix = calloc(d,sizeof(int));
    int prof = 0;

    if (root->dx != NULL) {
        prefix[prof+1] = 1;
        stampa_figlio_destro(root->dx, prefix, prof + 1);
    }

    printf(" --%d\n", root->info);

    if (root->sx != NULL) {
        prefix[prof+1] = 1;
        stampa_figlio_sinistro(root->sx, prefix, prof + 1);
    }
    free(prefix);
}
