#include <stdio.h>
#include <stdlib.h>

void allocVet (int *vet, int *size, int *capacity);
int lerVet (int *vet, int *size);

int main(){
     int size = 0, i=0;
     int capacity = 1;
     int *vet = malloc(capacity* sizeof(int));

     printf("qual o tamanho do vetor?\n");

     scanf("%d",&size);

     allocVet(vet, &size, &capacity);
   
     lerVet(vet,&size);

     for(i=0;i<size;i++)
          printf("valor vetor[%d]: %d\n",i+1,vet[i]);
     
     free(vet);
}

void allocVet(int *vet, int *size, int *capacity){
     int newSize = *size;
     int *newVet;
     if(*size > *capacity){
          newVet = realloc(vet, sizeof(vet) * newSize);
          *capacity = sizeof(vet) * newSize;
     }
}

int lerVet(int *vet, int *size){
     int i;

     for(i=0;i < *size;i++){
          printf("qual o valor da possiçao %d\n",i+1);
          scanf("%d",&vet[i]);
     }

     return vet[0];
}