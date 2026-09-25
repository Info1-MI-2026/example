#include <stdio.h>   // pour utiliser printf
#include <stdbool.h> // pour utiliser le type bool, true et false

int main()
{
    int cpt = 12;

    // --- Conventions de nommage ---
    double cpt_machine; // snake_case
    double CptMachine;  // PascalCase
    double cptMachine;  // camelCase

    // --- Le type bool ---
    // false vaut 0, true vaut 1 (et toute valeur != 0 est considérée vraie)
    bool condition1 = false;

    // On peut stocker le résultat d'une comparaison dans un bool
    bool est_positif = cpt > 0;

    printf("La valeur du compteur : %d\n", cpt);

    // --- Opérateurs ---
    // Comparaison : ==  !=  <  <=  >  >=
    // Logiques    : &&  ET
    //               ||  OU
    //               !   NON (inverse un bool : true -> false)

    // --- if / else if / else ---
    // Les conditions sont testées dans l'ordre : seul le premier bloc
    // dont la condition est vraie est exécuté.
    if (est_positif && condition1)
    {
        printf("Le compteur est positif et condition1 est vraie\n");
    }
    else if (cpt < -10)
    {
        printf("Le compteur est plus petit que -10\n");
    }
    else if (cpt < 0)
    {
        printf("Le compteur est négatif\n");
    }
    else
    {
        // On arrive ici si cpt vaut 0, ou si cpt est positif mais condition1 est fausse
        if (!condition1) // équivalent à : condition1 == false
        {
            printf("La variable condition1 est fausse\n");
        }
        printf("Le compteur vaut 0 ou condition1 est fausse\n");
    }

    printf("La fin du programme\n");

    return 0;
}
