#include <stdio.h>
#include <stdlib.h>

// Funkcija za unos matrice koristeći pokazivače
void unos_matrice(int **matrica, int redovi, int kolone) {
    printf("Unesite elemente matrice:\n");
    for (int i = 0; i < redovi; i++) {
        printf("Red %d: ", i + 1);
        for (int j = 0; j < kolone; j++) {
            scanf("%d", (*(matrica + i) + j));
        }
    }
}

// Funkcija za ispis matrice koristeći pokazivače
void ispis_matrice(int **matrica, int redovi, int kolone) {
    for (int i = 0; i < redovi; i++) {
        for (int j = 0; j < kolone; j++) {
            printf("%4d ", *(*(matrica + i) + j));
        }
        printf("\n");
    }
}

// Funkcija za množenje matrica koristeći pokazivače
void mnozenje_matrica(int **matricaA, int **matricaB, int **rezultat, 
                     int redoviA, int koloneA, int koloneB) {
    for (int i = 0; i < redoviA; i++) {
        for (int j = 0; j < koloneB; j++) {
            *(*(rezultat + i) + j) = 0;  // Inicijalizacija na 0
            
            for (int k = 0; k < koloneA; k++) {
                // rezultat[i][j] += matricaA[i][k] * matricaB[k][j]
                *(*(rezultat + i) + j) += *(*(matricaA + i) + k) * *(*(matricaB + k) + j);
            }
        }
    }
}

int main() {
    int redoviA, koloneA, redoviB, koloneB;
    
    printf("=== MNOZENJE MATRICA KORISTECI POKAZIVACE ===\n\n");
    
    // Unos dimenzija prve matrice
    printf("Unesite dimenzije prve matrice (redovi kolone): ");
    scanf("%d %d", &redoviA, &koloneA);
    
    // Unos dimenzija druge matrice
    printf("Unesite dimenzije druge matrice (redovi kolone): ");
    scanf("%d %d", &redoviB, &koloneB);
    
    // Provjera da li je množenje moguće
    if (koloneA != redoviB) {
        printf("\nGreska: Mnozenje nije moguce!\n");
        printf("Broj kolona prve matrice (%d) mora biti jednak broju redova druge matrice (%d).\n",
               koloneA, redoviB);
        return 1;
    }
    
    // Dinamička alokacija memorije za matrice
    // Prva matrica
    int **matricaA = (int **)malloc(redoviA * sizeof(int *));
    for (int i = 0; i < redoviA; i++) {
        matricaA[i] = (int *)malloc(koloneA * sizeof(int));
    }
    
    // Druga matrica
    int **matricaB = (int **)malloc(redoviB * sizeof(int *));
    for (int i = 0; i < redoviB; i++) {
        matricaB[i] = (int *)malloc(koloneB * sizeof(int));
    }
    
    // Rezultujuća matrica
    int **rezultat = (int **)malloc(redoviA * sizeof(int *));
    for (int i = 0; i < redoviA; i++) {
        rezultat[i] = (int *)malloc(koloneB * sizeof(int));
    }
    
    // Unos elemenata matrica
    printf("\n--- Prva matrica (%d x %d) ---\n", redoviA, koloneA);
    unos_matrice(matricaA, redoviA, koloneA);
    
    printf("\n--- Druga matrica (%d x %d) ---\n", redoviB, koloneB);
    unos_matrice(matricaB, redoviB, koloneB);
    
    // Množenje matrica
    mnozenje_matrica(matricaA, matricaB, rezultat, redoviA, koloneA, koloneB);
    
    // Ispis rezultata
    printf("\n=== REZULTAT MNOZENJA ===\n");
    printf("\nPrva matrica (%d x %d):\n", redoviA, koloneA);
    ispis_matrice(matricaA, redoviA, koloneA);
    
    printf("\nDruga matrica (%d x %d):\n", redoviB, koloneB);
    ispis_matrice(matricaB, redoviB, koloneB);
    
    printf("\nRezultat (%d x %d):\n", redoviA, koloneB);
    ispis_matrice(rezultat, redoviA, koloneB);
    
    // Oslobađanje memorije
    for (int i = 0; i < redoviA; i++) {
        free(matricaA[i]);
    }
    free(matricaA);
    
    for (int i = 0; i < redoviB; i++) {
        free(matricaB[i]);
    }
    free(matricaB);
    
    for (int i = 0; i < redoviA; i++) {
        free(rezultat[i]);
    }
    free(rezultat);
    
    return 0;
}