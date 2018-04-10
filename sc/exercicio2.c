#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS 2
#define TAM 20

void *somaVet(void *vet) {

    int *vetor = (int *) vet;
    int i, soma = 0;

    for (i = 0; i < TAM; i++) {
	soma = soma + vetor[i];
    }

    printf("Somatorio = %d\n", soma);

    pthread_exit(NULL);
}

void *maxVet(void *vet) {

    int *vetor = (int *) vet;
    int i, max = vetor[0];

    for (i = 1; i < TAM; i++) {
	if (vetor[i] > max) {
             max = vetor[i];
	}
    }

    printf("Maior valor = %d\n", max);

    pthread_exit(NULL);
}


int main (int argc, char *argv[]) {
    pthread_t threads[NUM_THREADS];

    int vetor[TAM] = {40,38,36,34,32,30,28,26,24,22,20,18,16,14,12,10,8,6,4,2};
    int rc;
    long t;

    for(t = 0; t < NUM_THREADS; t++){
       if (t == 0) {
       	   rc = pthread_create(&threads[t], NULL, somaVet, (void *) &vetor);
           if (rc){
               printf("ERROR; return code from pthread_create() is %d\n", rc);
               exit(-1);
           }
       }
       else {
	   rc = pthread_create(&threads[t], NULL, maxVet, (void *) &vetor);
           if (rc){
               printf("ERROR; return code from pthread_create() is %d\n", rc);
               exit(-1);
           }
       }
    }

    /* Last thing that main() should do */
    pthread_exit(NULL);
}
