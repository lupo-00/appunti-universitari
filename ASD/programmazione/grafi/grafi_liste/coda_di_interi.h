#ifndef _CODA_DI_INTERI_H
#define _CODA_DI_INTERI_H

typedef struct cdi {

	int* A;
	int  size;
	int  head;
	int  tail;

} coda_di_interi;

coda_di_interi* new_queue(int default_size); 

int is_empty(coda_di_interi* pc);

int dequeue(coda_di_interi* pc);

void enqueue(coda_di_interi* pc, int x);

void stampa_coda_di_interi(coda_di_interi* pc);

#endif