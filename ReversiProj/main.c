#include <stdio.h>
#include "estado.h"
#include <string.h>
#include "ctype.h"
int main() {
    char c1, c2;
    char linha[50];
    int x, y;
    char mdj;
    int jogador = 0;

    //printf("Insira o modo de jogo \n0-> manual, 1-> contra computador, outra-> abrir jogo\n");
   // scanf("%c", &mdj);
    ESTADO
    e = {0};
    e.modo = mdj;
        // estado inicial do tabuleiro. Inicio do jogo!
        e.grelha[3][4] = VALOR_X;
        e.grelha[4][3] = VALOR_X;
        e.grelha[3][3] = VALOR_O;
        e.grelha[4][4] = VALOR_O;

        do {
            if (jogador%2 == 0) {
                printf("Jogador X:\n=>");
                e.peca = VALOR_X;
            }
            else {
                printf("Jogador O:\n=>");
                e.peca = VALOR_O;
            }

            fgets(linha,50,stdin);
            // scanf("%s",linha);
            switch (toupper(linha[0])) {
                case '?' : {
                    printf("J x y // Jogar [linha] [coluna]\nT // Obter uma dica\n //");
                    break;
                }
                case 'J' : {
                    sscanf(linha, "%c %d %d", &c1, &x, &y);
                    if (verificajogada(&e,x-1,y-1)) {
                        joga(&e, x - 1, y - 1);
                        poepeca(&e, x - 1, y - 1);
                        printa(e);
                        jogador ++;
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

   // else if (mdj == '1');


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