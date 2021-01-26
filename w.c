#include "w.h"

waz *tworz_glowe_poczatkowa(int r, int c)
{
    waz *snake = (waz *)malloc(sizeof(waz));
    snake->r = r;
    snake->c = c;
    snake->nast = NULL;
    snake->poprz = NULL;

    return snake;
}

baza *tworzymy_baze()
{
    baza *Sbaza = (baza *)malloc(sizeof(baza));
    Sbaza->waz1 = tworz_glowe_poczatkowa(0, 0);
    Sbaza->waz2 = tworz_glowe_poczatkowa(M - 1, N - 1);
    Sbaza->lista = generuj_liste_ruchow(Sbaza, Sbaza->waz1);
    Sbaza->kolejka = 1;
    return Sbaza;
}

ruch *generuj_liste_ruchow(baza*wszystko,waz *snake)
{
    ruch *lista = (ruch *)malloc(sizeof(ruch));
    if (snake->r != 0)
    if(wszystko->plansza[wszystko->waz1->r-1][wszystko->waz1->c]!='X')
    if(wszystko->plansza[wszystko->waz1->r-1][wszystko->waz1->c]!='Y')
    {
        if (lista != NULL)
        {
            ruch *zaczep = lista;
            while (zaczep->nast != NULL)
            {
                zaczep = zaczep->nast;
            }
            ruch *doczep = (ruch *)malloc(sizeof(ruch));
            zaczep->nast = doczep;
            doczep->poprz = zaczep;
            doczep->nast = NULL;
            doczep->kierunek = 'G';
        }
        else
        {
            lista->kierunek = 'G';
            lista->nast = NULL;
            lista->poprz = NULL;
        }
    }
    if (snake->r != M - 1)
    if(wszystko->plansza[wszystko->waz1->r+1][wszystko->waz1->c]!='X')
    if(wszystko->plansza[wszystko->waz1->r+1][wszystko->waz1->c]!='Y')
    {
        if (lista != NULL)
        {
            ruch *zaczep;
            zaczep = lista;
            while (zaczep->nast != NULL)
            {
                zaczep = zaczep->nast;
            }
            ruch *doczep = (ruch *)malloc(sizeof(ruch));
            zaczep->nast = doczep;
            doczep->poprz = zaczep;
            doczep->nast = NULL;
            doczep->kierunek = 'D';
        }
        else
        {
            lista->kierunek = 'D';
            lista->nast = NULL;
            lista->poprz = NULL;
        }
    }
    if (snake->c != 0)
    if(wszystko->plansza[wszystko->waz1->r][wszystko->waz1->c-1]!='X')
    if(wszystko->plansza[wszystko->waz1->r][wszystko->waz1->c-1]!='Y')
    {
        if (lista != NULL)
        {
            ruch *zaczep = lista;
            while (zaczep->nast != NULL)
            {
                zaczep = zaczep->nast;
            }
            ruch *doczep = (ruch *)malloc(sizeof(ruch));
            zaczep->nast = doczep;
            doczep->poprz = zaczep;
            doczep->nast = NULL;
            doczep->kierunek = 'L';
        }
        else
        {
            lista->kierunek = 'L';
            lista->nast = NULL;
            lista->poprz = NULL;
        }
    }
    if (snake->c != N - 1)
    if(wszystko->plansza[wszystko->waz1->r][wszystko->waz1->c+1]!='X')
    if(wszystko->plansza[wszystko->waz1->r][wszystko->waz1->c+1]!='Y')
    {
        if (lista != NULL)
        {
            ruch *zaczep = lista;
            while (zaczep->nast != NULL)
            {
                zaczep = zaczep->nast;
            }
            ruch *doczep = (ruch *)malloc(sizeof(ruch));
            zaczep->nast = doczep;
            doczep->poprz = zaczep;
            doczep->nast = NULL;
            doczep->kierunek = 'P';
        }
        else
        {
            lista->kierunek = 'P';
            lista->nast = NULL;
            lista->poprz = NULL;
        }
    }
    return (lista);
}

int dlugosc(waz *tesciowa)
{
    int n = 0;
    waz *snake = tesciowa;
    while (snake != NULL)
    {
        n++;
        snake = snake->nast;
    }
    return n;
}

int pokaz_wynik(baza *wszystko)
{ //1 kiedy wygrywa 1(x), 2 kiedy wygrywa(y) 2, 3 kiedy remis
    int x = dlugosc(wszystko->waz1);
    int y = dlugosc(wszystko->waz2);
    if (x > y)
        return 1;
    else if (x < y)
        return 2;
    else
        return 0;
}

void zwolnij_liste(ruch *lista)
{
    ruch *n = lista;
    while (lista != NULL)
    {
        n = lista->nast;
        free(lista);
        lista = n;
    }
}

