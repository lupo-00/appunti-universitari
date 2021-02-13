#include <stdio.h>
#include <stdlib.h>

#include "grafi_liste.h"
#include "lista_interi.h"
#include "error.h"
#include "coda_di_interi.h"

grafo_lista* nuovo_grafo_lista(int numero_nodi){

  grafo_lista* new_grafo = (grafo_lista*)malloc(sizeof(grafo_lista));

  new_grafo->numero_nodi = numero_nodi;
  new_grafo->lista = (lista_interi*)calloc(numero_nodi, sizeof(lista_interi));

  return new_grafo;
}

void stampa_grafo_lista(grafo_lista* g) {

	int i;
	for(i = 0; i < g->numero_nodi; i++ ) {

		printf("%d[]->", i);
		lista_interi e = g->lista[i];
		while( e != NULL ) {
			printf("%d->",e->info);
			e = e->next;
		}
		printf("\n");
	}
}

/* si presume che non si stia inserendo lo stesso arco più volte*/
void inserisci_arco_lista(grafo_lista* g, int i, int j){

  lista_interi nuovo_arco = (lista_interi)malloc(sizeof(litem));
  nuovo_arco->info = j;
  nuovo_arco->prev = NULL;
  nuovo_arco->next = g->lista[i];

  if(g->lista[i] != NULL){
    g->lista[i]->prev = nuovo_arco;
  }

  g->lista[i] = nuovo_arco;
}

void inserisci_arco(grafo_lista* g, int i, int j){

  inserisci_arco_lista( g,  i,  j);
  inserisci_arco_lista( g,  j,  i);

}
//funzione professore per aggiunta archi


int grado_uscita(grafo_lista* g, int i){

  int grado = 0;
  while(g->lista[i] != NULL){
      grado++;
    g->lista[i] = g->lista[i]->next;
  }

  return grado;
}
/* verifica che un grafo sia semplice (che non abbia loop)*/
int grafo_semplice(grafo_lista* g){

  int verifica = 1;
  if(g == NULL)
    return verifica;

  for(int i = 0; i < g->numero_nodi; i++){
    while(g->lista[i] != NULL){
      if(g->lista[i]->info == i){
        verifica = 0;
      }
      g->lista[i] = g->lista[i]->next;
    }
  }
  return verifica;
}
/* funzione che attraverso una dfs ritorna un array parent*/
void DFS_parent(grafo_lista* g, int u, int* parent, int* color){

  color[u] = 1;   // marco il nodo visitato
  litem* x = g->lista[u];

  while(x != NULL){
    if(color[x->info] == 0){  // se questo vicino è stato visitato
      parent[x->info] = u;
      DFS_parent(g, x->info, parent, color);
    }
    x = x->next;
  }
}

int* albero_ricoprente(grafo_lista* g){

  int* parent = (int*)malloc(sizeof(int)*(g->numero_nodi));
  int* color = (int*)malloc(sizeof(int)*(g->numero_nodi));

  for(int i = 0; i < g->numero_nodi; i++){
    parent[i] = -1;
    color[i] = 0;
  }
  DFS_parent(g, 0, parent, color);

  free(color);
  return parent;
}

void dfs(grafo_lista* g){
  /*creo e pulisco l'array con marcatori*/
  int* color = (int*)calloc(g->numero_nodi, sizeof(int));

  dfs_visit( g, 0, color);
}

void dfs_v(grafo_lista* g, int v){
  /*creo e pulisco l'array con marcatori*/
  int* color = (int*)calloc(g->numero_nodi, sizeof(int));

  dfs_visit( g, v, color);
}

void dfs_visit(grafo_lista* g, int i, int* color){

    color[i] = 1;
    litem* lista_nodi = g->lista[i];

    while(lista_nodi != NULL){
      if(color[lista_nodi->info] == 0){
        dfs_visit(g, lista_nodi->info, color);
      }
      lista_nodi = lista_nodi->next;
    }
}

  void dfs_mark(grafo_lista* g, int i, int* color, int mark){

    color[i] = mark;
    litem* lista_nodi = g->lista[i];

    while(lista_nodi != NULL){
      if(color[lista_nodi->info] == 0)
        dfs_mark(g, lista_nodi->info, color, mark);

      lista_nodi = lista_nodi->next;
    }
}

int numero_componenti_connesse(grafo_lista* g){

  int* color = (int*)calloc(g->numero_nodi, sizeof(int));
  int componenti = 0;
  for(int i = 0; i < g->numero_nodi; i++){
    if(color[i] == 0){
      componenti++;
      dfs_visit(g, i, color);
    }
  }


  return componenti;
}

int componenti_connesse_liste(grafo_lista* g){
    /* creo un array color per visitare tutto il grafo*/

    int* color = (int*)calloc(g->numero_nodi,sizeof(int));

    int contatore = 0;

    //bfs_liste_color(g,0,color); // ho visitato
    // contatore++; se voglio subito contare il grafo con gli elementi connessi a 0

    int i;
    for(i = 0; i < g->numero_nodi; i++){
        if(color[i] == 0){
            for(int j = 0; j < g->numero_nodi; j++){
              printf(" array[j] = %d ", color[j] );
            }
            printf("\nlancio bfs su nodo %d\n", i);
            bfs_liste_color(g,i,color);
            contatore++;

        }
    }
    return contatore;
}

void bfs_liste_color(grafo_lista* g, int v, int* color){
    /*creiamo la coda dove poi inseriremo i nodi da marcare*/
    coda_di_interi* q = new_queue(g->numero_nodi);
    enqueue(q,v); // inserisco il nodo da tastiera nella coda
    color[v] = 1; // coloro l'elemento primo messo in coda

    while( !is_empty(q)){
        int u = dequeue(q);
        printf("hai dequequato il nodo %d\n", u);

        int i; //iteratore per scorrere nell'array
        for(i = 0; i < g->numero_nodi; i++){
            litem* x = g->lista[u];
            while( x != NULL){ //scorri all'interno della lista
                if( color[x->info] == 0){
                    enqueue(q,x->info);
                    //color[x->info] = 1;
                }
                x = x->next;
            }
        }
    }
}

//Funzione che ritorna la grandezza della componente visitata
int dfs_lista_size(grafo_lista* g, int* color, int i){
		color[i] = 1;
		int contatore = 1;

		litem* x = g->lista[i];
		while(x!=NULL){
				if(color[x->info] == 0){
						contatore = contatore+dfs_lista_size(g, color, x->info);
				}
		x = x->next;
		}
		return contatore;
}

//Funzione che attraverso la DFS, ritorna il numero
//di nodi di una componente connessa di un
//grafo rappresentato con liste di adiacenza
litem* calcolo_nodi_ogni_componente(grafo_lista* g){
		litem* lista_componenti = NULL;

		int* color = (int*)calloc(g->numero_nodi,sizeof(int));
		for( int i = 0; i<g->numero_nodi; i++){
				if(color[i]==0) //aggiungo un nodo alla lista di componenti
						insert_lista_interi(&lista_componenti, dfs_lista_size(g,color, i));
		}

		return lista_componenti;
}
