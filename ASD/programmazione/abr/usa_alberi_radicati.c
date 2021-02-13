#include <stdio.h>
#include <stdlib.h>

#include "esercizi_alberi_radicati.h"
#include "stampa_albero_binario.h"
#include "error.h"
#include "lista_interi.h"


int main(){
    nodo* albero = new_tree();

    add_root(&albero, 3);

    printf("%d\n", root(albero));

    add_left(albero, 4);
    add_right(albero, 5);
    add_right(albero->dx, 0);
    add_right(albero->sx, 8);
    add_left(albero->sx, 6);
    add_left(albero->dx, 7);

    //add_left(albero->sx->sx, 9);

    //printf("%d\n", root(albero->sx));
    //printf("%d\n", root(albero->dx));

    printf("altezza = %d\n", altezza(albero));

    printf("cammino = %d\n", cammino_ric(albero));

    printf("numero nodi = %d\n", conta_nodi_post(albero));

    printf("esiste il nodo con valore 9: %d\n", cerca_simm(albero, 9));

    printf("la media fra tutti i nodi è: %.2f\n", average_info(albero));

    printf("l'albero è completo? = %d\n", completo(albero));


    stampa_albero_binario(albero);

    //printf("prima deallocazione\n");

    //printf("%p\n", root_id(albero));

    //dealloca(albero);

    //printf("dopo deallocazione\n");

    //printf("%p\n", root_id(albero));

    //pota(albero, 4);

    //stampa_albero_binario(albero);
    //stampa_albero_binario(albero);
    //stampa_albero_binario(albero);
    //printf("poto l'albero sotto profondità 1\n");


    //pota_prof(albero, 1);

    //printf("poto l'albero sotto profondità 2 post\n");

    //stampa_albero_binario(albero);

    //printf("%d\n", root(albero));
    //printf("%d\n", root(albero->sx));
    //printf("%d\n", root(albero->dx));
    //printf("%d\n", root(albero->dx->dx));

    //stampa_albero_binario(albero);

    //printf("Ci sono %d nodi con valore uguale al nonno\n", valore_nonno(albero));

    printf("Ci sono %d nodi che ha/hanno due figli nell'albero.\n", due_figli(albero));

    printf("Ci sono %d nodi che ha/hanno quattro nipoti nell'albero.\n", quattro_nipoti(albero));

    print_lista_interi(cammino(albero, 3));

    printf("La lunghezza del cammino tra il nodo %d e il nodo %d è: %d\n",albero->info, albero->dx->dx->info, parentela(albero, albero, albero->dx->dx));


}
