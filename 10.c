#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_DUZINA 1000

// Funkcija za pretvaranje velikih u mala slova
void velika_u_mala(FILE *ulaz, FILE *izlaz) {
    char ch;
    while ((ch = fgetc(ulaz)) != EOF) {
        if (isupper(ch)) {
            fputc(tolower(ch), izlaz);
        } else {
            fputc(ch, izlaz);
        }
    }
}

// Funkcija za pretvaranje malih u velika slova
void mala_u_velika(FILE *ulaz, FILE *izlaz) {
    char ch;
    while ((ch = fgetc(ulaz)) != EOF) {
        if (islower(ch)) {
            fputc(toupper(ch), izlaz);
        } else {
            fputc(ch, izlaz);
        }
    }
}

// Funkcija za pretvaranje velikih u mala i malih u velika (zamjena)
void zamijeni_velicinu(FILE *ulaz, FILE *izlaz) {
    char ch;
    while ((ch = fgetc(ulaz)) != EOF) {
        if (isupper(ch)) {
            fputc(tolower(ch), izlaz);
        } else if (islower(ch)) {
            fputc(toupper(ch), izlaz);
        } else {
            fputc(ch, izlaz);
        }
    }
}

// Funkcija za kreiranje testne datoteke
void kreiraj_testnu_datoteku() {
    FILE *test = fopen("test_input.txt", "w");
    if (test == NULL) {
        printf("Greska pri kreiranju testne datoteke!\n");
        return;
    }
    
    fprintf(test, "Ovo je TESTNA datoteka za PROVjeru Programa.\n");
    fprintf(test, "Ona sadrzi VELIKA i mala SLOVA.\n");
    fprintf(test, "Primjer: Hello World 123! @#$%%\n");
    fprintf(test, "PROGRAMIRANJE u C je ZANIMLJIVO.\n");
    
    fclose(test);
    printf("Kreirana testna datoteka: test_input.txt\n");
}

// Funkcija za ispis sadržaja datoteke
void ispisi_datoteku(const char *ime_datoteke) {
    FILE *datoteka = fopen(ime_datoteke, "r");
    if (datoteka == NULL) {
        printf("Greska pri otvaranju datoteke %s za citanje!\n", ime_datoteke);
        return;
    }
    
    printf("\n=== Sadrzaj datoteke %s ===\n", ime_datoteke);
    printf("----------------------------------------\n");
    
    char linija[MAX_DUZINA];
    while (fgets(linija, MAX_DUZINA, datoteka) != NULL) {
        printf("%s", linija);
    }
    
    printf("----------------------------------------\n");
    fclose(datoteka);
}

int main() {
    int izbor;
    char ulazna_datoteka[100], izlazna_datoteka[100];
    
    printf("=== PROGRAM ZA PRETVARANJE VELICINE SLOVA U DATOTECI ===\n\n");
    
    // Kreiranje testne datoteke
    printf("Zelite li kreirati testnu datoteku? (1-Da, 0-Ne): ");
    scanf("%d", &izbor);
    
    if (izbor == 1) {
        kreiraj_testnu_datoteku();
        printf("\n");
    }
    
    // Meni
    printf("=== IZBOR OPERACIJE ===\n");
    printf("1. Pretvori VELIKA slova u mala\n");
    printf("2. Pretvori mala slova u VELIKA\n");
    printf("3. Zamijeni velika i mala slova\n");
    printf("4. Sve tri operacije\n");
    printf("\nVas izbor: ");
    scanf("%d", &izbor);
    
    // Unos imena datoteka
    printf("\nUnesite ime ulazne datoteke: ");
    scanf("%s", ulazna_datoteka);
    
    // Otvaranje ulazne datoteke
    FILE *ulaz = fopen(ulazna_datoteka, "r");
    if (ulaz == NULL) {
        printf("Greska: Ne mogu otvoriti datoteku '%s'!\n", ulazna_datoteka);
        return 1;
    }
    
    // Izvršenje odabrane operacije
    switch (izbor) {
        case 1: {
            printf("Unesite ime izlazne datoteke: ");
            scanf("%s", izlazna_datoteka);
            
            FILE *izlaz = fopen(izlazna_datoteka, "w");
            if (izlaz == NULL) {
                printf("Greska pri kreiranju izlazne datoteke!\n");
                fclose(ulaz);
                return 1;
            }
            
            velika_u_mala(ulaz, izlaz);
            fclose(izlaz);
            
            printf("\nUspjesno pretvoreno VELIKA -> mala\n");
            ispisi_datoteku(izlazna_datoteka);
            break;
        }
        
        case 2: {
            printf("Unesite ime izlazne datoteke: ");
            scanf("%s", izlazna_datoteka);
            
            FILE *izlaz = fopen(izlazna_datoteka, "w");
            if (izlaz == NULL) {
                printf("Greska pri kreiranju izlazne datoteke!\n");
                fclose(ulaz);
                return 1;
            }
            
            mala_u_velika(ulaz, izlaz);
            fclose(izlaz);
            
            printf("\nUspjesno pretvoreno mala -> VELIKA\n");
            ispisi_datoteku(izlazna_datoteka);
            break;
        }
        
        case 3: {
            printf("Unesite ime izlazne datoteke: ");
            scanf("%s", izlazna_datoteka);
            
            FILE *izlaz = fopen(izlazna_datoteka, "w");
            if (izlaz == NULL) {
                printf("Greska pri kreiranju izlazne datoteke!\n");
                fclose(ulaz);
                return 1;
            }
            
            zamijeni_velicinu(ulaz, izlaz);
            fclose(izlaz);
            
            printf("\nUspjesno zamijenjena velicina slova\n");
            ispisi_datoteku(izlazna_datoteka);
            break;
        }
        
        case 4: {
            // Vrati na početak datoteke
            rewind(ulaz);
            
            // 1. VELIKA -> mala
            FILE *izlaz1 = fopen("velika_u_mala.txt", "w");
            if (izlaz1 != NULL) {
                velika_u_mala(ulaz, izlaz1);
                fclose(izlaz1);
            }
            
            // Vrati na početak datoteke
            rewind(ulaz);
            
            // 2. mala -> VELIKA
            FILE *izlaz2 = fopen("mala_u_velika.txt", "w");
            if (izlaz2 != NULL) {
                mala_u_velika(ulaz, izlaz2);
                fclose(izlaz2);
            }
            
            // Vrati na početak datoteke
            rewind(ulaz);
            
            // 3. Zamijeni
            FILE *izlaz3 = fopen("zamijenjeno.txt", "w");
            if (izlaz3 != NULL) {
                zamijeni_velicinu(ulaz, izlaz3);
                fclose(izlaz3);
            }
            
            printf("\nUspjesno izvrsene sve tri operacije!\n");
            printf("Kreirane datoteke:\n");
            printf("1. velika_u_mala.txt\n");
            printf("2. mala_u_velika.txt\n");
            printf("3. zamijenjeno.txt\n");
            
            // Ispis svih kreiranih datoteka
            printf("\n");
            ispisi_datoteku("velika_u_mala.txt");
            printf("\n");
            ispisi_datoteku("mala_u_velika.txt");
            printf("\n");
            ispisi_datoteku("zamijenjeno.txt");
            break;
        }
        
        default:
            printf("Nepoznat izbor!\n");
    }
    
    fclose(ulaz);
    return 0;
}