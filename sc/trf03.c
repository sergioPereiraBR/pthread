#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void TaskThread(char *str){
   printf("%s, sua thread foi Criada com sucesso!\n", str);
}

void *PrintThread(void *id)
{
   long idt;
   idt = (long) id;
   char nome[30];

   printf("Thread %ld\n", idt+1);

   printf("Digite seu nome: ");

   scanf("%s",nome);
   TaskThread(nome);
   pthread_exit(NULL);
}

void CallThread(long nt, pthread_t *t){
   int rc;
   rc = pthread_create(t, NULL, PrintThread, (void *) nt);

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
            CallThread(i, &threads[i]);
            pthread_join(threads[i],NULL);
            break;
         case 2:
            exit(0);
            break;
      }
   }
   pthread_exit(NULL);                                                                                }


