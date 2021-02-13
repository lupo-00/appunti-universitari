#ifndef ESAME_LUGLIO_A
#define ESAME_LUGLIO_A

typedef struct nodo_struct {
 struct nodo_struct* left;
 struct nodo_struct* right;
 int info;
} nodo;

typedef nodo* albero;

int verifica(albero a);

#endif
