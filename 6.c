#include <stdio.h>

#define MAX_VELICINA 100

// Rekurzivna funkcija sa detaljnim ispisom
int zbir_niza_sa_ispisom(int niz[], int indeks, int duzina, int nivo) {
    // Ispis trenutnog stanja
    for (int i = 0; i < nivo; i++) {
        printf("  ");  // Uvlacenje za bolju preglednost
    }
    printf("Poziv zbir_niza(indeks=%d, duzina=%d)\n", indeks, duzina);
    
    if (indeks >= duzina) {
        for (int i = 0; i < nivo; i++) {
            printf("  ");
        }
        printf("Vracam 0 (bazni slucaj)\n");
        return 0;
    }
    
    int trenutni = niz[indeks];
    int zbir_ostatka = zbir_niza_sa_ispisom(niz, indeks + 1, duzina, nivo + 1);
    int rezultat = trenutni + zbir_ostatka;
    
    for (int i = 0; i < nivo; i++) {
        printf("  ");
    }
    printf("niz[%d]=%d + zbir_ostatka=%d = %d\n", 
           indeks, trenutni, zbir_ostatka, rezultat);
    
    return rezultat;
}

int main() {
    int niz[MAX_VELICINA];
    int n;
    
    printf("Unesite broj elemenata (max %d): ", MAX_VELICINA);
    scanf("%d", &n);
    
    if (n <= 0 || n > MAX_VELICINA) {
        printf("Broj elemenata mora biti izmedju 1 i %d.\n", MAX_VELICINA);
        return 1;
    }
    
    printf("Unesite elemente niza:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &niz[i]);
    }
    
    printf("\n=== REKURZIVNI PROCES ===\n");
    int zbir = zbir_niza_sa_ispisom(niz, 0, n, 0);
    
    printf("\n=== REZULTAT ===\n");
    printf("Zbir elemenata niza: %d\n", zbir);
    
    // Iterativna provjera
    int zbir_iterativno = 0;
    for (int i = 0; i < n; i++) {
        zbir_iterativno += niz[i];
    }
    printf("Provjera (iterativno): %d\n", zbir_iterativno);
    
    return 0;
}