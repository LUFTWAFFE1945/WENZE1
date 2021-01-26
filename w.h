
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
int kolejka;
ruch *lista;
waz *waz1; 
waz *waz2;
char plansza[M][N];
}baza;


void pokaz_liste_wenza(waz*tesciowa);
waz * tworz_glowe_poczatkowa(int r, int c);
baza* tworzymy_baze();
int dlugosc(waz*tesciowa);
int ocena(baza*wszystko);
void zwolnij_liste(ruch*lista);
void zwolnij_weza(waz*snake);
void zwolnij_baze(baza*Sbaza);
void wypisz(char plansza[M][N]);
void uzupelnij_plansze_jedzeniem(baza*Sbaza);
void uzupelnij_plansze_wenzami(baza*Sbaza);
ruch* generuj_liste_ruchow(baza*wszystko);
void usun_ostatni_element(baza*Sbaza,waz*snake);
void pokaz_liste_ruchow(ruch*tesciowa);
int gora(baza*wszystko,waz*snake);
int dol(baza*wszystko,waz*snake);
int lewo(baza*wszystko,waz*snake);
int prawo(baza*wszystko,waz*snake);
baza* ruszanko(char kierunek, baza *Sbaza);
baza* kopiuj_baze(baza*Sbaza);





 