void zwolnij_weza(waz *snake)
{
    waz *n = snake;
    while (snake != NULL)
    {
        n = snake->nast;
        free(snake);
        snake = n;
    }
}

void zwolnij_baze(baza *Sbaza)
{
    zwolnij_weza(Sbaza->waz1);
    zwolnij_weza(Sbaza->waz2);
    zwolnij_liste(Sbaza->lista);
    free(Sbaza);
}

void wypisz(char plansza[M][N])
{
    for (int i = 0; i < M; i++)
    {
        printf("| ");
        for (int j = 0; j < N; j++)
        {
            printf("%c | ", plansza[i][j]);
        }
        printf("\n");
        for (int j = 0; j < N; j++)
        {
            printf("----");
        }
        printf("\n");
    }
}

void uzupelnij_plansze_jedzeniem(baza *Sbaza)
{
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
        {
            Sbaza->plansza[i][j] = ' ';
        }
    for (int i = 0; i < iloscJedzenia; i++)
    {
        int x, y;
        time(NULL);
        x = rand() % (M); // losowe
        y = rand() % (N); // loswe
        //printf("%d  %d\n",x,y);
        Sbaza->plansza[x][y] = '*';
    }
}

void uzupelnij_plansze_wenzami(baza *Sbaza)
{
    waz *x;
    x = Sbaza->waz1;
    waz *y;
    y = Sbaza->waz2;
    while (x != NULL)
    {
        Sbaza->plansza[x->r][x->c] = 'X';
        x = x->nast;
    }
    while (y != NULL)
    {
        Sbaza->plansza[y->r][y->c] = 'Y';
        y = y->nast;
    }
}

void usun_ostatni_element(baza *Sbaza, waz *snake)
{
    waz *glowa = snake;
    while (glowa->nast != NULL)
    {
        glowa = glowa->nast;
    }
    Sbaza->plansza[glowa->r][glowa->c] = ' ';
    glowa->poprz->nast = NULL;
    free(glowa);
}

void pokaz_liste_ruchow(ruch *tesciowa)
{
    while (tesciowa != NULL)
    {
        printf("%c\n", tesciowa->kierunek);
        tesciowa = tesciowa->nast;
    }
}

int gora(baza*wszystko,waz*snake){

if(wszystko->plansza[snake->r-1][snake->c]=='*'){
printf("+1 byczku\n");
    waz*stara_glowa=snake;
    waz*nowa_glowa = (waz*) malloc(sizeof(waz));
    nowa_glowa->r = stara_glowa->r-1;
    nowa_glowa->c = stara_glowa->c;
    nowa_glowa->nast = stara_glowa; 
    stara_glowa->poprz = nowa_glowa;
    nowa_glowa->poprz = NULL;
    snake=nowa_glowa;
    }
else{ 
    waz*stara_glowa=wszystko->waz1;
    waz*nowa_glowa = (waz*) malloc(sizeof(waz));
    nowa_glowa->r = stara_glowa->r-1;
    nowa_glowa->c = stara_glowa->c;
    nowa_glowa->nast = stara_glowa; 
    stara_glowa->poprz = nowa_glowa;
    nowa_glowa->poprz = NULL;                    
    wszystko->waz1=nowa_glowa;
    usun_ostatni_element(wszystko,snake);
    }
}

int dol(baza*wszystko,waz*snake){

if(wszystko->plansza[snake->r+1][snake->c]=='*'){
printf("+1 byczku\n");
    waz*stara_glowa=snake;
    waz*nowa_glowa = (waz*) malloc(sizeof(waz));
    nowa_glowa->r = stara_glowa->r+1;
    nowa_glowa->c = stara_glowa->c;
    nowa_glowa->nast = stara_glowa; 
    stara_glowa->poprz = nowa_glowa;
    nowa_glowa->poprz = NULL;
    snake=nowa_glowa;
    }
else{ 
    waz*stara_glowa=wszystko->waz1;
    waz*nowa_glowa = (waz*) malloc(sizeof(waz));
    nowa_glowa->r = stara_glowa->r+1;
    nowa_glowa->c = stara_glowa->c;
    nowa_glowa->nast = stara_glowa; 
    stara_glowa->poprz = nowa_glowa;
    nowa_glowa->poprz = NULL;                    
    wszystko->waz1=nowa_glowa;
    usun_ostatni_element(wszystko,snake);
    }
}

