#include <stdio.h>

// Makro naredba za sabiranje dva broja
#define SABERI(a, b) ((a) + (b))

// Makro naredba za ispis rezultata
#define ISPISI_REZULTAT(a, b, rezultat) \
    printf("%d + %d = %d\n", a, b, rezultat)

int main() {
    int broj1, broj2, rezultat;
    
    printf("Unesite prvi broj: ");
    scanf("%d", &broj1);
    
    printf("Unesite drugi broj: ");
    scanf("%d", &broj2);
    
    // Korištenje makro naredbe za sabiranje
    rezultat = SABERI(broj1, broj2);
    
    // Korištenje makro naredbe za ispis
    ISPISI_REZULTAT(broj1, broj2, rezultat);
    
    return 0;
}