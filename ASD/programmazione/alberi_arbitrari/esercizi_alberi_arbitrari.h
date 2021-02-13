#ifndef _ESERCIZI_ALBERI_ARBITRATI_H
#define _ESERCIZI_ALBERI_ARBITRATI_H

#include "esercizi_alberi_radicati.h"
#include "lista_interi.h"
#include "error.h"

int conta_nodi_arb(albero t);

nodo* add_son(albero t, int n);

nodo* add_siblign(albero t, int n);

nodo* cerca_arbi(albero t, int n);

int binario(albero t);

int grado_massimo(albero t);

int cammino_arbitrario(nodo* t);

int conta_nodi_prof_arb(albero t, int prof);


#endif
