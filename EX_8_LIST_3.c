#include <stdio.h>
#include<stdlib.h>
#include<string.h>

void sub_strg(char strg[]);

int main(){
    char linha[80], c;
    int i=0;

    printf("digite a frase a ser separada:\n");

	c = getchar();
	while ((c != '\n') && (i < 100)) {
        linha[i++] = c;
		c = getchar();
	}
	linha[i] = '\n';
	linha[i+1] = '\0';

    sub_strg(linha);

return 0;
}

void sub_strg(char strg[]){
    char nova_str[40][80];
    int i, j, k = 0, l = 0, ult_esp = 0;



    for (i=0;i<=strlen(strg);i++){
        if(strg[i] == ' ' || strg[i] == '\n'){
            for(j=0;j<i-ult_esp;j++){
                nova_str[k][j] = strg[l++];
            }
            nova_str[k][j] = '\n';
            nova_str[k][j+1] = '\0';
            ult_esp = i+1;
            l = ult_esp;
            k++;
        }

    }
    for(i=0;i<k;i++)
    printf("%s",nova_str[i]);
}