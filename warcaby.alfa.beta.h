
int alfabeta(szachownica *sz, int glebokosc, int alfa, int beta){
    
    if (sz->liczba_bialych == 0 || sz->liczba_czarnych == 0 || glebokosc == 0)
        return(sz->ocena);

        listaruchow* l;
        generuj_ruch(sz, &l);

 

    for(; l; l = (listaruchow *)l->nast){

        szachownica dziecko;
        wykonaj_ruch(sz, &dziecko, l->r);

        int value = -alfabeta(&dziecko, glebokosc - 1, -beta, -alfa);

        if (value > alfa)
            alfa = value;
        

        if (alfa >= beta){
            zniszczliste(l);
            return beta; 
        }
    }

    zniszczliste(l);
    return alfa;
}