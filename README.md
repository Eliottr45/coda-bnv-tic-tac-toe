# coda-bnv-tic-tac-toe

void construct_grid(char **grille):

    Fonction permettant de construire les variable qui constituent les "cases" du jeu.

int used(char** grille, int input):

    Fonction qui permet de vérifier si la case sur laquelle on veut placer notre pion est libre ou non. On vérifie si input est unre case prise dans grille.

void complete(char ** grille, int input, int id_joueur):

    Fonction remplissant la grille avec le symbole de id_joueur a la case input.

void print_grid(char**grille):

    Fonction qui affiche la grille et son contenu.

int bot(char** grille, int id):

    Fonction qui choisi aleatoirement une case de la grille parmi celle disponible.

int verification(char** grille, char camp):

    Fonction qui vérifie si une succecion de trois symbole est présente dans la grille.

int est_pleine(char ** grille):

    Fonction qui vérifie si la grille est pleine.

void game(char**grille):

    Fonction qui execute les fonction précédentes permettants a l'utilisateuyr de jouer au morpion contre un ordinateur.