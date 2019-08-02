#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "common.h"
#include "common_threads.h"
#include "mycommon.h"
puerta puertaP;

volatile float v = 0;

void *operacion1(void *arg) {
        int y=350;
        int z=25;
	cerrar_puerta(puertaP);
	sleep (2);
	v=(float)z/(float)y;
	printf("v en hilo 1 : %f\n", v);
	abrir_puerta(puertaP);
    return NULL;
}
void *operacion2(void *arg) {
	int x=1250;
	cerrar_puerta(puertaP);
        v=v*(float)x;
	printf("v en hilo 2 : %f\n", v);
	abrir_puerta(puertaP);
    return NULL;
}


int main(int argc, char *argv[]) {
    crear_puerta(puertaP);
    pthread_t p1, p2;
    printf("Initial value : %f\n", v);
    Pthread_create(&p1, NULL, operacion1, NULL); 
    Pthread_create(&p2, NULL, operacion2, NULL);
	Pthread_join(p1, NULL);
    Pthread_join(p2, NULL);
    printf("Final value   : %f\n", v);
    destruir_puerta(puertaP);
    return 0;
}

