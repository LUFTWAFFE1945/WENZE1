//----------------------------------------------------------------------------------------------------------------------------------------------------//
///////////////////////////////////////////////////////////////// NASTY ////////////////////////////////////////////////////////////////////////////////
//-----------------------------------+-+-+-+----------------------------------------------------------------------------------------------------------//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include<math.h>
#define M 10
#define N 15
#define iloscJedzenia 35
#define G 3 //3 działa

typedef struct _elementyweza
{
    int waz[2];
    struct _elementyweza *next;
}elementyweza;

struct weze
{
    char tab[M][N]; //przestrzen gry
    elementyweza *waz1;
    elementyweza *waz2;
    int ktoryGraczTerazRuszaWeza;  
    int ilejedzenia;
};

struct listaruchow
{
    char ruch;
    struct listaruchow *nast;
};

struct weze wypelnijJedzeniem(struct weze W)
{
    int a=iloscJedzenia;
   while(a!=0)
   {
    int x,y;
    time(NULL);
    x=rand()%(M-1); 
    y=rand()%(N-1);
    if(W.tab[x][y]=='*' || (x==0 && y==0) || (x==M-1 && y==N-1))
    {}
    else
    {W.tab[x][y]='*';
    a--;}
   }
   return W;
}

struct weze planszaPoczatkowa()
{
    struct weze poczatek;
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            poczatek.tab[i][j]=' ';
        }
    }
    
    poczatek.ilejedzenia=iloscJedzenia;
    poczatek.ktoryGraczTerazRuszaWeza=1;
    poczatek.waz1 = (elementyweza*) malloc(sizeof(elementyweza));
    poczatek.waz2 = (elementyweza*) malloc(sizeof(elementyweza));
    poczatek.waz1->waz[0]=0;
    poczatek.waz1->waz[1]=0;
    poczatek.waz1->next=NULL;

    poczatek.waz2->waz[0]=M-1;
    poczatek.waz2->waz[1]=N-1;
    poczatek.waz2->next=NULL;
    return wypelnijJedzeniem(poczatek);

    
}

void wpiszweze(struct weze *plansza)
{
    
    elementyweza *n1 = plansza->waz1;
    elementyweza *n2 = plansza->waz2;
    while(n1!=NULL)
    {
        int x = n1->waz[0];
        int y = n1->waz[1];
        plansza->tab[x][y]='1';
        n1=n1->next;
    }
    while(n2!=NULL)
    {
        plansza->tab[n2->waz[0]][n2->waz[1]]='2';
        n2=n2->next;
    }
}

void wypisz(struct weze W)
{
    printf("\n");
    for(int j=0;j<N;j++)
        {
            printf("----");
        }
    printf("\n");
    wpiszweze(&W);
    for(int i=0;i<M;i++)
    {
        printf("| ");
        for(int j=0;j<N;j++)
        {
            printf("%c | ",W.tab[i][j]);
        }
        printf("\n");
        for(int j=0;j<N;j++)
        {
            printf("----");
        }
        printf("\n");
    }
}


int porownajweze(struct weze baza)
{
    int dlugosc1=1;
    int dlugosc2=1;
    elementyweza *n1 = baza.waz1;
    elementyweza *n2 = baza.waz2;
    while(n1->next!=NULL)
    {
        dlugosc1++;
        n1 = n1->next;

    }
    while(n2->next!=NULL)
    {
        dlugosc2++;
        n2 = n2->next;
    }
    if(dlugosc1>dlugosc2)
    {
        return 1;
    }
    if(dlugosc2>dlugosc1)
    {
        return 2;
    }
    if(dlugosc2==dlugosc1)
    {
        return 0;
    }
}

int sciana(elementyweza *glowa)
{
    if(glowa->waz[0]<=-1 || glowa->waz[1]<=-1 || glowa->waz[0]>=M || glowa->waz[1]>=N)
    {
        return 1;
    }
    else
    return 0;
}

