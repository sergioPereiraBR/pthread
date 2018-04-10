#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS 5

void *PrintThread(void *threadid)
{
   long tid;
   tid = (long) threadid;
   
   printf("Thread #%ld criada\n", tid);
   pthread_exit(NULL);
}

int main (int argc, char *argv[])
{
   pthread_t threads[NUM_THREADS];
   long taskids[NUM_THREADS];
   int rc;
   long t;

   for(t=0; t<NUM_THREADS; t++){
      taskids[t] = t;
      printf("Base cria thread %ld\n", t);

      rc = pthread_create(&threads[t], NULL, PrintThread, (void *)taskids[t]);

      if (rc) {
         printf("Falha no retorno de ptrhread_creta(), cod.= %d\n", rc);
         exit(-1);
      }
   }

   pthread_exit(NULL);
}
