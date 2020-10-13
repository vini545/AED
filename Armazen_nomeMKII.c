#include<stdio.h>
#include<stdlib.h>
#include<string.h>


char *add_nome(int primeira_vez, char *main_str);
char *sub_nome(char *main_str);
int menu(void);

int main(){
    int primeiro = 0, i = 0;
	int escolha;
	char *main_str;
	
	for (;;) {
		escolha = menu();
		switch (escolha) {
		case 1:
			main_str = add_nome(primeiro,main_str);
            primeiro++;
			break;
		case 2:
            if (primeiro == 0){
                printf("Nao ha nomes na string\n");    
            }
            else
                main_str = sub_nome(main_str);

            break;
		case 3:
            printf("%s", main_str);
			break;
		case 4:
			return 0;
			break;
		}
	}
	
}


int menu(void)
{
	int c = 0;
	do {
		printf("-- MENU:\n");
		printf("\t 1. ADD nome\n");
		printf("\t 2. Excluir nome\n");
		printf("\t 3. lista nomes\n");
		printf("\t 4. Sair\n");
		printf("-- Digite sua escolha: ");
		scanf("%d", &c);
	} while (c <= 0 || c > 4);
	getchar();
	return c;
}

char *add_nome(int primeira_vez, char *main_str)
{
	int i = 0;
    char c, *nome;

	nome = malloc(sizeof (char) * 50);
	
	if (!nome){
		printf("ERRO: Falta de memoria");
		return -1;
	}
	
	printf("digite o nome a ser ADD:\n");

	c = getchar();
	while ((c != '\n') && (i < 100)) {
        nome[i++] = c;
		c = getchar();
	}
	nome[i] = '\n';
	nome[i+1] = '\0';

    if(primeira_vez > 0){
        strcat(main_str,nome);
        return main_str;
    }
    main_str = nome;  
	
    return main_str;
}

char *sub_nome(char *main_str){
    char *remover, c, *p, *q, *r; 
    int i = 0, tam = 0;

    remover = malloc(sizeof (char) * 50);

        printf("digite o nome a ser removido:\n");

    c = getchar();
	while ((c != '\n') && (i < 100)) {
        remover[i++] = c;
		c = getchar();
	}
	remover[i] = '\n';
    remover[i+1] = '\0';

    if ((q = r = strstr(main_str, remover)) != NULL) {
        tam = strlen(remover);
        while ((r = strstr(p = r + tam, remover)) != NULL) {
            while (p < r)
                *q++ = *p++;
        }
        while ((*q++ = *p++) != '\0')
            continue;
    }
    return main_str;
}