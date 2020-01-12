
void dodajruch(listaruchow *l, ruch *r){
    

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


int bicie_obowiazkowe_biale(szachownica *sz, ruch *r){
        for(int i=1; i<sz->liczba_bialych; i++){
            if(sz->plansza[sz->pozycje_bialych[i][0]+1][sz->pozycje_bialych[i][1]+1] == czarny && sz->plansza[sz->pozycje_bialych[i][0]+2][sz->pozycje_bialych[i][1]+2] == pusty){
                r->z.wiersz = sz->pozycje_bialych[i][0];
                r->z.kolumna = sz->pozycje_bialych[i][1];
                r->na.wiersz = sz->pozycje_bialych[i][0]+2;
                r->na.kolumna = sz->pozycje_bialych[i][1]+2;
                r->zbicie.wiersz = sz->pozycje_bialych[i][0]+1;
                r->zbicie.kolumna = sz->pozycje_bialych[i][1]+1;
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
            }
        }
    return 0;
}


void ruch_zwykly_bialy(szachownica *sz, ruch *r, listaruchow *l){
    for(int i=1; i<sz->liczba_bialych; i++){
            if(sz->plansza[sz->pozycje_bialych[i][0]+1][sz->pozycje_bialych[i][1]+1] == pusty){
                r->z.wiersz = sz->pozycje_bialych[i][0];
                r->z.kolumna = sz->pozycje_bialych[i][1];
                r->na.wiersz = sz->pozycje_bialych[i][0]+1;
                r->na.kolumna = sz->pozycje_bialych[i][1]-1;
                dodaj_ruch(&r, l);
            }

            if(sz->plansza[sz->pozycje_bialych[i][0]+1][sz->pozycje_bialych[i][1]-1] == pusty){
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


int generuj_ruch(szachownica *sz, listaruchow *l){
    ruch r;
    r.zbicie.wiersz = 0;
    if(sz->tura == biale){
        if(bicie_obowiazkowe_biale(sz, &r) == 1){
        dodaj_ruch(&r, l);
        return 0;
        }
        ruch_zwykly_bialy(sz, &r, l);
    }

    else{
        if(bicie_obowiazkowe_czarne(sz, &r) == 1){
        dodaj_ruch(&r, l);
        return 0;
        }
        ruch_zwykly_czarny(sz, &r, l);



    }    
}


void wykonaj_ruch(szachownica *sz, szachownica *dziecko, listaruchow *l){
    
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