#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int data[10] = {4,5,67,34,2,87,54,6,77,63};

void SomaVetor(void)
{
   long soma = 0;
   int i;

   for (i=0; i<10; i++){
      soma += data[i];
   }

   printf("A soma dos valores do vetor é %ld\n", soma);
}

void *SomaThread(void *tid)
{
   long id = (long) tid;

   printf("Thread Soma id: %ld\n", id);

   SomaVetor();   

   pthread_exit(NULL);
}

void *MaiorThread(void *tid)
{
   int i;
   int maior = 0;
   long id = (long) tid;

   printf("Thread Maior id: %ld\n", id);
   
   for(i=0;i<10;i++){
      if(maior < data[i]){
         maior = data[i];
      }
   }

   printf("O maior número encontrado foi %d\n",maior);

   pthread_exit(NULL);
}


int main(int argc, char *argv[])
{
   pthread_t thread_soma;
   pthread_t thread_maior;
   int rc;

   rc = pthread_create(&thread_soma, NULL, SomaThread, (void *) &thread_soma);

   if(rc){
      printf("Falha em pthread_soma, pthread_create(), cod: %d\n",rc);
      exit(-1);
   } 

   rc = pthread_create(&thread_maior, NULL, MaiorThread, (void *) &thread_maior);

   if(rc){
      printf("Falha em pthread_maior, pthread_create(), cod: %d\n",rc);
      exit(-1);
   }

   pthread_exit(NULL);
}
