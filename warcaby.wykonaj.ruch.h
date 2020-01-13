#include <stdlib.h>
#include <string.h>
#include <stdio.h>

listazbic* dodaj_zbicie(listazbic *zbi, pole p){
    listazbic *t = (listazbic *)calloc(1, sizeof(listazbic));
    
    t->point = p;
    t->nast = NULL;

    if(zbi == NULL){
        return t;
    }

    listazbic *tmp = zbi;
    while(tmp->nast != NULL){
        tmp = tmp->nast;
    } 

    tmp->nast = t;
    return zbi;
}


void zniszczostatniebicie(listazbic* z){
    if(z == NULL) return;

    listazbic *tmp = z, *poprzedni = NULL;
    while (tmp->nast != NULL)
    {
        poprzedni = tmp;
        tmp = tmp->nast;
    }

    if(poprzedni != NULL) poprzedni->nast = NULL;
    free(tmp);
}


void zniszczzbicia(listazbic* z){
    if(z == NULL) return;

    listaruchow *tmp;

    while(z != NULL){
        tmp = z;
        z = z->nast;
        free(tmp);
    }
}


int ilosc_zbic(listazbic* z){
    int i=0;
    if(z == NULL){
        return i;
    }

    listazbic *tmp = z;
    while(tmp->nast != NULL){
        tmp = tmp->nast;
        i++;
    } 

    return i;
}

listaruchow* dodaj_ruch(listaruchow *l, ruch r){
    listaruchow *t = (listaruchow *)calloc(1, sizeof(listaruchow));
    
    t->r = r;
    t->nast = NULL;

    if(l == NULL){
        return t;
    }

    listaruchow *tmp = l;
    while(tmp->nast != NULL){
        tmp = tmp->nast;
    } 

    tmp->nast = t;
    return l;
}


void zniszczliste(listaruchow* l){
    if(l == NULL) return;

    listaruchow *tmp;

    while(l != NULL){
        tmp = l;
        l = l->nast;
        free(tmp);
    }
}


void zniszczostatni(listaruchow* l){
    if(l == NULL) return;

    listaruchow *tmp = l, *poprzedni = NULL;
    while (tmp->nast != NULL)
    {
        poprzedni = tmp;
        tmp = tmp->nast;
    }

    if(poprzedni != NULL) poprzedni->nast = NULL;
    free(tmp);
}


/*###########################################################################################*/



void ruch_zwykly_czarny(szachownica *sz, listaruchow *l){
   
   for(int i=1; i<sz->liczba_czarnych; i++){
            if(sz->plansza[sz->pozycje_czarnych[i][0]-1][sz->pozycje_czarnych[i][1]+1] == pusty){
                ruch r;
                r.z.wiersz = sz->pozycje_czarnych[i][0];
                r.z.kolumna = sz->pozycje_czarnych[i][1];
                r.na.wiersz = sz->pozycje_czarnych[i][0]-1;
                r.na.kolumna = sz->pozycje_czarnych[i][1]+1;
                r.czy_bicie = 0;
                dodaj_ruch(l, r);
            }

            if(sz->plansza[sz->pozycje_czarnych[i][0]-1][sz->pozycje_czarnych[i][1]-1] == pusty){
                ruch r;
                r.z.wiersz = sz->pozycje_czarnych[i][0];
                r.z.kolumna = sz->pozycje_czarnych[i][1];
                r.na.wiersz = sz->pozycje_czarnych[i][0]-1;
                r.na.kolumna = sz->pozycje_czarnych[i][1]-1;
                r.czy_bicie = 0;
                dodaj_ruch(l, r);
            }
        }
}


void ruch_zwykly_bialy(szachownica *sz, listaruchow *l){
    
    for(int i=1; i<sz->liczba_bialych; i++){
            if(sz->plansza[sz->pozycje_bialych[i][0]+1][sz->pozycje_bialych[i][1]+1] == pusty){
                ruch r;
                r.z.wiersz = sz->pozycje_bialych[i][0];
                r.z.kolumna = sz->pozycje_bialych[i][1];
                r.na.wiersz = sz->pozycje_bialych[i][0]+1;
                r.na.kolumna = sz->pozycje_bialych[i][1]-1;
                r.czy_bicie = 0;
                dodaj_ruch(l, r);
            }

            if(sz->plansza[sz->pozycje_bialych[i][0]+1][sz->pozycje_bialych[i][1]-1] == pusty){
                ruch r;
                r.z.wiersz = sz->pozycje_bialych[i][0];
                r.z.kolumna = sz->pozycje_bialych[i][1];
                r.na.wiersz = sz->pozycje_bialych[i][0]+1;
                r.na.kolumna = sz->pozycje_bialych[i][1]+1;
                r.czy_bicie = 0;
                dodaj_ruch(l, r);
            }
    }
}


