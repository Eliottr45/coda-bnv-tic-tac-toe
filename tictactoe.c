#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void construct_grid(char **grille)
{
    int i = 0;
    int j = 0;

    while (grille[i] != NULL)
    {
        j = 0;
        while (j < 3)
        {
            grille[i][j] = ' ';
            j++;
        }
        i++;
    }
}

int used(char** grille, int input)
{
    int i = 0;
    int j = 0;
    if(input <= 3)
    {
        i = 0;
        j = (input - 1) % 3;
    }
    else if(input > 3 && input <= 6)
    {
        i = 1;
        j = (input - 1) % 3;
    }
    else
    {
        i = 2;
        j = (input - 1) % 3;
    }

    //condition pour verifier si la case est prise
    if(grille[i][j] == 'X' || grille[i][j] == 'O')
    {
        return(0);
    } 
    return(1);   
}

void complete(char ** grille, int input, int id_joueur)
{
    int i = 0;
    int j = 0;
    if(input <= 3)
    {
        i = 0;
        j = (input - 1) % 3;
    }
    else if(input > 3 && input <= 6)
    {
        i = 1;
        j = (input - 1) % 3;
    }
    else
    {
        i = 2;
        j = (input - 1) % 3;
    }
    if(id_joueur == 1)
    {
        grille[i][j] = 'X';
    }
    else
    {
        grille[i][j] = 'O';
    }
}

void print_grid(char**grille)
{
    int i = 0;

    while (i < 3)
    {
        printf("%c | %c | %c \n", grille[i][0], grille[i][1], grille[i][2]);

        if (i < 2)
            printf("---------\n");

        i++;
    }
    printf("\n");
}

int bot(char** grille)
{
    int pass = 0;
    int random_number;
    while (pass == 0)
    {
        random_number = rand() % 9 + 1;
        pass = used(grille, random_number);
    }
    return(random_number);
}

int verification(char** grille, char camp) 
{
    int i = 0;
    while(i < 3)
    {
    
        if(grille[i][0] == grille[i][1] && grille[i][0] == grille[i][2] && grille[i][0] != ' ')
        {
            if(grille[i][0] == camp)
            {
                return(1);
            }
            else
            {
                return(0);
            }
        }
        i++;
    }
    i = 0;
    while(i < 3)
    {
        if(grille[0][i] == grille[1][i] && grille[0][i] == grille[2][i] && grille[0][i] != ' ' )
        {
            if(grille[0][i] == camp)
            {
                return(1);
            }
            else
            {
                return(0);
            }
        }
        i++;
    }
    if(grille[0][0] == grille[1][1] && grille[0][0] == grille[2][2] && grille[0][0] != ' ' )
        {
            if(grille[0][0] == camp)
            {
                return(1);
            }
            else
            {
                return(0);
            }
        }
    if(grille[0][2] == grille[1][1] && grille[0][2] == grille[2][0] && grille[0][2] != ' ' )
        {
            if(grille[0][2] == camp)
            {
                return(1);
            }
            else
            {
                return(0);
            }
        }
    return(42);
}

int est_pleine(char ** grille)
{
    int i = 0;
    int j = 0;
    int case_rempli = 0;
    while(i < 3)
    {
        while(j < 3)
        {
            if(grille[i][j] == 'O' || grille[i][j] == 'X')
            {
                case_rempli++;
            }
            j++;
        }
        j = 0;
        i++;
    }
    if(case_rempli == 9)
    {
        return(1);
    }
    return(0);
}

void game(char**grille)
{
    srand(time(NULL));
    int choice;
    int resultat_partie = 42;
    char camp;
    int joueur = 1;
    int robot = 0;
    int rep_robot;
    int correct = 0;
    int full = 0;
    printf("Quelle symbole choisissez-vous: O/X ?\n");
    scanf(" %c", &camp);

    if(camp == 'O')
    {
        joueur = 0;
        robot = 1;
    }
    else
    {
        camp = 'X';
    }

    construct_grid(grille);
    print_grid(grille);

    while(resultat_partie == 42)
    {
        while(correct == 0)
        {
            printf("Choisissez une case entre 1 et 9: \n");
            scanf("%d", &choice);
            correct = used(grille,choice);
            if(correct == 0)
            {
                printf("Cette case est déjà prise !\n");
            }
        }
        correct = 0;
        complete(grille, choice, joueur);
        print_grid(grille);
        resultat_partie = verification(grille, camp);
        if(resultat_partie != 42)
        {
            break;
        }
        full = est_pleine(grille);
        if(full == 1)
        {
            printf("Égalité !\n");
            break;
        }
        rep_robot = bot(grille);
        complete(grille, rep_robot, robot);
        resultat_partie = verification(grille, camp);
        print_grid(grille); 
        if(resultat_partie != 42)
        {
            break;
        }
        full = est_pleine(grille);
        if(full == 1)
        {
            printf("Égalité !\n");
            break;
        }

    }
    if(resultat_partie == 0)
    {
        printf("Vous avez perdu !\n");
    }
    else if(resultat_partie == 1)
    {
        printf("Vous avez gagné !\n");
    }
}