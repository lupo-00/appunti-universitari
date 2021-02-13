#ifndef _STAMPA_ALBERO_BINARIO_H
#define _STAMPA_ALBERO_BINARIO_H

#include "esercizi_alberi_arbitrari.h"

void indenta(int* prefix, int prof);
void stampa_figlio_sinistro(nodo* n, int* prefix, int prof);
void stampa_figlio_destro(nodo* n, int* prefix, int prof);
void stampa_albero_binario(nodo* root);

#endif
