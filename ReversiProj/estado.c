#include <stdio.h>
#include "estado.h"


// exemplo de uma função para imprimir o estado (Tabuleiro)
void printa(ESTADO e)
{
    char c = ' ';
    int contaX = 0, contaO = 0;
    printf("  1 2 3 4 5 6 7 8\n");
    for (int i = 0; i < 8; i++) {
        printf("%d ",i+1);
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
    printf("\n#X = %d   #O = %d\n",contaX,contaO);

}

void poepeca (ESTADO *e,int x, int y){
    e->grelha[x][y] = e->peca;
}

void joga (ESTADO *e, int x, int y){
    int c=y,l=x;
    VALOR p;
    if (e->peca == VALOR_X) p = VALOR_O; // p -> peça contrária
    else p = VALOR_X;

    // modificar para a direita--------------------------
    while (e->grelha[l][c+1] == p && c < 8) c++;
    if (c==8);
    else if (e->grelha[l][c+1] == e->peca) for(;c!=y;c--) e->grelha[l][c] = e->peca;
    else;
    //----------------------------------------------------
    c=y,l=x;

    // modificar para a esquerda-------------------------
    while (e->grelha[l][c-1] == p && c > 0) c--;
    if (c==0);
    else if (e->grelha[l][c-1] == e->peca) for (;c!=y;c++) e->grelha[l][c] = e->peca;
    else;
    //-----------------------------------------------------
    c=y,l=x;

    // modificar para baixo--------------------------------
    while (e->grelha[l+1][c] == p && l < 8) l++;
    if (l == 8);
    else if (e->grelha[l+1][c] == e->peca) for (;l!=x;l--) e->grelha[l][c] = e->peca;
    else;
    //-----------------------------------------------------
    c=y,l=x;

    // modificar para cima
    while (e->grelha[l-1][c] == p && l > 0) l--;
    if (l == 0);
    else if (e->grelha[l-1][c] == e->peca) for (;l!=x;l++) e->grelha[l][c] = e->peca;
    else;
    //-----------------------------------------------------
    c=y,l=x;

    // modificar cima direita
    while (e->grelha[l-1][c+1] == p && c < 8 && l > 0) {
        l--;
        c++;
    }
    if (l == 0 || c == 8 );
    else if (e->grelha[l-1][c+1] == e->peca) for (;l!=x;l++,c--) e->grelha[l][c] = e->peca;
    else;
    //-----------------------------------------------------
    c=y,l=x;

    // modificar cima esquerda
    while (e->grelha[l-1][c-1] == p && c > 0 && l > 0) {
        l--;
        c--;
    }
    if (l == 0 || c == 0 );
    else if (e->grelha[l-1][c-1] == e->peca) for (;l!=x;l++,c++) e->grelha[l][c] = e->peca;
    else;
    //-----------------------------------------------------
    c=y,l=x;

    // modificar baixo esquerda
    while (e->grelha[l+1][c-1] == p && c > 0 && l < 8) {
        l++;
        c--;
    }
    if (l == 8 || c == 0 );
    else if (e->grelha[l+1][c-1] == e->peca) for (;l!=x;c++,l--) e->grelha[l][c] = e->peca;
    else;
    //-----------------------------------------------------
    c=y,l=x;

    // modificar baixo direita
    while (e->grelha[l+1][c+1] == p && c < 8 && l < 8) {
        l++;
        c++;
    }
    if (l == 8 || c == 8 );
    else if (e->grelha[l+1][c+1] == e->peca) for (;l!=x;l--,c--) e->grelha[l][c] = e->peca;
    else;
    //-----------------------------------------------------
}

int verificajogada (ESTADO *e, int x, int y) {
    int flag = 0;
    if (e->grelha[x][y] != VAZIA);
    else {
        int l = x, c = y;
        VALOR p;
        if (e->peca == VALOR_X) p = VALOR_O; // p -> peça contrária
        else p = VALOR_X;

        //direita
        if (e->grelha[x][y + 1] == p) {
            while (e->grelha[l][c + 1] == p && c < 8) c++;
            if (e->grelha[l][c + 1] == e->peca && c < 8) flag = 1;
        }
        l = x, c = y;

        //esquerda
        if (e->grelha[x][y - 1] == p && flag == 0) {
            while (e->grelha[l][c - 1] == p && c > 0) c--;
            if (e->grelha[l][c - 1] == e->peca && c > 0) flag = 1;
        }
        l = x, c = y;

        //cima
        if (e->grelha[x - 1][y] == p && flag == 0) {
            while (e->grelha[l - 1][c] == p && l > 0) l--;
            if (e->grelha[l - 1][c] == e->peca && l > 0) flag = 1;
        }
        l = x, c = y;

        //baixo
        if (e->grelha[x + 1][y] == p && flag == 0) {
            while (e->grelha[l + 1][c] == p && l < 8) l++;
            if (e->grelha[l + 1][c] == e->peca && l < 8) flag = 1;
        }
        l = x, c = y;

        //cima direita
        if (e->grelha[x - 1][y + 1] == p && flag == 0) {
            while (e->grelha[l - 1][c + 1] == p && l > 0 && c < 8) {
                l--;
                c++;
            }
            if (e->grelha[l - 1][c + 1] == e->peca && l > 0 && c < 8) flag = 1;
        }
        l = x, c = y;

        //baixo direita
        if (e->grelha[x + 1][y + 1] == p && flag == 0) {
            while (e->grelha[l + 1][c + 1] == p && l < 8 && c < 8) {
                l++;
                c++;
            }
            if (e->grelha[l + 1][c + 1] == e->peca && l < 8 && c < 8) flag = 1;
        }
        l = x, c = y;

        //baixo esquerda
        if (e->grelha[x + 1][y - 1] == p && flag == 0) {
            while (e->grelha[l + 1][c - 1] == p && l < 8 && c > 0) {
                l++;
                c--;
            }
            if (e->grelha[l + 1][c - 1] == e->peca && l < 8 && c > 0) flag = 1;
        }
        l = x, c = y;

        //cima esquerda
        if (e->grelha[x - 1][y - 1] == p && flag == 0) {
            while (e->grelha[l - 1][c - 1] == p && l > 0 && c > 0) {
                l--;
                c--;
            }
            if (e->grelha[l - 1][c - 1] == e->peca && l > 0 && c > 0) flag = 1;
        }
    }

    return flag;
}


