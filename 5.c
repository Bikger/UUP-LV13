#include <stdio.h>

#define MAX_VRIJEDNOSTI 1000
#define MIN_VRIJEDNOST 0
#define MAX_VRIJEDNOST 10

int main() {
    int vrijednosti[MAX_VRIJEDNOSTI];
    int broj_vrijednosti = 0;
    int unos;
    
    printf("Unesite vrijednosti izmedju %d i %d (odvojene razmakom):\n", MIN_VRIJEDNOST, MAX_VRIJEDNOST);
    printf("-1 za kraj niza\n");
    printf(">> ");
    
    // Čitanje vrijednosti od korisnika
    while (broj_vrijednosti < MAX_VRIJEDNOSTI) {
        scanf("%d", &unos);
        
        // Provjera da li je kraj unosa
        if (unos == -1) {
            break;
        }
        
        // Provjera da li je vrijednost u validnom rasponu
        if (unos < MIN_VRIJEDNOST || unos > MAX_VRIJEDNOST) {
            printf("Greska: Vrijednost %d nije u rasponu %d-%d. Preskacem.\n", 
                   unos, MIN_VRIJEDNOST, MAX_VRIJEDNOST);
            continue;
        }
        
        // Dodavanje vrijednosti u niz
        vrijednosti[broj_vrijednosti] = unos;
        broj_vrijednosti++;
    }
    
    // Ispis histograma
    printf("\nHistogram:\n");
    printf("----------\n");
    
    for (int i = 0; i < broj_vrijednosti; i++) {
        // Ispis broja hash znakova jednakog vrijednosti
        for (int j = 0; j < vrijednosti[i]; j++) {
            printf("#");
        }
        printf("\n");
    }
    
    return 0;
}