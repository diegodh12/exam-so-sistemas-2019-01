#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "common_threads.h"
#include "mycommon.h"

volatile int counter = 0;
puerta puertaP;
 
int loops;

void *worker(void *arg) {
    int i;
    cerrar_puerta(puertaP);
    for (i = 0; i < loops; i++) {
	counter++;
    }
    abrir_puerta(puertaP);
    return NULL;
}

int main(int argc, char *argv[]) {
	clock_t t_ini, t_fin;
 	double secs;
	t_ini = clock();
    if (argc != 2) { 
	exit(1);
    }
    crear_puerta(puertaP);
    loops = atoi(argv[1]);
    pthread_t p1, p2;
    printf("Initial value : %d\n", counter);
    Pthread_create(&p1, NULL, worker, NULL); 
    Pthread_create(&p2, NULL, worker, NULL);
    Pthread_join(p1, NULL);
    Pthread_join(p2, NULL);
    printf("Final value   : %d\n", counter);
    destruir_puerta(puertaP);
t_fin = clock();

  secs = (double)(t_fin - t_ini) / CLOCKS_PER_SEC;
  printf("%.16g milisegundos\n", secs * 1000.0);
    return 0;
}
