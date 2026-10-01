#include <stdio.h>

int main(){
    
    int value1 = 12345;
    int value2 = -12;

    double ask_value = 0;
    // printf("Entrer une valeur entre -10 et +10\n>");
    printf("Entrer une valeur entre -10 et +10 : ");
    scanf("%lf", &ask_value);
    printf("Valeur saisie : %lf\n", ask_value);
    
    printf("Value : %d [V]\n", value1);
    printf("Value : %06d [V]\n", value1);
    printf("Value : %-6d [V]\n", value1);
    
    
    printf("Value : %6d [V]\n", value2);
    printf("Value : %-6d [V]\n", value2);

    printf("Value : %.2lf [V]\n", 123.45);
    printf("Value : %10.2lf [V]\n", 123.45);
    printf("Value : %10.2lf [V]\n", 1230.45);
    printf("Value : %010.2lf [V]\n", 12300.45);
    printf("Value : %010.2lf [V]\n", -12300.45);
}