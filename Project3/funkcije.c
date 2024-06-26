﻿#include "header.h"

void izbornik() {
    printf("\nIzbornik:\n");
    printf("1. Zapocni avanturu\n");
    printf("2. Arena minigame\n");
    printf("3. Izlaz\n");
}

void nova_igra(Igrac* igrac) {
    strncpy(igrac->ime, "Heroj", MAX_IME);
    igrac->zdravlje = 100;
    igrac->snaga = 20;
    igrac->obrana = 10;
}

void prikazi_scenu(int scenaID) {
    FILE* file = fopen("scena1.txt", "r");
    if (!file) {
        perror("Greska prilikom otvaranja datoteke scena");
        return;
    }

    int id, opcija_1, opcija_2;
    char scena_opis[256], opcija_opis_1[256], opcija_opis_2[256];

    while (fscanf(file, "%d %[^\n] %d %[^\n] %d %[^\n]", &id, scena_opis, &opcija_1, opcija_opis_1, &opcija_2, opcija_opis_2) != EOF) {
        if (id == scenaID) {
            printf("\n%s\n", scena_opis);
            printf("1. %s\n", opcija_opis_1);
            printf("2. %s\n", opcija_opis_2);
            break;
        }
    }

    fclose(file);
}

void snimi_igru(Igrac* igrac, const char* filename) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        perror("Greska prilikom snimanja igre");
        return;
    }
    fwrite(igrac, sizeof(Igrac), 1, file);
    fclose(file);
}

void ucitaj_igru(Igrac* igrac, const char* filename) {
    FILE* file = fopen("arena.txt", "r");

    if (!file) {
        perror("Greska prilikom ucitavanja igre");
        return;
    }

    

    size_t result = fread(igrac, sizeof(Igrac), 1, file);
    if (result != 1) {
        perror("Greska prilikom citanja igraca iz datoteke");
    }

    fclose(file);
}

//void obradi_odluku(int odluka, Igrac* igrac, int* trenutnaScena) {
//    switch (*trenutnaScena) {
//    case 1:
//        if (odluka == 1) {
//            *trenutnaScena = 2;
//        }
//        else if (odluka == 2) {
//            *trenutnaScena = 3;
//        }
//        else {
//            printf("Taj izbor ne postoji!");
//        }
//        break;
//    case 2:
//        *trenutnaScena = (odluka == 1) ?  4 : 5;
//        break;
//    case 3:
//        *trenutnaScena = (odluka == 1) ? 6 : 5;
//        break;
//    case 4:
//        *trenutnaScena = (odluka == 1) ? 7 : 8;
//        break;
//    case 5:
//        *trenutnaScena = (odluka == 1) ? 2 : 3;
//        break;
//    case 6:
//        *trenutnaScena = (odluka == 1) ? 9 : 10;
//        break;
//    case 7:
//        *trenutnaScena = (odluka == 1) ? 11 : 12;
//        break;
//    case 8:
//        *trenutnaScena = (odluka == 1) ? 13 : 14;
//        break;
//    case 9:
//        *trenutnaScena = (odluka == 1) ? 7 : 6;
//        break;
//    case 10:
//        *trenutnaScena = (odluka == 1) ? 15 : 16;
//        break;
//    case 11:
//        *trenutnaScena = (odluka == 1) ? 17 : 18;
//        break;
//    case 12:
//        *trenutnaScena = (odluka == 1) ? 31 : 11;
//        break;
//    case 13:
//        *trenutnaScena = (odluka == 1) ? 19 : 20;
//        break;
//    case 14:
//        *trenutnaScena = (odluka == 1) ? 31 : 16;
//        break;
//    case 15:
//        *trenutnaScena = (odluka == 1) ? 30 : 31;
//        break;
//    case 16:
//        *trenutnaScena = (odluka == 1) ? 32 : 27;
//        break;
//    case 17:
//        *trenutnaScena = (odluka == 1) ? 5 : 50;
//        break;
//    case 18:
//        *trenutnaScena = (odluka == 1) ? 24 : 25;
//        break;
//    case 19:
//        *trenutnaScena = (odluka == 1) ? 11 : 16;
//        break;
//    case 20:
//        *trenutnaScena = (odluka == 1) ? 21 : 32;
//        break;
//    case 21:
//        *trenutnaScena = (odluka == 1) ? 26 : 22;
//        break;
//    case 22:
//        *trenutnaScena = (odluka == 1) ? 17 : 16;
//        break;
//    case 23:
//        *trenutnaScena = (odluka == 1) ? 28 : 29;
//        break;
//    case 24:
//        *trenutnaScena = (odluka == 1) ? 5 : 50;
//        break;
//    case 25:
//        *trenutnaScena = (odluka == 1) ? 5 : 50;
//        break;
//    case 26:
//        *trenutnaScena = (odluka == 1) ? 5 : 50;
//        break;
//    case 27:
//        *trenutnaScena = (odluka == 1) ? 5 : 50;
//        break;
//    case 28:
//        *trenutnaScena = (odluka == 1) ? 5 : 50;
//        break;
//    case 29:
//        *trenutnaScena = (odluka == 1) ? 5 : 50;
//        break;
//    case 30:
//        *trenutnaScena = (odluka == 1) ? 5 : 50;
//        break;
//    case 31:
//        *trenutnaScena = (odluka == 1) ? 5 : 50;
//        break;
//    case 32:
//        *trenutnaScena = (odluka == 1) ? 33 : 34;
//        break;
//    case 33:
//        *trenutnaScena = (odluka == 1) ? 5 : 50;
//        break;
//    case 50:
//        break;
//    default:
//        printf("Nepoznata scena!\n");
//        break;
//    }
//    return 0;
//}

