#include <stdio.h>
#include "estado.h"


// exemplo de uma função para imprimir o estado (Tabuleiro)
void printa(ESTADO e)
{
    char c = ' ';
    int contaX = 0, contaO = 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            switch (e.grelha[i][j]) {
                case VALOR_O: {
                    c = 'O';
                    contaO ++;
                    break;
                }
                case VALOR_X: {
                    c = 'X';
                    contaX ++;
                    break;
                }
                case VAZIA: {
                    c = '-';
                    break;
                }
            }
            printf("%c ", c);

        }
        printf("\n");
    }
    printf("#X = %d   #O = %d",contaX,contaO);

}


ESTADO joga (ESTADO e, int x, int y){
    int c=y,l=x;
    char p;
    if (e.peca == 'X') p = 'O'; // p -> peça contrária
    else p = 'X';
    // modificar para a direita--------------------------
    while (e.grelha[l][c] == p && c < 8) c++;
    if (c==8);
    else for(;c!=y;c--) e.grelha[l][c] = e.peca;

    //----------------------------------------------------
    // modificar para a esquerda-------------------------
    while (e.grelha[l][c] == p && c > 0) c--;
    if (c==0);
    else for (;c!=y;c++) e.grelha[l][c] = e.peca;

    //-----------------------------------------------------
    // modificar para baixo--------------------------------
    while (e.grelha[l][c] == p && l < 8) l++;
    if (l == 8);
    else for (;l!=x;l++) e.grelha[l][c] = e.peca;
    //-----------------------------------------------------
    // modificar para cima
    while (e.grelha[l][c] == p && l > 0) l--;
    if (l == 0);
    else for (;l!=x;l--) e.grelha[l][c] = e.peca;

    //-----------------------------------------------------
    // modificar cima direita
    while (e.grelha[l][c] == p && c < 8 && l > 0) {
        l--;
        c++;
    }
    if (l == 0 || c == 8 );
    else for (;l!=x;l++,c--) e.grelha[l][c] = e.peca;
    //-----------------------------------------------------
    // modificar cima esquerda
    while (e.grelha[l][c] == p && c > 0 && l > 0) {
        l--;
        c--;
    }
    if (l == 0 || c == 0 );
    else for (;l!=x;l++,c++) e.grelha[l][c] = e.peca;
    //-----------------------------------------------------
    // modificar baixo esquerda
    while (e.grelha[l][c] == p && c > 0 && l < 8) {
        l++;
        c--;
    }
    if (l == 8 || c == 0 );
    else for (;l!=x;c++,l--) e.grelha[l][c] = e.peca;
    //-----------------------------------------------------
    // modificar baixo direita
    while (e.grelha[l][c] == p && c < 8 && l < 8) {
        l++;
        c++;
    }
    if (l == 8 || c == 8 );
    else for (;l!=x;l--,c--) e.grelha[l][c] = e.peca;
    //-----------------------------------------------------
}