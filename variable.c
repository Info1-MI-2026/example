#include <stdio.h> // pour utiliser printf

int main()
{
    // --- Déclaration : un type + un nom ---
    int i1;      // entier signé sur 32 bits
    char c1;     // caractère / entier signé sur 8 bits

    // --- Déclaration avec initialisation ---
    double force = 1.2e3; // nombre à virgule sur 64 bits
    double couple = 0.0234;

    // Sans initialisation, la valeur de i1 et c1 est inconnue.
    // Il faut leur donner une valeur avant de les utiliser.
    i1 = 100;
    c1 = i1; // conversion int -> char (100 tient sur 8 bits)

    force = force * 0.1;

    // %d : int    %lf : double    %c : char
    printf("La valeur de i1 est : %d\n", i1);
    printf("La force vaut %.2lf et le couple %lf [Nm]\n", force, couple);

    // --- Dépassement de capacité ---
    // c1 vaut 100, mais 2 * 100 = 200 ne tient pas dans un char signé
    // (plage -128 à 127) : le résultat devient négatif.
    printf("c1 = %d et (char)(2 * c1) = %d\n", c1, (char)(2 * c1));

    // --- Les char sont des nombres ---
    char char1 = 65;                 // 65 est le code ASCII de 'A'
    char char2 = 'c' + 'A' - 'a';    // guillemets simples pour un char

    printf("char1 + 1 vaut %d  -  %c\n", char1 + 1, char1 + 1);
    printf("char2 vaut %d  -  %c\n", char2, char2);
    printf("La lettre g se trouve en position %d\n", 'g' - 'a' + 1);

    return 0;
}
