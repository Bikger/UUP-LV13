#include <stdio.h>
#include <ctype.h>

int main() {
    int pocetak = 32;
    int kraj = 255;
    int broj_stupaca = 7;
    int broj_redova = (kraj - pocetak + 1 + broj_stupaca - 1) / broj_stupaca;
    
    // Naslov
    printf("extended ASCII table - excluding control characters\n");
    
    // Zaglavlje tabele
    printf("| Ch Dec Hex | Ch Dec Hex | Ch Dec Hex | Ch Dec Hex | Ch Dec Hex | Ch Dec Hex | Ch Dec Hex |\n");
    
    // Tijelo tabele
    for (int red = 0; red < broj_redova; red++) {
        printf("|");
        
        for (int stupac = 0; stupac < broj_stupaca; stupac++) {
            int ascii_kod = pocetak + red + (stupac * broj_redova);
            
            if (ascii_kod <= kraj) {
                // Prikaz karaktera
                char prikaz_karaktera;
                if (ascii_kod == ' ') {
                    prikaz_karaktera = ' ';
                } else if (isprint(ascii_kod)) {
                    prikaz_karaktera = ascii_kod;
                } else {
                    prikaz_karaktera = ' ';
                }
                
                // Ispis formata "Ch Dec Hex"
                printf(" %c %3d 0x%02x |", prikaz_karaktera, ascii_kod, ascii_kod);
            } else {
                // Prazan prostor za nedostajuće ćelije
                printf("            |");
            }
        }
        printf("\n");
    }
    
    return 0;
}