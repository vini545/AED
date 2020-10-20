#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void * realloc_MOD(void *pont, size_t newSize,int oldSize);
  
int main(){
    char *p;
    int size_old;
    //tamnho original aqui....V /// se o tamnho é o mesmo da quantidade de char desejada (oi == 2) o Dr.memory aponta erro de leitura e escurita nas linhas 21 e 23.
    p = malloc(sizeof(char) * 3);
    	if (!p){
		    printf("ERRO: Falta de memoria");
		return -1;
	}
    ///////////////test para saber tamanho de p
    size_old = _msize(p);
    printf("Tamnho de p é %d\n",size_old);
    //////////////fim test

    strcpy(p,"oi"); // test

    printf("%s\n",p);
    // escolher novo tamanho aqui......VV
    p = realloc_MOD( p, sizeof(char) * 13, size_old); // 12 char no total e um espaço extra // só envia o valor 13//apos quebra a cabeça sem saber o motivo
        if (!p){                                                                                          //uma breve pesquisa revelou que (char == 1 byte) 1 * 13 == 13
		    printf("ERRO: Falta de memoria");                                                             //.... as vezes a gente esquece o basico :/ 
		return -1;
	}

    ///////////////test para saber tamanho de p
    size_old = _msize(p);
    printf("Novo tamnho de p é %d\n",size_old);
    //////////////fim test

    strcpy(p,"oi,tudo bem"); // test
    printf("%s\n",p);

    free(p);
    return 0;
}

void * realloc_MOD(void *pont, size_t newSize,int oldSize){
    void *palavra;

    if (newSize == 0){
        printf("Novo tamnho é zero, ponteiro liberado!\n");
    return NULL;
    }
    else if (!pont){
        printf("O ponteiro entrado é nulo e agora foi alocado com o valor desejado\n");
        return palavra = malloc(newSize);
    }
    else if (newSize <= oldSize){
        printf("Novo valor é menor que o atual, conteudo apagado e ponteiro re-alocado\n");
        pont = malloc(oldSize);
        return pont;
    }
    else{
        palavra = malloc(newSize);
            if (!palavra){
                printf("ERRO FALTA MEMORIA");
            }
        memcpy (palavra,pont, oldSize);
        free(pont);
    return palavra;
    }
}
