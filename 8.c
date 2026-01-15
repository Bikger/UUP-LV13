#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i, j, k;
    
    printf("Unesite string: ");
    fgets(str, sizeof(str), stdin);
    
    // Ukloni newline karakter
    str[strcspn(str, "\n")] = '\0';
    
    printf("Originalni string: %s\n", str);
    
    // Uklanjanje duplikata
    int duzina = strlen(str);
    
    for (i = 0; i < duzina; i++) {
        for (j = i + 1; j < duzina; j++) {
            // Ako nađemo duplikat
            if (str[i] == str[j]) {
                // Pomakni sve karaktere za jedno mjesto ulijevo
                for (k = j; k < duzina; k++) {
                    str[k] = str[k + 1];
                }
                duzina--;  // Smanji dužinu stringa
                j--;       // Vrati se na prethodnu poziciju jer smo pomaknuli karaktere
            }
        }
    }
    
    printf("String bez ponavljajucih znakova: %s\n", str);
    
    return 0;
}