#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "common.h"
#include "common_threads.h"
#include "mycommon.h"

volatile int v = 0;

void *operacion1(void *arg) {
	int x=1250;
        int y=350;
        int z=25;
	sleep (2);
	v=(z/y);
	printf("Initial value : %d\n", v);
    return NULL;
}
void *operacion2(void *arg) {
	int x=1250;
        int y=350;
        int z=25;
        v=x*v;
	printf("Initial value : %d\n", v);
    return NULL;
}


int main(int argc, char *argv[]) {
    pthread_t p1, p2;
    printf("Initial value : %d\n", v);
    Pthread_create(&p1, NULL, operacion1, NULL); 
    Pthread_create(&p2, NULL, operacion2, NULL);
	Pthread_join(p1, NULL);
    Pthread_join(p2, NULL);
    printf("Final value   : %d\n", v);
    return 0;
}

