#include <stdio.h>

void ispisi_slovo_F(int visina, int sirina) {
    if (visina < 3 || sirina < 2) {
        printf("Minimalna visina je 3, a minimalna sirina 2!\n");
        return;
    }
    
    for (int red = 0; red < visina; red++) {
        for (int kol = 0; kol < sirina; kol++) {
            if (red == 0) {
                printf("#");
            }
            else if (kol == 0) {
                printf("#");
            }
            else if (red == visina/3 && kol < sirina - 1) {
                printf("#");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void ispisi_slovo_C(int visina, int sirina) {
    if (visina < 5 || sirina < 5) {
        printf("Za zakrivljeno slovo C potrebna je minimalna visina 5 i sirina 5!\n");
        return;
    }
    
    // Predefinisani obrasci za različite veličine
    // Prvo provjerimo da li su dimenzije standardne
    if ((visina == 8 && sirina == 8) || (visina == 7 && sirina == 7)) {
        // Fiksan obrazac za originalni izgled
        char *obrasci[] = {
            "  ##### ",
            " ##    ##",
            "#        ",
            "#        ",
            "#        ",
            "#        ",
            " ##    ##",
            "  ##### "
        };
        
        // Prilagodimo za unesene dimenzije
        for (int red = 0; red < visina; red++) {
            for (int kol = 0; kol < sirina; kol++) {
                if (obrasci[red][kol] == '#') {
                    printf("#");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
    else {
        // Generički obrazac koji skalira
        int debljina_linije = 1;  // Možete povećati za deblje linije
        
        for (int red = 0; red < visina; red++) {
            for (int kol = 0; kol < sirina; kol++) {
                int treba_ispisati = 0;
                
                // Lijevi rub (glavni vertikalni dio)
                if (kol < debljina_linije && red >= visina/4 && red < 3*visina/4) {
                    treba_ispisati = 1;
                }
                
                // Gornji rub
                if (red < debljina_linije && kol >= sirina/3) {
                    treba_ispisati = 1;
                }
                
                // Donji rub
                if (red >= visina - debljina_linije && kol >= sirina/3) {
                    treba_ispisati = 1;
                }
                
                // Gornje zakrivljenje
                if (red >= debljina_linije && red < visina/4) {
                    int prazni_s_lijeve = (visina/4 - red) * 2;
                    if (kol >= prazni_s_lijeve && kol < prazni_s_lijeve + debljina_linije) {
                        treba_ispisati = 1;
                    }
                    if (kol >= sirina - debljina_linije && red == debljina_linije) {
                        treba_ispisati = 1;
                    }
                }
                
                // Donje zakrivljenje
                if (red > 3*visina/4 && red < visina - debljina_linije) {
                    int prazni_s_lijeve = (red - 3*visina/4) * 2;
                    if (kol >= prazni_s_lijeve && kol < prazni_s_lijeve + debljina_linije) {
                        treba_ispisati = 1;
                    }
                    if (kol >= sirina - debljina_linije && red == visina - debljina_linije - 1) {
                        treba_ispisati = 1;
                    }
                }
                
                if (treba_ispisati) {
                    printf("#");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
}

int main() {
    int visina_F, sirina_F;
    int visina_C, sirina_C;
    
    printf("=== PROGRAM ZA ISPIS SLOVA F I C ===\n\n");
    
    printf("--- Slovo F ---\n");
    printf("Unesite visinu slova F: ");
    scanf("%d", &visina_F);
    printf("Unesite sirinu slova F: ");
    scanf("%d", &sirina_F);
    
    printf("\nSlovo F (%d x %d):\n", visina_F, sirina_F);
    ispisi_slovo_F(visina_F, sirina_F);
    
    printf("\n--- Slovo C ---\n");
    printf("NAPOMENA: Za originalni izgled unesite visinu 8 i sirinu 8\n");
    printf("Unesite visinu slova C: ");
    scanf("%d", &visina_C);
    printf("Unesite sirinu slova C: ");
    scanf("%d", &sirina_C);
    
    printf("\nSlovo C (%d x %d):\n", visina_C, sirina_C);
    ispisi_slovo_C(visina_C, sirina_C);
    
    return 0;
}
