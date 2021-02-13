#include <stdio.h>
#include <stdlib.h>

#include "esercizi_alberi_radicati.h"
#include "stampa_albero_binario.h"
#include "lista_interi.h"

#include "abr.h"

int main(){
    nodo* albero = new_tree();

    add_root(&albero, 10);

    //printf("%d\n", root(albero)); //stampa la radice

    /*Esempio di ABR*/
    add_left(albero, 7);
    add_right(albero, 12);
    add_right(albero->dx, 14);
    add_right(albero->sx, 8);
    add_left(albero->sx, 6);
    add_left(albero->dx, 11);


    /*Esmepio albero binario che non è un ABR
    add_left(albero, 54);
    add_right(albero, 2);
    add_right(albero->dx, 0);
    add_right(albero->sx, 1);
    add_left(albero->sx, 60);
    add_left(albero->dx, 23);
*/

    stampa_albero_binario(albero);

    printf("L'albero è un abr in preordine: %d\n", is_abr_pre(albero));
    int length = 6;
    int array[length];
    array[0] = 54;
    array[1] = 2;
    array[2] = 0;
    array[3] = 1;
    array[4] = 60;
    array[5] = 23;


    printf("L'array è: ");
    for(int i = 0; i < 6; i++){
        printf("%d", array[i]);
    }
    printf("\n");


    printf("L'array ordinato è: ");
    tree_sort(array, length);
    for(int i = 0; i < 6; i++){
        printf("%d", array[i]);
    }
    printf("\n");

}
