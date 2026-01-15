#include <stdio.h>

// Makro naredba za zamjenu dva broja
#define ZAMIJENI(a, b) \
    do { \
        int temp = (a); \
        (a) = (b); \
        (b) = temp; \
    } while(0)

int main() {
    int broj1, broj2;
    
    printf("Unesite prvi broj: ");
    scanf("%d", &broj1);
    
    printf("Unesite drugi broj: ");
    scanf("%d", &broj2);
    
    printf("\nPrije zamjene:\n");
    printf("Broj1 = %d, Broj2 = %d\n", broj1, broj2);
    
    // Korištenje makro naredbe za zamjenu
    ZAMIJENI(broj1, broj2);
    
    printf("\nPoslije zamjene:\n");
    printf("Broj1 = %d, Broj2 = %d\n", broj1, broj2);
    
    return 0;
}