#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "w.h"
#define glembokosc 3

int negmax(baza* sz, char glebokosc, int alfa, int beta)
{
 if (!glebokosc)
 return ocena(sz);

 
 
 
 int ocenawezla = -1000;
 
 for(ruch *lr = generuj_liste_ruchow(sz), *ptr = lr; lr; lr = lr->nast, free(ptr), ptr = lr)
 {
    baza*dziecko=kopiuj_baze(sz);
    dziecko = ruszanko(lr->kierunek, dziecko);
    int nowaocena = -negmax(dziecko, glebokosc - 1, -beta, -alfa);
 
 if (nowaocena > ocenawezla)
 ocenawezla = nowaocena; 
 
 if (ocenawezla > alfa)
 alfa = ocenawezla;
 
 if (alfa > beta) 
 {
 
 break;
 }
 }
 
 return ocenawezla;
}
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
    lista=generuj_liste_ruchow(wszystko);
   // pokaz_liste_ruchow(lista);
    ruszanko(znak,wszystko);    
    wypisz(wszystko->plansza);
    } 
     
    if (p%2==0){ //rusza sie drugi czyli sterowany przez nas
    ruch*lista;
    ruch *wybrany;
    int najwekszy = -10000;
    lista=generuj_liste_ruchow(wszystko);
    while(lista->nast != NULL)
    {
        int ocenka =0;
        baza*kopia= kopiuj_baze(wszystko);
        kopia = ruszanko(lista->kierunek,kopia);
        ocenka=negmax(kopia, glembokosc, -10000, 10000);
        if (ocenka>najwekszy){
            ocenka=najwekszy;
            wybrany=lista;
        }
        lista=lista->nast;
    }
    ruszanko(wybrany->kierunek, wszystko);
    wypisz(wszystko->plansza);
    }
    printf("przewaga :%d",ocena(wszystko));
}



zwolnij_baze(wszystko);
printf("Main is done.\n");
}
