#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM_THREADS 4

typedef struct thread_data{
   int thread_id;
   int rand;
} Tipo_Thread_Data;

struct thread_data thread_data_array[NUM_THREADS];

void *PrintThread(void *threadarg)
{
   struct thread_data *my_data;
   my_data = (struct thread_data_array *) threadarg;
   long taskid = (long) my_data-> thread_id;
   int rand = (int) my_data->rand;
   long prod = (long) rand * taskid;

   printf("Thread %ld Random %d Produto %ld \n", taskid, rand, prod);
   pthread_exit(NULL);
}


int main(int argc, char *argv[])
{
   pthread_t threads[NUM_THREADS];
   int rc;
   int num_rand;
   long t;
   
   srand(time(NULL));

   for(t=0; t<NUM_THREADS; t++){
      num_rand = 1+(rand()%10);

      printf("Base cria Thread #%ld\n",t);

      thread_data_array[t].thread_id = t;
      thread_data_array[t].rand = num_rand;

      rc = pthread_create(&threads[t], NULL, PrintThread, (void *) &thread_data_array[t]);

      if(rc){
         printf("Falha no retorno, pthread(create(), cod. = %d\n", rc);
         exit(-1);
      }
   }

   pthread_exit(NULL);
}
