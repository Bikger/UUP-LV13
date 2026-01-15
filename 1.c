#include <stdio.h>

int main() {
    int iznos;
    
    // Unos iznosa
    printf("Unesite iznos u novcaniku: ");
    scanf("%d", &iznos);
    
    if (iznos < 0) {
        printf("Iznos ne može biti negativan!\n");
        return 1;
    }
    
    printf("Iznos od %d KM može se razbiti na:\n", iznos);
    
    // Novčanice koje su dostupne (u kunama)
    int novcanice[] = {200, 100, 50, 20, 10, 5, 2, 1};
    int brojNovcanica = sizeof(novcanice) / sizeof(novcanice[0]);
    
    for (int i = 0; i < brojNovcanica; i++) {
        if (iznos >= novcanice[i]) {
            int broj = iznos / novcanice[i];
            printf("%4d KM: %d\n", novcanice[i], broj);
            iznos %= novcanice[i];
        }
    }
    
    return 0;
}
