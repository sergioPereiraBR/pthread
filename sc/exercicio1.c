#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM_THREADS 4
#define TAM 20
#define MAX 10

struct thread_data{
   long  thread_id;
   long  rand;
};

struct thread_data thread_data_array[NUM_THREADS];

void *multRand(void *argumentos) {
    struct thread_data *numeros;
    numeros = (struct thread_data *) argumentos;


    long tid, rd;
    tid = numeros->thread_id;
    rd = numeros->rand;

    printf("Thread # %ld\t|\trandomico = %ld\t|\tresultado = %ld\n", tid, rd, tid*rd);

    pthread_exit(NULL);
}

int main (int argc, char *argv[]) {
    pthread_t threads[NUM_THREADS];
    srand (time(NULL));

    int rc;
    long t;
    for(t = 0; t < NUM_THREADS; t++){

       thread_data_array[t].thread_id = t;
       
       thread_data_array[t].rand = rand()%MAX+1;;

       rc = pthread_create(&threads[t], NULL, multRand, (void *) &thread_data_array[t]);
       if (rc){
          printf("ERROR; return code from pthread_create() is %d\n", rc);
          exit(-1);
       }
    }

    /* Last thing that main() should do */
    pthread_exit(NULL);
}
