#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int ** criaMatriz(int m, int n);
void leiaMatriz(int **mat, int m, int n);
int somaMatriz(int **mat, int m, int n);
int* colunaMatriz(int ** mat, int m, int n, int ncoluna);
void liberaMatriz(int **mat, int ncoluna, int m);
void imprimeMatriz(int **mat, int m, int n);
void imprimeVetor (int *vet, int m);

int main(){
    int m, n,i, soma_tot, ncoluna;
    int **main_mtrz, *coluna;

    printf("Qual o numero desejado de linhas e colunas?\n");
    printf("linhas:");
    scanf("%d",&m);
    printf("\ncollunas:");
    scanf("%d",&n);
    printf("\n");

    main_mtrz = criaMatriz(m,n); // m == linha / n == coluna

    leiaMatriz(main_mtrz, m, n);

    soma_tot = somaMatriz(main_mtrz, m, n);
    printf("\nA soma de todos os elementos da matriz eh: %d\n",soma_tot);

    printf("voce dejeza receber os valores de uma coluna especifica? (1=sim 2=nao)\n");
        scanf("%d",&i);
        if(i==1){
        printf("qual coluna?:");
        scanf("%d",&ncoluna);
        ncoluna = ncoluna - 1;
        coluna = colunaMatriz(main_mtrz, m, n, ncoluna);
        printf("\n");
        imprimeVetor (coluna, m);
        free(coluna);
        printf("\n");
        }

    printf("voce dejeza imprimir todos os valores dessa matriz? (1=sim 2=nao)\n");
        scanf("%d",&i);
        if(i==1){
            imprimeMatriz(main_mtrz, m, n);
            printf("\n");
        }

    printf("voce dejeza apagar os valores de uma coluna especifica? (1=sim 2=nao)\n");
        scanf("%d",&i);
        if(i==1){
            printf("qual coluna?:");
            scanf("%d",&ncoluna);
            liberaMatriz(main_mtrz, ncoluna, m); // eu add m na funçao
        }else{
            for(i=0; i<m; i++)
                free(main_mtrz[i]);
            free(main_mtrz);
    }
return 0;
}

int ** criaMatriz(int m, int n){
    int **main_mtrz_creation;
    int i;

    main_mtrz_creation = (int **)malloc(m*sizeof(int *));
        for(i=0; i<m; i++)
            main_mtrz_creation[i] = (int *)malloc(n*sizeof(int));
    
    return main_mtrz_creation;
}

void leiaMatriz(int **mat, int m, int n){
   int i, j;

   for(i=0; i<m; i++){
       for(j=0; j<n; j++){
           printf("\nvalor na linha %d e coluna %d:",i+1,j+1);
           scanf("%d",&mat[i][j]); 
       }
   }
}

int somaMatriz(int **mat, int m, int n){
    int soma = 0, i, j;

    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            soma = soma + mat[i][j];
        }
   }
    return soma;
}

int* colunaMatriz(int ** mat, int m, int n, int ncoluna){
    int *coluna,i;

        coluna = (int *)malloc(n*sizeof(int));

        for(i=0; i<m; i++){
            coluna[i] = mat[i][ncoluna];
        }

    return coluna;
}

void liberaMatriz(int **mat, int ncoluna,int m){
    int i;
    for(i=0; i<m; i++)
        free(mat[i]);
    free(mat);
}

void imprimeMatriz(int **mat, int m, int n){
    int i,j;
    
    for(i=0;i<m;i++){
        printf("\n");
        for(j=0;j<n;j++){
            printf("%d ",mat[i][j]);
        }
    }
}

void imprimeVetor (int *vet, int m) {
    int i;
        for(i=0;i<m;i++){
            printf("%d ",vet[i]);
        }

}