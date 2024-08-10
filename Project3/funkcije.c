#define _CRT_SECURE_NO_WARNINGS
#include "header.h"

#define OPIS 256
#define GOBLIN 15
#define ORK 25
#define ZMAJ 50

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
    char scena_opis[OPIS], opcija_opis_1[OPIS], opcija_opis_2[OPIS];

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


static long velicina_dat(const char* filename) {
    FILE* file = fopen(filename, "r"); // Open file in binary mode
    if (file == NULL) {
        printf("Greska pri otvaranju fajla.\n");
        return -1;
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fclose(file);

    return size;
}
static void izbrisi_minigame() {
    const char* ime_datoteke = "arena_save.txt";

    if (remove(ime_datoteke) == 0) {
        printf("Save file '%s' has been deleted successfully.\n", ime_datoteke);
    }
    else {
        printf("Error: Could not delete save file '%s'.\n", ime_datoteke);
    }
}
static int usporedi_tezinu(const void* a, const void* b) {
    return ((Protivnik*)b)->tezina - ((Protivnik*)a)->tezina;
}
static void ucitaj_arenu(int* iskustvo) {
    const char* ime_datoteke = "arena_save.txt";

    FILE* file = fopen(ime_datoteke, "r");
    if (file == NULL) {
        printf("Neuspjesno otvaranje datoteke %s za citanje.\n", ime_datoteke);
        return;
    }

    if (fscanf(file, "%d", iskustvo) != 1) {
        *iskustvo = 0;
    }
    fclose(file);
    printf("Spremljeno iskustvo iz datoteke %s: %d\n\n", ime_datoteke, *iskustvo);
    long file_size = velicina_dat("arena_save.dat");
    if (file_size != -1) {
        printf("Velicina fajla pri cuvanju je %ld bajtova.\n", file_size);
    }
}
static void spremi_minigame(int iskustvo) {
    const char* ime_datoteke = "arena_save.txt";

    FILE* file = fopen(ime_datoteke, "w+");
    if (file == NULL) {
        printf("Nije moguce otvoriti datoteku %s za pisanje.\n", ime_datoteke);
        return;
    }


    fprintf(file, "%d\n", iskustvo);
    fclose(file);
    long file_size = velicina_dat("arena_save.dat");
    if (file_size != -1) {
        printf("Velicina fajla pri cuvanju je %ld bajtova.\n", file_size);
    }
}

void arena_minigame(Igrac* igrac) {
    Protivnik* protivnici = (Protivnik*)malloc(3 * sizeof(Protivnik));
    if (protivnici == NULL) {
        printf("Greska prilikom alociranja memorije za protivnike.\n");
        return;
    }

    strncpy(protivnici[0].naziv, "Goblin", MAX_IME);
    protivnici[0].tezina = GOBLIN;
    strncpy(protivnici[1].naziv, "Ork", MAX_IME);
    protivnici[1].tezina = ORK;
    strncpy(protivnici[2].naziv, "Zmaj", MAX_IME);
    protivnici[2].tezina = ZMAJ;

    qsort(protivnici, 3, sizeof(Protivnik), usporedi_tezinu);

    int iskustvo = 0;
    int level = 1;

    printf("\nDobrodosli u arenu!\n");
    printf("\n1. Nova igra\t2. Ucitaj igru\t3. Izbrisi spremanje\n");
    int igra = 0;
    scanf("%d", &igra);

    if (igra == 2) {
        ucitaj_arenu(&iskustvo);
    }
    else if (igra == 3) {
        izbrisi_minigame();
        free(protivnici);
        return;
    }

    level = (iskustvo / 100) + 1;

    while (1) {
        printf("Odaberite protivnika:\n");
        for (int i = 0; i < 3; ++i) {
            printf("%d. %s - Tezina: %d\n", i + 1, protivnici[i].naziv, protivnici[i].tezina);
        }

        int odabir;
        scanf("%d", &odabir);

        if (odabir < 1 || odabir > 3) {
            printf("Neispravan odabir protivnika!\n");
            continue;
        }

        Protivnik protivnik = protivnici[odabir - 1];

        if ((strcmp(protivnik.naziv, "Ork") == 0 && level < 2) || (strcmp(protivnik.naziv, "Zmaj") == 0 && level < 3)) {
            printf("Ne mozete pobijediti %s. Potrebno je dostici odgovarajuci level.\n", protivnik.naziv);
            continue;
        }

        printf("\nBorite se protiv %s!\n", protivnik.naziv);
        printf("Pobjedili ste!\n");
        iskustvo += protivnik.tezina;

        spremi_minigame(iskustvo);

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
    protivnici = NULL;
}
