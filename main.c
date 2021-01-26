#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "w.h"

int main(){
baza*wszystko=tworzymy_baze();
uzupelnij_plansze_jedzeniem(wszystko);
uzupelnij_plansze_wenzami(wszystko);
wypisz(wszystko->plansza);


for(int p=0;p<10;p++){
    if (p%2==0){  //rusza sie pierwszy na nueparzyste
    ruch*lista;
    lista=generuj_liste_ruchow(wszystko,wszystko->waz1);
    pokaz_liste_ruchow(lista);
    ruszanko('D',wszystko);
    uzupelnij_plansze_wenzami(wszystko);
    wypisz(wszystko->plansza);
    } 
     
    if (p%2==1){ //rusza sie drugi czyli sterowany przez nas
    ruch*lista;
    lista=generuj_liste_ruchow(wszystko,wszystko->waz2);
    pokaz_liste_ruchow(lista);
    wypisz(wszystko->plansza);
    }
}
pokaz_wynik(wszystko);
zwolnij_baze(wszystko);
printf("Main is done.\n");
}
