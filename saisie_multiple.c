#include <stdio.h>   // pour utiliser printf et scanf
#include <stdbool.h> // pour utiliser le type bool, true et false

int main()
{
    int val1 = 0;
    double val2 = 0;
    int check = 0; // nombre de valeurs lues par scanf

    // --- Opérateur ternaire : condition ? valeur_si_vrai : valeur_si_faux ---
    // Ce if / else ...
    bool is_positive = false;
    if (val1 > 0)
    {
        is_positive = true;
    }
    else
    {
        is_positive = false;
    }

    // ... s'écrit en une seule ligne avec l'opérateur ternaire
    is_positive = val1 > 0 ? true : false;

    // Valeur absolue : val1 si val1 est positif, sinon -val1
    int val_abs = val1 > 0 ? val1 : -val1;
    printf("positif : %d, valeur absolue : %d\n", is_positive, val_abs);

    // --- 1. Lire deux valeurs séparées par un espace ---
    // scanf retourne le nombre de valeurs lues correctement : 0, 1 ou 2.
    // Exemple de saisie : 12 3.5
    printf("Entrer A et B : ");
    check = scanf("%d %lf", &val1, &val2);

    if (check == 2)
    {
        printf("Tout est ok : %d  %lf\n", val1, val2);
    }
    else
    {
        printf("Il y a une erreur\n");
    }

    // --- 2. Lire deux valeurs séparées par une virgule ---
    // La virgule dans le format doit être tapée telle quelle par l'utilisateur.
    // Exemple de saisie : 12,3.5    (12 3.5 donne une erreur)
    printf("Entrer A et B separes par une virgule : ");
    check = scanf("%d,%lf", &val1, &val2);

    if (check == 2)
    {
        printf("Tout est ok : %d  %lf\n", val1, val2);
    }
    else
    {
        printf("Il y a une erreur\n");
    }

    // --- 3. Lire le séparateur dans un char pour le vérifier ---
    // L'espace avant %c saute les espaces et le retour à la ligne restés
    // dans le buffer : c reçoit le premier caractère visible.
    // Exemple de saisie : 12,3.5   ou   12 / 3.5
    char c = ' ';
    printf("Entrer A et B separes par , ou / : ");
    check = scanf("%d %c %lf", &val1, &c, &val2);

    // Ternaire pour choisir un caractère : 'Y' si les 3 valeurs sont lues
    char result = check == 3 ? 'Y' : 'N';
    printf("Saisie complete : %c\n", result);

    if (check == 3)
    {
        if (c == ',' || c == '/')
        {
            printf("Separateur ok\n");
        }
        else
        {
            printf("Separateur '%c' non autorise\n", c);
        }

        printf("Valeurs : %d  %lf\n", val1, val2);
    }
    else
    {
        printf("Il y a une erreur\n");
    }

    return 0;
}
