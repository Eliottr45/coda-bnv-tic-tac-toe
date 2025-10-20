#ifndef __TICTACTOE_H__
#define __TICTACTOE_H__

//int opposent_placement(char*tab);
//find_chain(char*tableau);
void construct_grid(char ** grille);
int used(char** grille, int input, int id_joueur);
void complete(char ** grille, int reponse, int id_joueur);
void print_grid(char**grille);
int bot(char** tableau, int id);
void verification(char** grille, char symbole);
int est_pleine(char ** grille);
void game(char**grille);
#endif