#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>


void TaskClean(void){
   system("clear");
}

void TaskNome(void){
   char nome[30];
   printf("\n\nNome: ");
   scanf("%s",nome);
   printf("\n\n%s, sua thread foi Criada com sucesso!\n", nome);
}

void TaskOla(void){
   printf("\n\n\nOlá!\n\n\n");
}

void TaskId(long id){
   printf("\n\nId %ld da thread criada.\n\n", id);
}

void *PrintThread(void *id)
{
   long idt;
   idt = (long) id;
   char nome[30];
   int i=0;

   while (i<1 || i>4){
      printf("Selecione um serviço:\n\n");
      printf("1 - Limpar a tela;\n");
      printf("2 - Digitar seu nome;\n");
      printf("3 - Receber um Olá;\n");
      printf("4 - Saber id da thread.\n\n");
      printf("Opção: ");
      scanf("%d",&i);

      switch (i){
         case 1:
            TaskClean();
         break;
         case 2:
            TaskNome();
         break;
         case 3:
            TaskOla();
         break;
         case 4:
            TaskId(idt);
         break;
      }
   }
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
   pthread_exit(NULL);
}
