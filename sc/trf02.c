#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void TaskThread(void){
   printf("Thread Criada com sucesso!\n");
}

void *PrintThread(void *id)
{
   long idt;
   idt = (long) id;

   printf("Thread %ld\n", idt+1);
   TaskThread();
   pthread_exit(NULL);
}

void CallThread(long nt, pthread_t *t){
   int rc;
   printf("call p01\n");
   rc = pthread_create(&t, NULL, PrintThread, (void *) nt);
   printf("call p02\n"); 
   if(rc){
      printf("\nFalha ao criar Thrade %ld, cod: %d\n", nt, rc);
      exit(-1);
   }
}

int main(int argc, char *argv[])
{
   int h = 0;
   long i;
   
   pthread_t *threads;
 
   for(;;){

      printf("\n\nDeseja criar uma nova Thread?\n");
      printf("0-Sim 1-Não 2-Sair\n\nOpção: ");

      scanf("%d", &h);

      switch (h){
         case 0:
            i++;
            threads = (pthread_t *) malloc(sizeof(pthread_t) *i);
            printf("p01\n");
            CallThread(i, &threads);
            printf("p02\n");
            pthread_join(&threads,NULL);
            printf("p03\n");
            break;
         case 2:
            exit(0);
            break;
      }
   }
   pthread_exit(NULL);

}