int czyzderzenie(elementyweza *glowa1, elementyweza *glowa2)
{
    int kordynatyglowy[2];
    kordynatyglowy[0] = glowa1->waz[0];
    kordynatyglowy[1] = glowa1->waz[1];
    elementyweza *n1 = glowa1;
    elementyweza *n2 = glowa2;
    int czycostam =0;
    while(n1->next!=NULL)
    {
        if(kordynatyglowy[0] == n1->next->waz[0] && kordynatyglowy[1] == n1->next->waz[1])
        {
            return 1;
        }
        n1=n1->next;
    }
    while(n2!=NULL)
    {
        if(kordynatyglowy[0] == n2->waz[0] && kordynatyglowy[1] == n2->waz[1])
        {
            return 1;
        }
        n2=n2->next;
    }
    return 0;
}

int ocena(struct weze baza)
{
    if(baza.ktoryGraczTerazRuszaWeza == 1)
    {
        if(czyzderzenie(baza.waz1,baza.waz2)==1 || sciana(baza.waz1)==1 )
        return 2;
    }
    else
    {
        if(czyzderzenie(baza.waz2,baza.waz1)==1 || sciana(baza.waz2)==1 )
        return 1;
    }
    if(baza.ilejedzenia==0)
    {
        return porownajweze(baza);
    }
    else return 0;
}

struct listaruchow *pseudoruchy(elementyweza *glowa)
{
    struct listaruchow *ruchy;

        if(glowa->next == NULL)
        {
            ruchy=(struct listaruchow*) malloc(sizeof(struct listaruchow));
            ruchy->ruch = 'N';
            ruchy->nast=(struct listaruchow*) malloc(sizeof(struct listaruchow));
            ruchy->nast->ruch = 'E';
            ruchy->nast->nast=(struct listaruchow*) malloc(sizeof(struct listaruchow));
            ruchy->nast->nast->ruch = 'S';
            ruchy->nast->nast->nast=(struct listaruchow*) malloc(sizeof(struct listaruchow));
            ruchy->nast->nast->nast->ruch = 'W';
            ruchy->nast->nast->nast->nast=NULL;
        }
        else if(glowa->waz[0]-1 == glowa->next->waz[0] && glowa->waz[1] == glowa->next->waz[1])
        {
            ruchy=(struct listaruchow*) malloc(sizeof(struct listaruchow));
            ruchy->ruch = 'E';
            ruchy->nast=(struct listaruchow*) malloc(sizeof(struct listaruchow));
            ruchy->nast->ruch = 'S';
            ruchy->nast->nast=(struct listaruchow*) malloc(sizeof(struct listaruchow));
            ruchy->nast->nast->ruch = 'W';
            ruchy->nast->nast->nast=NULL;
        } 
        else if(glowa->waz[0]+1 == glowa->next->waz[0] && glowa->waz[1] == glowa->next->waz[1])
        {
            ruchy=(struct listaruchow*) malloc(sizeof(struct listaruchow));
            ruchy->ruch = 'E';
            ruchy->nast=(struct listaruchow*) malloc(sizeof(struct listaruchow));
            ruchy->nast->ruch = 'N';
            ruchy->nast->nast=(struct listaruchow*) malloc(sizeof(struct listaruchow));
            ruchy->nast->nast->ruch = 'W';
            ruchy->nast->nast->nast=NULL;
        }
        else if(glowa->waz[0] == glowa->next->waz[0] && glowa->waz[1]-1 == glowa->next->waz[1])
        {
            ruchy=(struct listaruchow*) malloc(sizeof(struct listaruchow));
            ruchy->ruch = 'E';
            ruchy->nast=(struct listaruchow*) malloc(sizeof(struct listaruchow));
            ruchy->nast->ruch = 'S';
            ruchy->nast->nast=(struct listaruchow*) malloc(sizeof(struct listaruchow));
            ruchy->nast->nast->ruch = 'N';
            ruchy->nast->nast->nast=NULL;
        }
        else if(glowa->waz[0] == glowa->next->waz[0] && glowa->waz[1]+1 == glowa->next->waz[1])
        {
            ruchy=(struct listaruchow*) malloc(sizeof(struct listaruchow));
            ruchy->ruch = 'W';
            ruchy->nast=(struct listaruchow*) malloc(sizeof(struct listaruchow));
            ruchy->nast->ruch = 'S';
            ruchy->nast->nast=(struct listaruchow*) malloc(sizeof(struct listaruchow));
            ruchy->nast->nast->ruch = 'N';
            ruchy->nast->nast->nast=NULL;
        }
        
