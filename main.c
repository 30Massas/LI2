#include <stdio.h>
#include "estado.h"
#include <string.h>
#include "ctype.h"
int main() {
    char c1, c2;
    char linha[50];
    int x, y;
    char mdj;
    printf("Insira o modo de jogo \n0-> manual, 1-> contra computador, outra-> abrir jogo\n");
    scanf("%c", &mdj);
    ESTADO
    e = {0};
    e.modo = mdj;
    if (mdj == '0') {
        // estado inicial do tabuleiro. Inicio do jogo!
        e.grelha[3][4] = VALOR_X;
        e.grelha[4][3] = VALOR_X;
        e.grelha[3][3] = VALOR_O;
        e.grelha[4][4] = VALOR_O;

        do {
            gets(linha);
            switch (toupper(linha[0])) {
                case 'N' : {
                    sscanf(linha, "%c %c", &c1, &c2);
                    e.peca = c2;
                    break;
                }
                case 'J' : {
                    sscanf(linha, "%c %c %d %d", &c1, &c2, &x, &y);
                    if (toupper(c2) == 'X') e.peca = VALOR_X;
                    else e.peca = VALOR_O;
                    if (verificajogada(&e,x-1,y-1)) {
                        joga(&e, x - 1, y - 1);
                        poepeca(&e, x - 1, y - 1);
                        printa(e);
                    }
                    else printf("introduza uma jogada válida\n");
                    break;
                }
                case 'P' : {
                    printa(e);
                    break;
                }

            }


        } while (toupper(linha[0] != 'Q'));
    }
   // else if (mdj == '1');
    else ;

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


    return 0;
}
 */