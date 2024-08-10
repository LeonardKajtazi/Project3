
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

typedef enum {
    PRVA_ODLUKA = 1,
    DRUGA_ODLUKA
} Odluka;

typedef enum {
    SUMA_DVIJE_STAZE = 1,
    LIJEVA_STAZA,
    DESNA_STAZA,
    PLIVANJE_PREKO_RIJEKE,
    VRACANJE_NA_POCETAK = 5,
    ODLAZAK_NA_BRDO,
    ULAZAK_U_PECINU,
    PUT_PORED_PECINE,
    ISTRAZIVANJE_RUSEVINA,
    POVRATAK_NIZ_BRDO = 10,
    UZIMANJE_BLAGA,
    DUBLJE_U_PECINU,
    BORBA_SA_ZMAJEM,
    BJEG_OD_ZMAJA,
    RAZGOVOR_MISTERIOZNA_OSOBA = 15,
    ODLAZAK_NA_TRZNICU,
    BJEG_IZ_PECINE,
    SKRIVANJE_I_CEKANJE,
    GNJEZDO_ZMAJA,
    ODLAZAK_U_GUSTU_SUMU = 20,
    PUT_KROZ_MOCVARU,
    SOLO_PUT,
    ZAPUSTENA_KOLIBA,
    IZLAZ_IZ_PECINE,
    RUSENJE_SPILJE = 25,
    STARAC_ZAMKA,
    WE_ARE_LAUST,
    BORBA_SA_TROLOM,
    RAZGOVOR_SA_TROLOM,
    UZIMANJE_PREDMETA = 30,
    PRAZNE_RUKE,
    ULAZAK_U_TRZNICU,
    PRODAJA,
    IZLAZ_IZ_AVANTURE
} Scene;

void nova_igra(Igrac* igrac);
void prikazi_scenu(int scenaID);
void snimi_igru(Igrac* igrac, const char* filename);
void ucitaj_igru(Igrac* igrac, const char* filename);
void izbornik();
void obradi_odluku(int odluka, Igrac* igrac, int* trenutnaScena);
void izbrisi_datoteku();
int usporedi_tezinu(const void* a, const void* b);
void arena_minigame(Igrac* igrac); // Dodana deklaracija funkcije

#endif
