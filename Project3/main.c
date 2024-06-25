#include "header.h"

int main() {
    Igrac igrac;
    int odluka, trenutna_scena = 1;
    static enum Opcija opcija;

    do {
        izbornik();
        printf("\nUnesite opciju: ");

        if (scanf("%d", &opcija) != 1) {
            printf("\nPogresan unos!\n");
            while (getchar() != '\n');
            continue;
        }

        switch (opcija) {
            case NOVA_IGRA:
                nova_igra(&igrac);
                trenutna_scena = 1;
                while (trenutna_scena != 50) {
                    prikazi_scenu(trenutna_scena);
                    scanf("%d", &odluka);
                    obradi_odluku(odluka, &igrac, &trenutna_scena);
                }
                printf("\nKraj igre!\n");
                break;
            case ARENA:
                arena_minigame(&igrac);
                break;
            case IZLAZ:
                return 0;  // Exit the program
            default:
                printf("\nPogresan unos!\n");
                break;
            }
    } while (opcija != IZLAZ);
    return 0;
}