void obradi_odluku(Odluka odluka, Igrac* igrac, Scene* trenutnaScena) {
    switch (*trenutnaScena) {
    case SUMA_DVIJE_STAZE:
        switch (odluka) {
        case PRVA_ODLUKA:
            *trenutnaScena = LIJEVA_STAZA;
            break;
        case DRUGA_ODLUKA:
            *trenutnaScena = DESNA_STAZA;
            break;
        default:
            printf("Taj izbor ne postoji!\n");
            break;
        }
        break;
    case LIJEVA_STAZA:
        switch (odluka) {
        case PRVA_ODLUKA:
            *trenutnaScena = PLIVANJE_PREKO_RIJEKE;
            break;
        case DRUGA_ODLUKA:
            *trenutnaScena = VRACANJE_NA_POCETAK;
            break;
        default:
            printf("Taj izbor ne postoji!\n");
            break;
        }
        break;
    case DESNA_STAZA:
        switch (odluka) {
        case PRVA_ODLUKA:
            *trenutnaScena = ODLAZAK_NA_BRDO;
            break;
        case DRUGA_ODLUKA:
            *trenutnaScena = VRACANJE_NA_POCETAK;
            break;
        default:
            printf("Taj izbor ne postoji!\n");
            break;
        }
        break;
    case PLIVANJE_PREKO_RIJEKE:
        switch (odluka) {
        case PRVA_ODLUKA:
            *trenutnaScena = ULAZAK_U_PECINU;
            break;
        case DRUGA_ODLUKA:
            *trenutnaScena = PUT_PORED_PECINE;
            break;
        default:
            printf("Taj izbor ne postoji!\n");
            break;
        }
        break;
    case VRACANJE_NA_POCETAK:
        switch (odluka) {
        case PRVA_ODLUKA:
            *trenutnaScena = LIJEVA_STAZA;
            break;
        case DRUGA_ODLUKA:
            *trenutnaScena = DESNA_STAZA;
            break;
        default:
            printf("Taj izbor ne postoji!\n");
            break;
        }
        break;
    case ODLAZAK_NA_BRDO:
        switch (odluka) {
        case PRVA_ODLUKA:
            *trenutnaScena = ISTRAZIVANJE_RUSEVINA;
            break;
        case DRUGA_ODLUKA:
            *trenutnaScena = POVRATAK_NIZ_BRDO;
            break;
        default:
            printf("Taj izbor ne postoji!\n");
            break;
        }
        break;
    case ULAZAK_U_PECINU:
        switch (odluka) {
        case PRVA_ODLUKA:
            *trenutnaScena = UZIMANJE_BLAGA;
            break;
        case DRUGA_ODLUKA:
            *trenutnaScena = DUBLJE_U_PECINU;
            break;
        default:
            printf("Taj izbor ne postoji!\n");
            break;
        }
        break;
    case PUT_PORED_PECINE:
        switch (odluka) {
        case PRVA_ODLUKA:
            *trenutnaScena = BORBA_SA_ZMAJEM;
            break;
        case DRUGA_ODLUKA:
            *trenutnaScena = BJEG_OD_ZMAJA;
            break;
        default:
            printf("Taj izbor ne postoji!\n");
            break;
        }
        break;
    case ISTRAZIVANJE_RUSEVINA:
        switch (odluka) {
        case PRVA_ODLUKA:
            *trenutnaScena = ULAZAK_U_PECINU;
            break;
        case DRUGA_ODLUKA:
            *trenutnaScena = ODLAZAK_NA_BRDO;
            break;
        default:
            printf("Taj izbor ne postoji!\n");
            break;
        }
        break;
    case POVRATAK_NIZ_BRDO:
        switch (odluka) {
        case PRVA_ODLUKA:
            *trenutnaScena = RAZGOVOR_MISTERIOZNA_OSOBA;
            break;
        case DRUGA_ODLUKA:
            *trenutnaScena = ODLAZAK_NA_TRZNICU;
            break;
        default:
            printf("Taj izbor ne postoji!\n");
            break;
        }
        break;
    case UZIMANJE_BLAGA:
        switch (odluka) {
        case PRVA_ODLUKA:
            *trenutnaScena = BJEG_IZ_PECINE;
            break;
        case DRUGA_ODLUKA:
            *trenutnaScena = SKRIVANJE_I_CEKANJE;
            break;
        default:
            printf("Taj izbor ne postoji!\n");
            break;
        }
        break;
    case DUBLJE_U_PECINU:
        switch (odluka) {
        case PRVA_ODLUKA:
            *trenutnaScena = PRAZNE_RUKE;
            break;
        case DRUGA_ODLUKA:
            *trenutnaScena = UZIMANJE_BLAGA;
            break;
        default:
            printf("Taj izbor ne postoji!\n");
            break;
        }
        break;
    case BORBA_SA_ZMAJEM:
        switch (odluka) {
        case PRVA_ODLUKA:
            *trenutnaScena = GNJEZDO_ZMAJA;
            break;
        case DRUGA_ODLUKA:
            *trenutnaScena = ODLAZAK_U_GUSTU_SUMU;
            break;
        default:
            printf("Taj izbor ne postoji!\n");
            break;
        }
        break;
    case BJEG_OD_ZMAJA:
        switch (odluka) {
        case PRVA_ODLUKA:
            *trenutnaScena = PRAZNE_RUKE;
            break;
        case DRUGA_ODLUKA:
            *trenutnaScena = ODLAZAK_NA_TRZNICU;
            break;
        default:
            printf("Taj izbor ne postoji!\n");
            break;
        }
        break;
    case RAZGOVOR_MISTERIOZNA_OSOBA:
        switch (odluka) {
        case PRVA_ODLUKA:
            *trenutnaScena = UZIMANJE_PREDMETA;
            break;
        case DRUGA_ODLUKA:
            *trenutnaScena = PRAZNE_RUKE;
            break;
        default:
            printf("Taj izbor ne postoji!\n");
            break;
        }
        break;
    case ODLAZAK_NA_TRZNICU:
        switch (odluka) {
        case PRVA_ODLUKA:
            *trenutnaScena = ULAZAK_U_TRZNICU;
            break;
        case DRUGA_ODLUKA:
            *trenutnaScena = WE_ARE_LAUST; //there are no rules man, we're LAUST
            break;
        default:
            printf("Taj izbor ne postoji!\n");
            break;
        }
        break;
    case BJEG_IZ_PECINE:
        switch (odluka) {
        case PRVA_ODLUKA:
            *trenutnaScena = VRACANJE_NA_POCETAK;
            break;
        case DRUGA_ODLUKA:
            *trenutnaScena = IZLAZ_IZ_AVANTURE;
            break;
        default:
            printf("Taj izbor ne postoji!\n");
            break;
        }
        break;
    case SKRIVANJE_I_CEKANJE:
        switch (odluka) {
        case PRVA_ODLUKA:
            *trenutnaScena = IZLAZ_IZ_PECINE;
            break;
        case DRUGA_ODLUKA:
            *trenutnaScena = RUSENJE_SPILJE;
            break;
        default:
            printf("Taj izbor ne postoji!\n");
            break;
        }
        break;
    case GNJEZDO_ZMAJA:
        switch (odluka) {
        case PRVA_ODLUKA:
            *trenutnaScena = UZIMANJE_BLAGA;
            break;
        case DRUGA_ODLUKA:
            *trenutnaScena = ODLAZAK_NA_TRZNICU;
            break;
        default:
            printf("Taj izbor ne postoji!\n");
            break;
        }
        break;
    case ODLAZAK_U_GUSTU_SUMU:
        switch (odluka) {
        case PRVA_ODLUKA:
            *trenutnaScena = PUT_KROZ_MOCVARU;
            break;
        case DRUGA_ODLUKA:
            *trenutnaScena = ULAZAK_U_TRZNICU;
            break;
        default:
            printf("Taj izbor ne postoji!\n");
            break;
        }
        break;
    case PUT_KROZ_MOCVARU:
        switch (odluka) {
        case PRVA_ODLUKA:
            *trenutnaScena = STARAC_ZAMKA;
            break;
        case DRUGA_ODLUKA:
            *trenutnaScena = SOLO_PUT;
            break;
        default:
            printf("Taj izbor ne postoji!\n");
            break;
        }
        break;
    case SOLO_PUT:
        switch (odluka) {
        case PRVA_ODLUKA:
            *trenutnaScena = BJEG_IZ_PECINE;
            break;
        case DRUGA_ODLUKA:
            *trenutnaScena = ODLAZAK_NA_TRZNICU;
            break;
        default:
            printf("Taj izbor ne postoji!\n");
            break;
        }
        break;
    case ZAPUSTENA_KOLIBA:
        switch (odluka) {
        case PRVA_ODLUKA:
            *trenutnaScena = BORBA_SA_TROLOM;
            break;
        case DRUGA_ODLUKA:
            *trenutnaScena = RAZGOVOR_SA_TROLOM;
            break;
        default:
            printf("Taj izbor ne postoji!\n");
            break;
        }
        break;
    case IZLAZ_IZ_PECINE:
        switch (odluka) {
        case PRVA_ODLUKA:
            *trenutnaScena = VRACANJE_NA_POCETAK;
            break;
        case DRUGA_ODLUKA:
            *trenutnaScena = IZLAZ_IZ_AVANTURE;
            break;
        default:
            printf("Taj izbor ne postoji!\n");
            break;
        }
        break;
    case RUSENJE_SPILJE:
        switch (odluka) {
        case PRVA_ODLUKA:
            *trenutnaScena = VRACANJE_NA_POCETAK;
            break;
        case DRUGA_ODLUKA:
            *trenutnaScena = IZLAZ_IZ_AVANTURE;
            break;
        default:
            printf("Taj izbor ne postoji!\n");
            break;
        }
        break;
    case STARAC_ZAMKA:
        switch (odluka) {
        case PRVA_ODLUKA:
            *trenutnaScena = VRACANJE_NA_POCETAK;
            break;
        case DRUGA_ODLUKA:
            *trenutnaScena = IZLAZ_IZ_AVANTURE;
            break;
        default:
            printf("Taj izbor ne postoji!\n");
            break;
        }
        break;
    case WE_ARE_LAUST:
        switch (odluka) {
        case PRVA_ODLUKA:
            *trenutnaScena = VRACANJE_NA_POCETAK;
            break;
        case DRUGA_ODLUKA:
            *trenutnaScena = IZLAZ_IZ_AVANTURE;
            break;
        default:
            printf("Taj izbor ne postoji!\n");
            break;
        }
        break;
    case BORBA_SA_TROLOM:
        switch (odluka) {
        case PRVA_ODLUKA:
            *trenutnaScena = VRACANJE_NA_POCETAK;
            break;
        case DRUGA_ODLUKA:
            *trenutnaScena = IZLAZ_IZ_AVANTURE;
            break;
        default:
            printf("Taj izbor ne postoji!\n");
            break;
        }
        break;
    case RAZGOVOR_SA_TROLOM:
        switch (odluka) {
        case PRVA_ODLUKA:
            *trenutnaScena = VRACANJE_NA_POCETAK;
            break;
        case DRUGA_ODLUKA:
            *trenutnaScena = IZLAZ_IZ_AVANTURE;
            break;
        default:
            printf("Taj izbor ne postoji!\n");
            break;
        }
        break;
    case UZIMANJE_PREDMETA:
        switch (odluka) {
        case PRVA_ODLUKA:
            *trenutnaScena = VRACANJE_NA_POCETAK;
            break;
        case DRUGA_ODLUKA:
            *trenutnaScena = IZLAZ_IZ_AVANTURE;
            break;
        default:
            printf("Taj izbor ne postoji!\n");
            break;
        }
        break;
    case PRAZNE_RUKE:
        switch (odluka) {
        case PRVA_ODLUKA:
            *trenutnaScena = VRACANJE_NA_POCETAK;
            break;
        case DRUGA_ODLUKA:
            *trenutnaScena = IZLAZ_IZ_AVANTURE;
            break;
        default:
            printf("Taj izbor ne postoji!\n");
            break;
        }
        break;
    case ULAZAK_U_TRZNICU:
        switch (odluka) {
        case PRVA_ODLUKA:
            *trenutnaScena = PRODAJA;
            break;
        case DRUGA_ODLUKA:
            *trenutnaScena = PRAZNE_RUKE;
            break;
        default:
            printf("Taj izbor ne postoji!\n");
            break;
        }
        break;
    case PRODAJA:
        switch (odluka) {
        case PRVA_ODLUKA:
            *trenutnaScena = VRACANJE_NA_POCETAK;
            break;
        case DRUGA_ODLUKA:
            *trenutnaScena = IZLAZ_IZ_AVANTURE;
            break;
        default:
            printf("Taj izbor ne postoji!\n");
            break;
        }
        break;
    case IZLAZ_IZ_AVANTURE:
        break;
    default:
        printf("Nepoznata scena!\n");
        break;
    }
}