    return ruchy;
}

void ruch(char kierunek, struct weze *plansza)
{
    int xy[2],xy2[2];
    elementyweza *n;


    if(plansza->ktoryGraczTerazRuszaWeza == 1)
    {
        n = plansza->waz1;
    }
    else
    {
        n = plansza->waz2;
    }


    if(kierunek == 'N'){
    xy[0] = n->waz[0]-1;
    xy[1] = n->waz[1];
    } else if(kierunek == 'S'){
    xy[0] = n->waz[0]+1;
    xy[1] = n->waz[1];
    } else if(kierunek == 'W'){
    xy[0] = n->waz[0];
    xy[1] = n->waz[1]-1;
    } else if(kierunek == 'E'){
    xy[0] = n->waz[0];
    xy[1] = n->waz[1]+1;
    }

    if(xy[0]!=-1&&xy[0]!=M&&xy[1]!=-1&&xy[1]!=N)
    {
        if(plansza->tab[xy[0]][xy[1]]=='*')
        {
            elementyweza *nowy = malloc(sizeof(elementyweza));
            nowy->next = n->next;
            n->next = nowy;
            nowy->waz[0] = n->waz[0];
            nowy->waz[1] = n->waz[1];
            n->waz[0] = xy[0];
            n->waz[1] = xy[1];
            plansza->tab[xy[0]][xy[1]]=' ';
            plansza->ilejedzenia--;
        }
        else 
        {
            while(n!=NULL)
            {
                xy2[0] = n->waz[0];
                xy2[1] = n->waz[1];
                n->waz[0] = xy[0];
                n->waz[1] = xy[1];
                xy[0] = xy2[0];
                xy[1] = xy2[1];
                n=n->next;
            }
        }
    }
    else 
        {
            while(n!=NULL)
            {
                xy2[0] = n->waz[0];
                xy2[1] = n->waz[1];
                n->waz[0] = xy[0];
                n->waz[1] = xy[1];
                xy[0] = xy2[0];
                xy[1] = xy2[1];
                n=n->next;
            }
        }
}

int punkty(struct weze plansza)
{
    if(plansza.ktoryGraczTerazRuszaWeza==1)
    {
        if(ocena(plansza)==2)
        {
            return -1000;
        }
        elementyweza *n1 = plansza.waz1;
        int dlugosc1=1;
        while(n1->next!=NULL)
        {
            dlugosc1++;
            n1 = n1->next;
        }

        elementyweza *n2 = plansza.waz2;
        int dlugosc2=1;

        while(n2->next!=NULL)
        {
            dlugosc2++;
            n2 = n2->next;
        }
        
        return dlugosc1-dlugosc2;
    }
    else if(plansza.ktoryGraczTerazRuszaWeza==2)
    {
        if(ocena(plansza)==1)
        {
            return -1000;
        }

        elementyweza *n2 = plansza.waz2;
        int dlugosc2=1;

        while(n2->next!=NULL)
        {
            dlugosc2++;
            n2 = n2->next;
        }

        elementyweza *n1 = plansza.waz1;
        int dlugosc1=1;

        while(n1->next!=NULL)
        {
            dlugosc1++;
            n1 = n1->next;
        }

        return dlugosc2-dlugosc1;
        
    }
}


struct weze zrobkopie(struct weze plansza)
{
    elementyweza *n1 = plansza.waz1;
    elementyweza *n2 = plansza.waz2;

    elementyweza *lastelement1 = NULL;
    elementyweza *lastelement2 = NULL;
    
    elementyweza *glowa1 = NULL;
    elementyweza *glowa2 = NULL;

    struct weze kopia = plansza;
    
    kopia.waz1 = NULL;
    kopia.waz2 = NULL;
    
    while(n1!=NULL)
    {
        elementyweza *element = (elementyweza*) malloc(sizeof(elementyweza));
        element->next=NULL;
        if(lastelement1==NULL)
            glowa1 = element;
        else
            lastelement1->next = element;
        lastelement1 = element;

        element->waz[0] = n1->waz[0];
        element->waz[1] = n1->waz[1];
        n1=n1->next;
    }
    kopia.waz1 = glowa1;

