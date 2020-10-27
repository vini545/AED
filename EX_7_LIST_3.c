#include <stdio.h>

int ret_rep(int *vetor, int tam); // retira repetido

int main(){
    int n, i;

    printf("quantos numeros serao escritos?: ");
    scanf("%d",&n);
    
    int vet[n], *pont_vet;

    for(i=0;i<n;i++){
        printf("entre o valor na posiçao %d: ",i+1);
        scanf("%d",&vet[i]);
    }
    pont_vet = vet;

    n = ret_rep(pont_vet, n);

    for(i=0;i<n;i++){
    printf("\nNovo vet[%d]: %d ",i+1,*(pont_vet+i)); 
    }


return 0;
}

int ret_rep(int *vetor, int tam){
    int nov_tam, dup, i, j, cont_nun_ret=0;

    for(i=0;i<tam-cont_nun_ret;i++){
        dup = vetor[i];
        j=i+1;
        if(dup == vetor[j]){
            cont_nun_ret++;
            for(;j<tam;j++){
                if(j+1 < tam){
                    vetor[j] = vetor[j+1];
                }
            }
        }
    }
    nov_tam = tam - cont_nun_ret;
    return nov_tam;
}