void arena_minigame(Igrac* igrac) {
    FILE* file = NULL;
    Protivnik* protivnici = (Protivnik*)malloc(3 * sizeof(Protivnik));
    if (protivnici == NULL) {
        printf("Greska prilikom alociranja memorije za protivnike.\n");
        return;
    }

    strncpy(protivnici[0].naziv, "Goblin", MAX_IME);
    protivnici[0].tezina = 15;
    strncpy(protivnici[1].naziv, "Ork", MAX_IME);
    protivnici[1].tezina = 25;
    strncpy(protivnici[2].naziv, "Zmaj", MAX_IME);
    protivnici[2].tezina = 50;

    int broj_protivnika = 3;  // Define the number of opponents

    printf("\nDobrodosli u arenu!\n");
    printf("\n1. Nova igra\t2. Ucitaj igru\n");
    int igra = 0;
    int iskustvo = 0;  // Initialize iskustvo to 0
    int level = 1;
    scanf("%d", &igra);

    if (igra == 2) {
        file = fopen("arena.txt", "r+");
        if (file == NULL) {
            printf("Neuspjesno otvaranje datoteke arena.txt za citanje.\n");
            free(protivnici);
            return;
        }
        if (fscanf(file, "%d", &iskustvo) == 1) {  // Correct condition to check if a valid number is read
            printf("Spremljeno iskustvo iz datoteke: %d\n\n", iskustvo);
        }
        else {
            printf("Nije pronaden vazeci broj u datoteci. Pokretanje nove igre.\n");
            iskustvo = 0;  // Reset iskustvo if no valid data found
        }
        fclose(file);  // Close the file after reading
    }

    // Determine initial level based on loaded iskustvo
    level = (iskustvo / 100) + 1;

    while (1) {
        // Odabir protivnika
        printf("Odaberite protivnika:\n");
        for (int i = 0; i < broj_protivnika; ++i) {
            printf("%d. %s - Tezina: %d\n", i + 1, protivnici[i].naziv, protivnici[i].tezina);
        }

        int odabir;
        scanf("%d", &odabir);

        if (odabir < 1 || odabir > broj_protivnika) {
            printf("Neispravan odabir protivnika!\n");
            continue;
        }

        Protivnik protivnik = protivnici[odabir - 1];

        // Provjera levela prije borbe s orkom i zmajem
        if ((strcmp(protivnik.naziv, "Ork") == 0 && level < 2) || (strcmp(protivnik.naziv, "Zmaj") == 0 && level < 3)) {
            printf("Ne mozete pobijediti %s. Potrebno je dostici odgovarajuci level.\n", protivnik.naziv);
            continue;
        }

        // Simulacija borbe
        printf("\nBorite se protiv %s!\n", protivnik.naziv);

        // Simulacija pobjede
        printf("Pobjedili ste!\n");

        // Dodjela iskustva za poraz protivnika
        iskustvo += protivnik.tezina;

        // Save experience points to file
        file = fopen("arena.txt", "w+");
        if (file == NULL) {
            printf("Could not open file arena.txt for writing.\n");
            free(protivnici);
            return;
        }
        fprintf(file, "%d\n", iskustvo);
        fclose(file);  // Close the file after writing

        // Provjera je li igrač dostigao dovoljno iskustva za level up
        if (iskustvo >= 100 * level) {
            printf("Cestitamo! Dostigli ste level %d!\n", level + 1);
            level++;
        }

        printf("\nZelite li nastaviti borbu u areni? (1 - Da, 2 - Ne)\n");
        int odabir_borbe;
        scanf("%d", &odabir_borbe);
        if (odabir_borbe != 1) {
            break;
        }
    }

    free(protivnici);
    printf("\nArena minigame zavrsena.\n");
}