 while(n2!=NULL)
    {
        elementyweza *element2 = (elementyweza*) malloc(sizeof(elementyweza));
        element2->next=NULL;
        if(lastelement2==NULL)
            glowa2 = element2;
        else
            lastelement2->next = element2;
        lastelement2 = element2;

        element2->waz[0] = n2->waz[0];
        element2->waz[1] = n2->waz[1];
        n2=n2->next;
    }
    kopia.waz2 = glowa2;

    return kopia;
}

int alfabeta( int glebokosc , int A, int B, struct weze plansza)
{
    if(plansza.ktoryGraczTerazRuszaWeza==1)
            plansza.ktoryGraczTerazRuszaWeza=2;
        else 
            plansza.ktoryGraczTerazRuszaWeza=1;


    elementyweza *n;
    if(plansza.ktoryGraczTerazRuszaWeza == 1)
    {
        n=plansza.waz1;
    }
    else
        n=plansza.waz2;

    if(glebokosc == 0)
    {
        //printf("%d\n", punkty(plansza));
        return punkty(plansza);
    }
    int ocenawezla = -10000;
    int nowaocena;
    
    for(struct listaruchow *lr = pseudoruchy(n), *ptr=lr;lr;lr=lr->nast,free(ptr), ptr=lr)
    {
        struct weze dziecko=zrobkopie(plansza);
        
        ruch(lr->ruch,&dziecko);

        nowaocena = alfabeta(glebokosc-1, A , B , dziecko);

        if (nowaocena > ocenawezla)
        ocenawezla = nowaocena; 

        if(ocenawezla>A)
        A=ocenawezla;

        if(A>B)
        {
            //zwolnienie listy ruchw do konca
            break;
        }
        
    }




    return ocenawezla;
}

char WSAD(char c)
{
    if(c=='s')
    {
        return 'S';
    }
    if(c=='a')
    {
        return 'W';
    }
    if(c=='w')
    {
        return 'N';
    }
    if(c=='d')
    {
        return 'E';
    }
}


int main(int argc, char *argv[]) 
{
    struct weze plansza=planszaPoczatkowa();
    char str[1];
    
    wypisz(plansza);
    
    while(ocena(plansza)==0)
    {
         if(plansza.ktoryGraczTerazRuszaWeza==1)
        {
         printf("W którą stronę chcesz się poruszyć Graczu nr %d?\n", plansza.ktoryGraczTerazRuszaWeza);
         scanf("%s", str);
         char RUCH = WSAD(str[0]);
         ruch( RUCH ,&plansza);
         wypisz(plansza);
        }
        if(ocena(plansza)==1)
        {
            printf("\nBrawo! Gracz I wygrywa partię!\n\n");
            break;
        }
        if(ocena(plansza)==2)
        {
            printf("\nBrawo! Gracz II wygrywa partię!\n\n");
            break;
        }

        if(plansza.ktoryGraczTerazRuszaWeza==2)
        {
            struct listaruchow *waz2rusza = pseudoruchy(plansza.waz2);
            int najlepiej=-10000;
            char ruchwaz2;
            int ab;

            while(waz2rusza != NULL)
            {
                struct weze dziecko = zrobkopie(plansza);
                ruch(waz2rusza->ruch , &dziecko);

                if(ocena(dziecko)==2)
                {
                    ruchwaz2=waz2rusza->ruch;
                    break;
                }
                else if(ocena(dziecko)!=1)
                {

                    ab = alfabeta(G,-10000,10000,dziecko);

                    printf("%c%d\n",waz2rusza->ruch, ab );
                    if( ab > najlepiej )
                    {
                        najlepiej=ab;
                        ruchwaz2=waz2rusza->ruch;
                    }
                }

                waz2rusza = waz2rusza->nast;
            }
            
            ruch(ruchwaz2,&plansza);
            wypisz(plansza);
        }
        if(ocena(plansza)==1)
        {
            printf("\nBrawo! Gracz I wygrywa partię!\n\n");
            break;
        }
        if(ocena(plansza)==2)
        {
            printf("\nBrawo! Gracz II wygrywa partię!\n\n");
            break;
        }

        if(plansza.ktoryGraczTerazRuszaWeza==1)
            plansza.ktoryGraczTerazRuszaWeza=2;
        else 
            plansza.ktoryGraczTerazRuszaWeza=1;
    }
    return 0;
}