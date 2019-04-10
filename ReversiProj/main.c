#include <stdio.h>
#include "estado.h"
#include <string.h>
#include "ctype.h"
int main() {
    char c1, c2;
    char linha[50];
    int x, y;
    int jogador = 0;
    int contaX,contaO;
    ESTADO *e = malloc(sizeof(struct estado));
    e->modo = 0;
    e->peca = VAZIA;
    // estado inicial do tabuleiro. Inicio do jogo!
    e->grelha[3][4] = VALOR_X;
    e->grelha[4][3] = VALOR_X;
    e->grelha[3][3] = VALOR_O;
    e->grelha[4][4] = VALOR_O;
    e->ant = NULL;


        do {
            if (e->peca == VAZIA) printf("Reversi ? => ");
            else if (e->peca == VALOR_O) printf("Reversi O => ");
            else printf("Reversi X => ");

            fgets(linha, 50, stdin);
            // scanf("%s",linha);
            switch (toupper(linha[0])) {
                case '?' :
                    {
                        printf("N <peca> // novo jogo em que o primeiro a jogar é o jogador com peça\n");
                        printf("L <ficheiro> // ler um jogo de ficheiro\n");
                        printf("E <ficheiro> // Guardar jogo\n");
                        printf("J <L> <C> // Jogar [linha] [coluna]\n");
                        printf("S // Colocar pontos nos locais de jogada válida\n");
                        printf("P // Imprimir estado do jogo\n");
                        printf("H // Dar sugestão de jogada\n");
                        printf("U // Desfazer jogada anterior\n");
                        break;
                }
                case 'N' :
                    { // cria novo jogo
                    novoEstado(e,linha);
                    break;
                }
                case 'E' :
                    {
                    guardajogo(e, linha);
                    break;
                }
                case 'J' : {
                    if (e->peca != VAZIA) {
                        sscanf(linha, "%c %d %d", &c1, &x, &y);
                        if (verificajogada(e, x - 1, y - 1)) {

                            // fase teste
                            ESTADO *aux = malloc(sizeof(struct estado));

                            copyEstado (e,aux);
                            aux->ant = e;
                            e = aux;

                            joga(e, x - 1, y - 1);
                            poepeca(e, x - 1, y - 1);
                            printa(*e,&contaX,&contaO);
                            printf("\n#X = %d   #O = %d\n",contaX,contaO);
                            if (e->peca == VALOR_O) e->peca = VALOR_X;
                            else e->peca = VALOR_O;
                        }
                        else printf("Jogada inválida. Introduza uma jgoada válida.\n");
                    }
                    break;
                }
                case 'P' :
                    {
                    printa(*e,&contaX,&contaO);
                    printf("\n#X = %d   #O = %d\n",contaX,contaO);
                    break;
                }
                case 'S' :
                    { // coloca pontos nos sítios de jogadas válidas
                    whereCanIPut(e);
                    break;
                }
                case 'U' : { // desfaz a jogada anterior
                    if (e->ant == NULL);
                    else {
                        ESTADO *aux;
                        aux = e;
                        e = e->ant;
                        free(aux);
                    }
                    break;
                }
                case 'H' :
                    { // coloca pontos de interrogação em locais sugeridos para jogar
                    giveHint(e);
                    break;
                }
                case 'L' :
                    {
                    readGame(e,linha);
                    break;
                }
            }
        } while (toupper(linha[0] != 'Q'));
    }