int bicie_obowiazkowe_czarne(szachownica *sz, listaruchow* l){
        for(int i=1; i<sz->liczba_czarnych; i++){
            bicie_czarnym(sz, l, sz->pozycje_czarnych[i][0], sz->pozycje_czarnych[i][1], sz->pozycje_czarnych[i][0], sz->pozycje_czarnych[i][1], NULL, 0); 
        }
}


int bicie_czarnym(szachownica *sz, listaruchow *l, int x, int y, int x_z, int y_z, listazbic * zbicia, int czyCosZbil){
    int wartownik = 0;
    if(sz->plansza[x-1][y-1] == bialy && sz->plansza[x-2][y-2] == pusty){
        wartownik += 1;
        pole p;
        listazbic * zbi = NULL;

        memcpy(zbi, zbicia, ilosc_zbic(zbicia));
        zbi = dodaj_zbicie(zbi, p);

        bicie_czarnym(sz, l, x-2, y-2, x_z, y_z, zbi, 1);
    }

    if(sz->plansza[x-1][y+1] == bialy && sz->plansza[x-2][y+2] == pusty){
        wartownik += 1;
        pole p;
        listazbic * zbi = NULL;

        memcpy(zbi, zbicia, iloscZbic(zbicia));
        zbi = dodaj_zbicie(zbi, p);

        bicie_bialym(sz, l, x-2, y+2, x_z, y_z, zbi, 1);
    }

    if(wartownik == 0 && czyCosZbil != 0){
        ruch r;
        r.z.wiersz = x_z;
        r.z.kolumna = y_z;
        r.na.wiersz = x;
        r.na.kolumna = y;
        r.zbicie = zbicia;
        r.czy_bicie = 1;
        
        l = dodaj_ruch(l, r);
    }

    else if (zbicia != NULL){
        zniszczostatniebicie(zbicia);
    }
}


int bicie_obowiazkowe_biale(szachownica *sz, listaruchow* l){
        for(int i=1; i<sz->liczba_bialych; i++){
            bicie_bialym(sz, l, sz->pozycje_bialych[i][0], sz->pozycje_bialych[i][1], sz->pozycje_bialych[i][0], sz->pozycje_bialych[i][1], NULL, 0); 
        }
}


int bicie_bialym(szachownica *sz, listaruchow *l, int x, int y, int x_z, int y_z, listazbic * zbicia, int czyCosZbil){
    int wartownik = 0;
    if(sz->plansza[x+1][y-1] == czarny && sz->plansza[x+2][y-2] == pusty){
        wartownik += 1;
        pole p;
        listazbic * zbi = NULL;

        memcpy(zbi, zbicia, ilosc_zbic(zbicia));
        zbi = dodaj_zbicie(zbi, p);

        bicie_bialym(sz, l, x+2, y-2, x_z, y_z, zbi, 1);
    }

    if(sz->plansza[x+1][y+1] == czarny && sz->plansza[x+2][y+2] == pusty){
        wartownik += 1;
        pole p;
        listazbic * zbi = NULL;

        memcpy(zbi, zbicia, iloscZbic(zbicia));
        zbi = dodaj_zbicie(zbi, p);

        bicie_bialym(sz, l, x+2, y+2, x_z, y_z, zbi, 1);
    }

    if(wartownik == 0 && czyCosZbil != 0){
        ruch r;
        r.z.wiersz = x_z;
        r.z.kolumna = y_z;
        r.na.wiersz = x;
        r.na.kolumna = y;
        r.zbicie = zbicia;
        r.czy_bicie = 1;
        
        l = dodaj_ruch(l, r);
    }

    else if (zbicia != NULL){
        zniszczostatniebicie(zbicia);
    }
}


/*###########################################################################################*/


void generuj_ruch(szachownica *sz, listaruchow *l){
    if(sz->tura == biale){
        bicie_obowiazkowe_biale(sz, l);
        
        if(l == NULL)
            ruch_zwykly_bialy(sz, l);
    }

    else{
        bicie_obowiazkowe_czarne(sz, l);
        
        if(l == NULL)
            ruch_zwykly_czarny(sz, l);
    }
}


/*###########################################################################################*/


void wykonaj_ruch(szachownica *sz, szachownica *dziecko, ruch r){
    
    for(int wiersz=0; wiersz<8; wiersz++)
        for(int kolumna=0; kolumna<8; kolumna++)
            dziecko->plansza[wiersz][kolumna] = sz->plansza[wiersz][kolumna];


    if(r.czy_bicie != 0){
        for(; r.zbicie; r.zbicie = (listazbic *)r.zbicie->nast)
        dziecko->plansza[r.zbicie->point.wiersz][r.zbicie->point.kolumna] = pusty;
    }
    
    dziecko->plansza[r.z.wiersz][r.z.kolumna] = pusty;

    if(sz->tura == biale){
        dziecko->plansza[r.na.wiersz][r.na.kolumna] = bialy;
        dziecko->tura = czarne;
    }
        
    else{
        dziecko->plansza[r.na.wiersz][r.na.kolumna] = czarny;
        dziecko->tura = biale;
    }
    
    policz_biale_czarne(dziecko);
    pozycje(dziecko);
}