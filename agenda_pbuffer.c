#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct cel {
	char nome_completo[100];
	unsigned long int fone;
	struct cel *prox;
}celula;

typedef struct variav {
    char nome_rem[100]; //// nome a ser removido
    char nome_pesq[100]; //// nome a ser encontrado
    int escolha;        //// Menu
    int c;              //// Menu
}variaveis;

variaveis *controle;

void *pBuffer;

celula *cria(void);
int menu(void);
void insere(celula * p);
void lista(celula *ini);
void remova(char nome_remove[], celula * ini);
void remocao(celula *ini);
void pesquisa(celula *ini);
void encontra(char nome_pesq[], celula *ini);
int free_all(celula *ini);

int main(){

    pBuffer = malloc(sizeof(variaveis));
    	if(!pBuffer){
		    return -1;
	    }
    controle = pBuffer;

    celula *ini;
	ini = cria();

    	for (;;) {
		controle->escolha = menu();
		switch (controle->escolha) {
		case 1:
			insere(ini);
			break;
		case 2:
			remocao(ini);
			break;
		case 3:
			pesquisa(ini);
			break;
		case 4:
			lista(ini);
			break;
		case 5:
        free(pBuffer);
        //free_all(ini); /// da erro de leitura ... ele tenta da free em algo q ja foi free.... 
        free(ini);
			return 0;
		}
	}
    return 0;
}

celula *cria(void)
{
	celula *start;

	start = (celula *) malloc(sizeof(celula));
	start->prox = NULL;
	return start;
}

int menu(void)
{
	controle->c = 0;
	do {
		printf("-- MENU:\n");
		printf("\t 1. Cadastrar uma novo contato\n");
		printf("\t 2. Excluir uma contato\n");
		printf("\t 3. Pesquisar por nome\n");
		printf("\t 4. Listar todos contatos\n");
		printf("\t 5. Sair\n");
		printf("-- Digite sua escolha: ");
		scanf("%d", &controle->c);
	} while (controle->c <= 0 || controle->c > 6);
	getchar();
	return controle->c;
}

void insere(celula * p)
{
		celula *nova;
		nova = (celula *) malloc(sizeof(celula));
		printf("Nome: ");
		scanf("%[^\n]s",nova->nome_completo);
		getchar();
		printf("\n");
		printf("Telefone:(123456789) ");
		scanf("%lu",&nova->fone);
		getchar();
		nova->prox = p->prox;
		p->prox = nova;
        free(nova);
}

void lista(celula *ini){
	celula *q;

	q = ini->prox;
	while (q != NULL){
		if ((q != NULL)){
			printf("Nome: %s\n",q->nome_completo);
			printf("Telefone: %lu\n",q->fone);
		}
	q = q->prox;
	}
}

void remocao(celula *ini){
	
	printf("Nome do contato a ser remnovido:\n ");
	printf("\t Nome: ");
	scanf("%[^\n]s",controle->nome_rem);
	getchar();
	printf("\n");

	remova(controle->nome_rem, ini);
}

void remova(char nome_remove[], celula * ini){
	celula *p, *q;
	p = ini;
	q = ini->prox;
	while ((q != NULL) && (strcmp(q->nome_completo,nome_remove) != 0)){
		p = q;
		q = q->prox;
	}
	if (q != NULL) {
		p->prox = q->prox;
		free(q);
	}
}

void pesquisa(celula *ini){
	
	printf("Nome da pessoa a ser pepsquisada:\n ");
	printf("\t Nome: ");
	scanf("%[^\n]s",controle->nome_pesq);
	getchar();
	printf("\n");

	encontra(controle->nome_pesq, ini);
}

void encontra(char nome_pesq[], celula *ini){
	celula *q;
	q = ini->prox;
	while (q != NULL){
		if ((q != NULL) && (strcmp(q->nome_completo,nome_pesq) == 0)){
			
			printf("Nome: %s\n",q->nome_completo);
			printf("Telefone: %lu\n",q->fone);
		}
	q = q->prox;
	}
}

int free_all(celula *ini){
	celula *q;
    q = ini->prox;
    while (q != NULL)
        while (q != NULL){
            free(q);
            q = ini->prox;}

    return 0;
}