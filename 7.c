#include <stdio.h>

#define MAX_REDOVA 10
#define MAX_KOLONA 10

int main() {
    int matrica[MAX_REDOVA][MAX_KOLONA];
    int redovi, kolone;
    
    // Unos dimenzija matrice
    printf("Dimenzija matrice: ");
    scanf("%dx%d", &redovi, &kolone);
    
    // Provjera da li je matrica kvadratna
    if (redovi != kolone) {
        printf("Matrica nije kvadratna, stoga nije matrica identiteta.\n");
        return 0;
    }
    
    if (redovi <= 0 || redovi > MAX_REDOVA || kolone <= 0 || kolone > MAX_KOLONA) {
        printf("Dimenzije moraju biti izmedju 1 i %d.\n", MAX_REDOVA);
        return 1;
    }
    
    // Unos elemenata matrice
    printf("Elementi matrice: ");
    for (int i = 0; i < redovi; i++) {
        for (int j = 0; j < kolone; j++) {
            scanf("%d", &matrica[i][j]);
        }
    }
    
    // Provjera da li je matrica identiteta
    int je_identiteta = 1;  // Pretpostavljamo da jeste
    
    for (int i = 0; i < redovi && je_identiteta; i++) {
        for (int j = 0; j < kolone && je_identiteta; j++) {
            // Na glavnoj dijagonali elementi trebaju biti 1
            if (i == j) {
                if (matrica[i][j] != 1) {
                    je_identiteta = 0;
                }
            }
            // Van glavne dijagonale elementi trebaju biti 0
            else {
                if (matrica[i][j] != 0) {
                    je_identiteta = 0;
                }
            }
        }
    }
    
    // Ispis rezultata
    printf("\nMatrica:\n");
    for (int i = 0; i < redovi; i++) {
        for (int j = 0; j < kolone; j++) {
            printf("%d ", matrica[i][j]);
        }
        printf("\n");
    }
    
    if (je_identiteta) {
        printf("\nOvo je matrica identiteta.\n");
    } else {
        printf("\nOvo NIJE matrica identiteta.\n");
    }
    
    return 0;
}