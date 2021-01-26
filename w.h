
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define M 5 //wiersze planszy
#define N 20 //kolunny planszy
#define iloscJedzenia 20


typedef struct waz{
int r; 
int c; 
int dlugosc;
struct waz*nast; 
struct waz*poprz; 
}waz;

typedef struct ruch{
    char kierunek;
    struct ruch*nast;
    struct ruch*poprz;
}ruch;

typedef struct baza{
ruch *lista;
waz *waz1; 
waz *waz2;
char plansza[M][N];
}baza;

waz * tworz_glowe_poczatkowa(int r, int c);
baza* tworzymy_baze();
int dlugosc(waz*tesciowa);
int pokaz_wynik(baza*wszystko);
void zwolnij_liste(ruch*lista);
void zwolnij_weza(waz*snake);
void zwolnij_baze(baza*Sbaza);
void wypisz(char plansza[M][N]);
void uzupelnij_plansze_jedzeniem(baza*Sbaza);
void uzupelnij_plansze_wenzami(baza*Sbaza);
ruch* generuj_liste_ruchow(waz*snake);
void usun_ostatni_element(baza*Sbaza,waz*snake);
void pokaz_liste_ruchow(ruch*tesciowa);









 


