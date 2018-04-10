#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS 7

void *PrintThread(void *id)
{
   long idt;
   idt = (long) id;
   printf("Thread %ld\n", idt+1);

   pthread_exit(NULL);
}

void CallThread(long nt, pthread_t *t){
   int rc;
   rc = pthread_create(t, NULL, PrintThread, (void *) nt);

   if(rc){
      printf("Falha ao criar Thrade %ld, cod: %d\n", nt, rc);
      exit(-1);
   }
}

int main(int argc, char *argv[])
{
   long i;
   pthread_t threads[NUM_THREADS];
   
   for(i=0; i<NUM_THREADS; i++){
      
      CallThread(i, &threads[i]);

      switch (i){
         case 0:
            pthread_join(threads[i],NULL);
            break;
         case 1:
            pthread_join(threads[i],NULL);
            break;
         case 4:
            pthread_join(threads[i-2],NULL);
            pthread_join(threads[i-1],NULL);
            pthread_join(threads[i],NULL);
            break;
         case 5:
            pthread_join(threads[i],NULL);
            break;
         case 6:
            pthread_join(threads[i],NULL);
            break;
       } 
   }
}
