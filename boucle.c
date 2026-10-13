#include <stdio.h> // pour utiliser printf

int main()
{
    int cpt = 0;

    // --- while : tant que ---
    // La condition est testée AVANT chaque tour.
    // Si elle est fausse dès le départ, le bloc n'est jamais exécuté.
    while (cpt <= 10)
    {
        printf("cpt while : %d\n", cpt);
        cpt += 1; // équivalent à : cpt++  ou  cpt = cpt + 1
    }
    // Autres opérateurs d'affectation composée : -=  *=  /=

    // Avec cpt = 11, la condition est fausse dès le départ :
    // la boucle while ne fait aucun tour.
    cpt = 11;
    while (cpt <= 10)
    {
        printf("jamais affiché\n");
        cpt++;
    }

    // --- do ... while : faire ... tant que ---
    // La condition est testée APRÈS chaque tour.
    // Le bloc est donc exécuté AU MOINS une fois, même si cpt vaut 11.
    cpt = 11;
    do
    {
        printf("cpt do while : %d\n", cpt);
        cpt++;
    } while (cpt <= 10); // attention au ; à la fin

    // --- for ---
    // for (initialisation; condition; incrément)
    //   1. initialisation : exécutée une seule fois, au début
    //   2. condition      : testée avant chaque tour
    //   3. incrément      : exécuté à la fin de chaque tour
    double force = 9.81;
    for (int i = 0; i <= 10; i += 2) // i vaut 0, 2, 4, 6, 8, 10
    {
        printf("i de la boucle for : %d\n", i);
        printf("la force : %lf\n", i * force);
    }
    // i n'existe plus ici : il est déclaré dans le for

    // Une boucle peut aussi compter à l'envers, et avec des char
    // (un char est un entier : son code ASCII)
    for (char c = 'X'; c >= 'E'; c--)
    {
        printf("%c", c); // affiche XWVUTSRQPONMLKJIHGFE
    }
    printf("\n");

    // Boucle + condition : afficher les multiples de 7 entre 3 et 100
    for (int i = 3; i <= 100; i++)
    {
        if (i % 7 == 0) // % : reste de la division entière
        {
            printf("Multiple de 7 : %d\n", i);
        }
    }

    return 0;
}