int lewo(baza*wszystko,waz*snake){

if(wszystko->plansza[snake->r][snake->c-1]=='*'){
printf("+1 byczku\n");
    waz*stara_glowa=snake;
    waz*nowa_glowa = (waz*) malloc(sizeof(waz));
    nowa_glowa->r = stara_glowa->r;
    nowa_glowa->c = stara_glowa->c-1;
    nowa_glowa->nast = stara_glowa; 
    stara_glowa->poprz = nowa_glowa;
    nowa_glowa->poprz = NULL;
    snake=nowa_glowa;
    }
else{ 
    waz*stara_glowa=snake;
    waz*nowa_glowa = (waz*) malloc(sizeof(waz));
    nowa_glowa->r = stara_glowa->r;
    nowa_glowa->c = stara_glowa->c-1;
    nowa_glowa->nast = stara_glowa; 
    stara_glowa->poprz = nowa_glowa;
    nowa_glowa->poprz = NULL;                    
    snake=nowa_glowa;
    usun_ostatni_element(wszystko,snake);
    }
}

int prawo(baza*wszystko,waz*snake){

if(wszystko->plansza[snake->r][snake->c+1]=='*'){
printf("+1 byczku\n");
    waz*stara_glowa=snake;
    waz*nowa_glowa = (waz*) malloc(sizeof(waz));
    nowa_glowa->r = stara_glowa->r;
    nowa_glowa->c = stara_glowa->c+1;
    nowa_glowa->nast = stara_glowa; 
    stara_glowa->poprz = nowa_glowa;
    nowa_glowa->poprz = NULL;
    snake=nowa_glowa;
    }
else{ 
    waz*stara_glowa=wszystko->waz1;
    waz*nowa_glowa = (waz*) malloc(sizeof(waz));
    nowa_glowa->r = stara_glowa->r;
    nowa_glowa->c = stara_glowa->c+1;
    nowa_glowa->nast = stara_glowa; 
    stara_glowa->poprz = nowa_glowa;
    nowa_glowa->poprz = NULL;                    
    wszystko->waz1=nowa_glowa;
    usun_ostatni_element(wszystko,snake);
    }
}

waz*kopiuj_weza(waz*snake){
    waz *zwrot = (waz *)malloc(sizeof(waz));
    zwrot=NULL;
    while (snake != NULL)
    {
    waz *czlon = (waz *)malloc(sizeof(waz));
    czlon->r=snake->r;
    czlon->c=snake->c;
    if (zwrot==NULL){
    zwrot=czlon;
    }
    else{
        while (zwrot->nast != NULL)
            {
            zwrot = zwrot->nast;
            }
        zwrot = czlon;
        snake = snake->nast; 
    }
    }
    return zwrot;
}

void pokaz_liste_wenza(waz*tesciowa){
    while(tesciowa!=NULL){
    printf("x-%d,y-%d\n",tesciowa->r,tesciowa->c);
    tesciowa=tesciowa->nast;
    }

}

baza* kopiuj_baze(baza*Sbaza){
baza *zwrot = (baza *)malloc(sizeof(baza));
zwrot->waz1 = kopiuj_weza(Sbaza->waz1);
zwrot->waz2 = kopiuj_weza(Sbaza->waz2);
zwrot->kolejka = Sbaza -> kolejka;
for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
        zwrot->plansza[i][j] = Sbaza->plansza[i][j];
return zwrot;
}

void ruszanko(char kierunek, baza *Sbaza)
{
    baza*kopia=kopiuj_baze(Sbaza);
    printf("lista w kopii waz1:\n");
    pokaz_liste_wenza(kopia->waz1);
    printf("lista w kopii waz2:\n");
    pokaz_liste_wenza(kopia->waz2);

    waz *teraz;
    if (Sbaza->kolejka % 2 == 1)
    { //rusza sie pierwszy jak nieparzyste
        teraz = Sbaza->waz1;
        
    }
    if (Sbaza->kolejka % 2 == 0)
    { //rusza sie drugi jak parzyste
        teraz = Sbaza->waz2;
    }

    if(kierunek=='G'){
        gora(Sbaza,teraz);
     }
        else if(kierunek=='L'){
        lewo(Sbaza,teraz);
        }
        else if(kierunek=='D'){
       dol(Sbaza,teraz);
        }
        else if(kierunek=='P'){
       prawo(Sbaza,teraz);
        }



















    
}

/*

struct ocena negmax(struct szachownica* sz, char glebokosc, int alfa, int beta)
{
 if (!glebokosc)
 return ocena(sz);
 
 int ocenawezla = -PRZEGRANA;
 
 for(struct listaruchow *lr = pseudoposuniecia(sz), *ptr = lr; lr; lr = lr->nast, free(ptr), ptr = lr)
 {
 dziecko = wykonajruch(sz, lr->ruch);
 nowaocena = -negmax(&dziecko, glebokosc - 1, -beta, -alfa);
 
 if (nowaocena > ocenawezla)
 ocenawezla = nowaocena; 
 
 if (ocenawezla > alfa)
 alfa = ocenawezla;
 
 if (alfa > beta) 
 {
 // zwolninenie listy ruchów do końca
 break;
 }
 }
 return ocenawezla;
}
*/
