#include <stdio.h> // pour utiliser printf et sscanf

// argc : nombre d'arguments, nom du programme compris (vaut toujours au moins 1)
// argv : tableau de textes (char*) qui contient les arguments
//
// Exemple : ./app 12 -h
//   argc    = 3
//   argv[0] = "./app"   (le nom du programme)
//   argv[1] = "12"
//   argv[2] = "-h"
int main(int argc, char *argv[])
{
    // --- Toujours tester argc AVANT d'accéder à argv ---
    // Accéder à argv[1] alors que argc vaut 1 fait planter le programme.
    if (argc < 2)
    {
        printf("Il faut au moins un argument\n");
        return 1; // code d'erreur : le programme s'arrête ici
    }

    if (argc > 3)
    {
        printf("Trop d'arguments\n");
        return 2;
    }

    printf("La valeur de argc : %d\n", argc);
    printf("Le nom du programme : %s\n", argv[0]); // %s pour afficher un texte
    printf("L'argument a l'index 1 : %s\n", argv[1]);

    int index_arg = 2;
    if (argc > index_arg) // l'argument à l'index 2 n'existe que si argc > 2
    {
        printf("L'argument a l'index %d : %s\n", index_arg, argv[index_arg]);

        // --- Accéder à un caractère d'un argument ---
        // argv[2][0] est le premier caractère du texte argv[2]
        if (argv[index_arg][0] == '-' && argv[index_arg][1] == 'h')
        {
            printf("Aide : ./app <entier> [-h]\n");
        }
    }

    // --- Convertir un argument en nombre avec sscanf ---
    // Un argument est toujours un TEXTE : "12" n'est pas le nombre 12.
    // sscanf fonctionne comme scanf, mais lit dans un texte au lieu du clavier.
    int val1 = 0;
    int nbr_conv = sscanf(argv[1], "%d", &val1); // ne pas oublier le &

    // sscanf retourne le nombre de valeurs converties : on le teste toujours
    if (nbr_conv == 1)
    {
        printf("La valeur de 2*val1 : %d\n", 2 * val1);
    }
    else
    {
        printf("'%s' n'est pas un entier\n", argv[1]);
        return 3;
    }

    return 0;
}
