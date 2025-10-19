#include <stdio.h>
#include <stdlib.h>
#include "tictactoe.h"

int main()
{
    int i = 0;

    // allocation de la memoire pourr creation d'un doublee tableau
    char ** grille = malloc(4*sizeof(*grille));
    grille[0] = malloc(4*sizeof(**grille)); //allocation de 8 cases car  affichage == O-|-X-|-O (| --> pas compté dans le tableau/ structure tableau)
    grille[1] = malloc(4*sizeof(**grille));
    grille[2] = malloc(4*sizeof(**grille));
    grille[3] = NULL;

    game(grille);
    free(grille);
}