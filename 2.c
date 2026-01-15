#include <stdio.h>

void ispisi_slovo_F() {
    int visina = 7; // 6 redova + dodatni red za širinu od 6 znakova
    int sirina = 6;
    
    for (int red = 0; red < visina; red++) {
        for (int kolona = 0; kolona < sirina; kolona++) {
            // Gornji horizontalni dio (prvi red)
            if (red == 0) {
                printf("#");
            }
            // Vertikalni dio (prva kolona)
            else if (kolona == 0) {
               printf("#");
            }
            // Srednji horizontalni dio (četvrti red)
            else if (red == 3) {
                if (kolona < 5) {
                    printf("#");
                } else {
                    printf(" ");
                }
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void ispisi_slovo_C() {
    int visina = 8;
    int sirina = 8;
    
    for (int red = 0; red < visina; red++) {
        for (int kolona = 0; kolona < sirina; kolona++) {
            // Gornji dio
            if (red == 0) {
                if (kolona >= 2 && kolona <= 6) {
                    printf("#");
                } else {
                    printf(" ");
                }
            }
            // Drugi red
            else if (red == 1) {
                if (kolona == 1 || kolona == 7) {
                    printf("#");
                } else if (kolona >= 2 && kolona <= 6) {
                    printf(" ");
                } else {
                    printf(" ");
                }
            }
            // Srednji redovi (3-6)
            else if (red >= 2 && red <= 5) {
                if (kolona == 0) {
                    printf("#");
                } else {
                    printf(" ");
                }
            }
            // Pretposljednji red
            else if (red == 6) {
                if (kolona == 1 || kolona == 7) {
                    printf("#");
                } else if (kolona >= 2 && kolona <= 6) {
                    printf(" ");
                } else {
                    printf(" ");
                }
            }
            // Donji red
            else if (red == 7) {
                if (kolona >= 2 && kolona <= 6) {
                    printf("#");
                } else {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}

int main() {
    printf("Ispis slova F:\n");
    ispisi_slovo_F();
    
    printf("\n\n");
    
    printf("Ispis slova C:\n");
    ispisi_slovo_C();
    
    return 0;
}