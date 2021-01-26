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
char znak;

for(int p=1;p<1000;p++){//rusza sie pierwszy na p parz
    if (p%2==1){ //waz 1 czyli my 
    scanf(" %c",&znak);  
    ruch*lista;
    lista=generuj_liste_ruchow(wszystko,wszystko->waz1);
   // pokaz_liste_ruchow(lista);
    ruszanko(znak,wszystko);    
    wypisz(wszystko->plansza);
    } 
     
    if (p%2==0){ //rusza sie drugi czyli sterowany przez nas
    ruch*lista;
    lista=generuj_liste_ruchow(wszystko,wszystko->waz2);
    pokaz_liste_ruchow(lista);
    wypisz(wszystko->plansza);
    }
    printf("przewaga :%d",ocena(wszystko));
}



zwolnij_baze(wszystko);
printf("Main is done.\n");
}
