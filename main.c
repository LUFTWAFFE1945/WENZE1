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


for(int p=0;p<2;p++){
    if (p%2==0){  //rusza sie pierwszys
    ruch*lista;
    lista=generuj_liste_ruchow(wszystko->waz1);
    pokaz_liste_ruchow(lista);
    } 
     
    if (p%2==1){ //rusza sie drugi czyli sterowany przez nas
    ruch*lista;
    lista=generuj_liste_ruchow(wszystko->waz2);
    pokaz_liste_ruchow(lista);
    }
}


pokaz_wynik(wszystko);
zwolnij_baze(wszystko);
printf("Main is done.\n");
}
