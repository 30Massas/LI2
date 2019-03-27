#include <stdio.h>
#include "estado.h"
#include <string.h>
#include "ctype.h"
int main()
{
    char c1, c2;
    char linha[50];
    int x,y;
    ESTADO e;
    do {
        gets(linha);
        switch (toupper(linha[0])){
            case 'N' : {
                sscanf(linha,"%c %c", &c1 , &c2);
                e.peca = c2;
                break;
            }
            case 'J' : {
                sscanf(linha,"%c %d %d", &c1, &x ,&y);
                e.peca = c1;
                break;
            }

        }









    }while (toupper(linha[0] != 'Q'));
}



/*{
    char mdj;
    ESTADO e = {0};
    printf("Insira o modo de jogo \n0-> manual, 1-> contra computador\n");
    scanf("%c",&mdj);
    e.modo = mdj;
    e.peca = VALOR_X;

    // estado inicial do tabuleiro. Inicio do jogo!
    e.grelha[3][4] = VALOR_X;
    e.grelha[4][3] = VALOR_X;
    e.grelha[3][3] = VALOR_O;
    e.grelha[4][4] = VALOR_O;


    //e.grelha[2][2] = VALOR_X;


    printf("\n");
    printa(e);
    printf("\n");

    return 0;
}
 */