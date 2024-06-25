#define _CRT_SECURE_NO_WARNINGS

#ifndef HEADER
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IME 50

typedef struct {
    char ime[MAX_IME];
    int zdravlje;
    int snaga;
    int obrana;
} Igrac;

typedef struct {
    char naziv[MAX_IME];
    int tezina;
} Protivnik;

enum Opcija {
    NOVA_IGRA = 1,
    ARENA,
    IZLAZ
};

void nova_igra(Igrac* igrac);
void prikazi_scenu(int scenaID);
void snimi_igru(Igrac* igrac, const char* filename);
void ucitaj_igru(Igrac* igrac, const char* filename);
void izbornik();
void obradi_odluku(int odluka, Igrac* igrac, int* trenutnaScena);
void arena_minigame(Igrac* igrac); // Dodana deklaracija funkcije

#endif
