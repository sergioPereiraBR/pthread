#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS 5

typedef struct thread_data{
   int thread_id;
   int sum;
   char *message;
}Tipo_thread_data;

struct thread_data thread_data_array[NUM_THREADS];

void *PrintThread(void *threadarg)
{
   struct thread_data *my_data;
   my_data = (struct thread_data *) threadarg;
   long taskid = (long) my_data->thread_id;
   int sum = my_data->sum;
   char* hello_msg = my_data->message;

   printf("Tarefa  #%ld - soma #%d - msg #%s\n", taskid, sum, hello_msg);
   pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
   pthread_t threads[NUM_THREADS];
   int rc;
   long t;
   int sum = 0;
   int num = 7;
   char messages[NUM_THREADS][7] = {{"tete1\0"},{"Teste2\0"},{"teste3\0"},{"teste4\0"},{"teste5\0"}};

   for(t=0;t<NUM_THREADS;t++){
      sum += num;
      printf("Base cria thread %ld\n", t);
      thread_data_array[t].thread_id = t;
      thread_data_array[t].sum = sum;
      thread_data_array[t].message = messages[t];

      rc = pthread_create(&threads[t], NULL, PrintThread, (void *) &thread_data_array[t]);

      if (rc){
         printf("Falha no retorno pthread_create(), cod.= %d\n", rc);
         exit(-1);
      }
   }

   pthread_exit(NULL);
}
