#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct cel {
	char nome_completo[100];
	char idade[3];
	char altura[12];
	struct cel *prox;
}celula;

int menu(void);
void insere(celula * p);
void ler_string(char palavra[100], int tamanho);
void imprime(celula * ini);
celula *cria(void);

int main()
{
	int escolha;
	celula *ini;
	ini = cria();
	
	for (;;) {
		escolha = menu();
		switch (escolha) {
		case 1:
			insere(ini);
			break;
		case 2:
			imprime(ini);
			break;
		case 3:
        free(ini);
			return 0;
			break;
		}
    }

	return 0;
}

celula *cria(void)
{
	celula *start;

	start = (celula *) malloc(sizeof(celula));
    if(!start){
        printf("\nERRO FALTA MEMORIA\n");
    }
	start->prox = NULL;
	return start;
}

int menu(void)
{
	int c = 0;
	do {
		printf("-- MENU:\n");
		printf("\t 1. Cadastrar uma nova pessoa\n");
        printf("\t 2. listar todos os nomes\n");
		printf("\t 3. Sair\n");
		printf("-- Digite sua escolha: ");
		scanf("%d", &c);
	} while (c <= 0 || c > 3);
	getchar();
	return c;
}

void insere(celula * p)
{
		celula *nova;

		nova = (celula *) malloc(sizeof(celula));
        if(!nova){
            printf("\nERRO FALTA MEMORIA\n");
        }
		printf("Nome: ");
		ler_string(nova->nome_completo,100);
		printf("\n");
		printf("Idade: ");
        ler_string(nova->idade,2);
		printf("\n");
		printf("altua: ");
		ler_string(nova->altura,9);
		printf("\n");
		nova->prox = p->prox;
		p->prox = nova;
}

void ler_string(char palavra[100], int tamanho)
{
	int i = 0;
	char c;

	c = getchar();
	while ((c != '\n') && (i < tamanho)) {
		palavra[i++] = c;
		c = getchar();
	}
	palavra[i] = '\0';

	if (c != '\n') {
		c = getchar();
		while ((c != '\n') && (c != EOF)) {
			c = getchar();
		}
	}
}

void imprime(celula * ini)
{
	celula *p;
	for (p = ini->prox; p != NULL; p = p->prox){
		printf("Nome: %s\n", p->nome_completo);
		printf("Altura: %s\n", p->altura);
		printf("Idade: %s\n", p->idade);
	}
}