#include <stdio.h>

int main(void)
{
    int value = 0;

    printf("Entrez un entier : ");
    const int ret = scanf("%d", &value);
    printf("scanf retourne %d, value = %d\n", ret, value);

    // Le 2e scanf n'attend pas de saisie : il retombe sur les mêmes caractères
    const int ret2 = scanf("%d", &value);
    printf("2e scanf retourne %d, value = %d\n", ret2, value);

    // On lit ce qui reste dans le buffer, caractère par caractère
    const int c1 = getchar();
    printf("Caractère 1 : '%c' (code %d)\n", c1, c1);

    const int c2 = getchar();
    printf("Caractère 2 : '%c' (code %d)\n", c2, c2);

    const int c3 = getchar();
    printf("Caractère 3 : '%c' (code %d)\n", c3, c3);

    const int c4 = getchar();
    printf("Caractère 4 : '%c' (code %d)\n", c4, c4);

    const int c5 = getchar();
    printf("Caractère 5 : '%c' (code %d)\n", c5, c5);

    const int c6 = getchar();
    printf("Caractère 6 : '%c' (code %d)\n", c6, c6);

    return 0;
}
