#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct{
    pole point;
    void *nast;
} listazbic;

listazbic* dodajzbicie(){//TODO
}

void zniszczzbicia(){//TODO
}

int iloscZbic(){//TODO
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


int bicie_obowiazkowe_czarne(szachownica *sz, ruch *r){
        for(int i=1; i<sz->liczba_czarnych; i++){
            if(sz->plansza[sz->pozycje_czarnych[i][0]+1][sz->pozycje_czarnych[i][1]+1] == bialy && sz->plansza[sz->pozycje_czarnych[i][0]+2][sz->pozycje_czarnych[i][1]+2] == pusty){
                r->z.wiersz = sz->pozycje_czarnych[i][0];
                r->z.kolumna = sz->pozycje_czarnych[i][1];
                r->na.wiersz = sz->pozycje_czarnych[i][0]+2;
                r->na.kolumna = sz->pozycje_czarnych[i][1]+2;
                r->zbicie.wiersz = sz->pozycje_czarnych[i][0]+1;
                r->zbicie.kolumna = sz->pozycje_czarnych[i][1]+1;
                return 1;
            }

             if(sz->plansza[sz->pozycje_czarnych[i][0]+1][sz->pozycje_czarnych[i][1]-1] == bialy && sz->plansza[sz->pozycje_czarnych[i][0]+2][sz->pozycje_czarnych[i][1]-2] == pusty){
                r->z.wiersz = sz->pozycje_czarnych[i][0];
                r->z.kolumna = sz->pozycje_czarnych[i][1];
                r->na.wiersz = sz->pozycje_czarnych[i][0]+2;
                r->na.kolumna = sz->pozycje_czarnych[i][1]-2;
                r->zbicie.wiersz = sz->pozycje_czarnych[i][0]+1;
                r->zbicie.kolumna = sz->pozycje_czarnych[i][1]-1;
                return 1;
            }
        }
    return 0;
}


//czarne ida w druga strone
//zmienic na minnusy

int bicie_obowiazkowe_biale(szachownica *sz, listaruchow* l){
        for(int i=1; i<sz->liczba_bialych; i++){
            bicie_bialym(sz, l, , ,,,NULL, 0);
            /*if(sz->plansza[sz->pozycje_bialych[i][0]+1][sz->pozycje_bialych[i][1]+1] == czarny && sz->plansza[sz->pozycje_bialych[i][0]+2][sz->pozycje_bialych[i][1]+2] == pusty){
                r->z.wiersz = sz->pozycje_bialych[i][0];
                r->z.kolumna = sz->pozycje_bialych[i][1];
                r->na.wiersz = sz->pozycje_bialych[i][0]+2;
                r->na.kolumna = sz->pozycje_bialych[i][1]+2;
                r->zbicie.wiersz = sz->pozycje_bialych[i][0]+1;
                r->zbicie.kolumna = sz->pozycje_bialych[i][1]+1;
                //dodaj aktu
                return 1;
            }

            if(sz->plansza[sz->pozycje_bialych[i][0]+1][sz->pozycje_bialych[i][1]-1] == czarny && sz->plansza[sz->pozycje_bialych[i][0]+2][sz->pozycje_bialych[i][1]-2] == pusty){
                r->z.wiersz = sz->pozycje_bialych[i][0];
                r->z.kolumna = sz->pozycje_bialych[i][1];
                r->na.wiersz = sz->pozycje_bialych[i][0]+2;
                r->na.kolumna = sz->pozycje_bialych[i][1]-2;
                r->zbicie.wiersz = sz->pozycje_bialych[i][0]+1;
                r->zbicie.kolumna = sz->pozycje_bialych[i][1]-1;
                return 1;
            }*/
        }
    return 0;
}

int bicie_bialym(szachownica *sz, listaruchow *l, int x, int y, int x_z, int y_z, listazbic * zbicia, int czyCosZbil){
    int wartownik = 0;
    //pozmieniac pozycje
    if(sz->plansza[sz->pozycje_bialych[i][0]+1][sz->pozycje_bialych[i][1]-1] == czarny && sz->plansza[sz->pozycje_bialych[i][0]+2][sz->pozycje_bialych[i][1]-2] == pusty){
        wartownik += 1;
        pole p;
        listazbic * zbi = NULL;

        memcpy(zbi, zbicia, iloscZbic(zbicia));
        zbi = dodajzbicie(zbi, p);
        bicie_bialym(,,,,,,,1);
    }

    if(sz->plansza[sz->pozycje_bialych[i][0]+1][sz->pozycje_bialych[i][1]+1] == czarny && sz->plansza[sz->pozycje_bialych[i][0]+2][sz->pozycje_bialych[i][1]+2] == pusty){
        wartownik += 1;
        pole p;
        listazbic * zbi = NULL;

        memcpy(zbi, zbicia, iloscZbic(zbicia));
        zbi = dodajzbicie(zbi, p);

        r->z.wiersz = sz->pozycje_bialych[i][0];
        r->z.kolumna = sz->pozycje_bialych[i][1];
        r->na.wiersz = sz->pozycje_bialych[i][0]+2;
        r->na.kolumna = sz->pozycje_bialych[i][1]+2;
        r->zbicie.wiersz = sz->pozycje_bialych[i][0]+1;
        r->zbicie.kolumna = sz->pozycje_bialych[i][1]+1;
        //dodaj aktu
        bicie_bialym(,,,,,,,1);
    }

    if(wartownik == 0 && czyCosZbil != 0){
        ruch r;
        r.z.wiersz = x_z;
        r.z.kolumna = y_z;
        r.na.wiersz = x;
        r.na.kolumna = y;
        r.zbicie = zbicia;
        
        l = dodaj_ruch(l, r);
    }
    else if (zbicia != NULL){
        zniszczostatniebicie();
    }
}


void ruch_zwykly_bialy(szachownica *sz, listaruchow *l){
    
    for(int i=1; i<sz->liczba_bialych; i++){
            if(sz->plansza[sz->pozycje_bialych[i][0]+1][sz->pozycje_bialych[i][1]+1] == pusty){
                ruch r;
                r->z.wiersz = sz->pozycje_bialych[i][0];
                r->z.kolumna = sz->pozycje_bialych[i][1];
                r->na.wiersz = sz->pozycje_bialych[i][0]+1;
                r->na.kolumna = sz->pozycje_bialych[i][1]-1;
                dodaj_ruch(&r, l);
            }

            if(sz->plansza[sz->pozycje_bialych[i][0]+1][sz->pozycje_bialych[i][1]-1] == pusty){
                ruch r;
                r->z.wiersz = sz->pozycje_bialych[i][0];
                r->z.kolumna = sz->pozycje_bialych[i][1];
                r->na.wiersz = sz->pozycje_bialych[i][0]+1;
                r->na.kolumna = sz->pozycje_bialych[i][1]+1;
                dodaj_ruch(&r, l);
            }
        }
}


void ruch_zwykly_czarny(szachownica *sz, ruch *r, listaruchow *l){
   for(int i=1; i<sz->liczba_czarnych; i++){
            if(sz->plansza[sz->pozycje_czarnych[i][0]+1][sz->pozycje_czarnych[i][1]+1] == pusty){
                r->z.wiersz = sz->pozycje_czarnych[i][0];
                r->z.kolumna = sz->pozycje_czarnych[i][1];
                r->na.wiersz = sz->pozycje_czarnych[i][0]+1;
                r->na.kolumna = sz->pozycje_czarnych[i][1]+1;
                dodaj_ruch(r, l);
            }

            if(sz->plansza[sz->pozycje_czarnych[i][0]+1][sz->pozycje_czarnych[i][1]+1] == pusty){
                r->z.wiersz = sz->pozycje_czarnych[i][0];
                r->z.kolumna = sz->pozycje_czarnych[i][1]-1;
                r->na.wiersz = sz->pozycje_czarnych[i][0];
                r->na.kolumna = sz->pozycje_czarnych[i][1]-1;
                dodaj_ruch(r, l);
            }
        }
}


listaruchow* generuj_ruch(szachownica *sz, listaruchow *l){
    if(sz->tura == biale){
        if(bicie_obowiazkowe_biale(sz, l) == 1){
        dodaj_ruch(&r, l);
        return 0;
        }
        ruch_zwykly_bialy(sz, l);
    }

    else{
        if(bicie_obowiazkowe_czarne(sz, &r) == 1){
        dodaj_ruch(&r, l);
        return 0;
        }
        ruch_zwykly_czarny(sz, &r, l);



    }    
}


szachownica wykonaj_ruch(szachownica *sz, szachownica *dziecko, ruch r){
    
    for(int wiersz=0; wiersz<8; wiersz++)
        for(int kolumna=0; kolumna<8; kolumna++)
            dziecko->plansza[wiersz][kolumna] = sz->plansza[wiersz][kolumna];

    if(r.zbicie.wiersz != 0)
        dziecko->plansza[r.zbicie.wiersz][r.zbicie.kolumna] = pusty;
    
    
    dziecko->plansza[r.z.wiersz][r.z.kolumna] = pusty;

    if(sz->tura == biale){
        dziecko->plansza[r.na.wiersz][r.na.kolumna] = bialy;
        dziecko->tura = czarne;
    }
        
    
    else{
        dziecko->plansza[r.na.wiersz][r.na.kolumna] = czarny;
        dziecko->tura = biale;
    }
    
    policz_biale_czarne(sz);
    pozycje(sz);
}