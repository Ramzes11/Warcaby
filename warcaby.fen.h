#include <stdio.h>


void wypisz_plansze(szachownica *sz){
    printf("   +---+---+---+---+---+---+---+---+\n");
    for(int i = 0; i < 8; i++)
    {
        printf(" %d | %c | %c | %c | %c | %c | %c | %c | %c |\n", i + 1, kodyfigurek[sz->plansza[i][0]], kodyfigurek[sz->plansza[i][1]], kodyfigurek[sz->plansza[i][2]], kodyfigurek[sz->plansza[i][3]], kodyfigurek[sz->plansza[i][4]],kodyfigurek[sz->plansza[i][5]], kodyfigurek[sz->plansza[i][6]],  kodyfigurek[sz->plansza[i][7]]);
        printf("   +---+---+---+---+---+---+---+---+\n");
    }

    printf("     A   B   C   D   E   F   G   H\n\n");
}


void policz_biale_czarne(szachownica *sz){
    int b=0,c=0;
    int bd=0, cd=0;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(sz->plansza[i][j] == bialy) b++;
            if(sz->plansza[i][j] == czarny) c++;
            //if(sz->plansza[i][j] == biala_damka) bd++;
            //if(sz->plansza[i][j] == czarna_damka) cd++;
        }
    }
    sz->liczba_bialych = b;
    sz->liczba_czarnych = c;
    //sz->liczba_bialych_d=bd;
    //sz->liczba_czarnych_d=cd;
    sz->wartosc_planszy = b-c;
    
    if((b+bd)==0)
        sz->ocena = -100;

    if((c+cd)==0)
        sz->ocena = 100;
}


void pozycje(szachownica *sz){
    int b=1;
    int c=1;

    for (int wiersz = 0; wiersz < 8; wiersz++)
        for (int kolumna = 0; kolumna < 8; kolumna++){
            
            if(sz->plansza[wiersz][kolumna] == bialy){
                sz->pozycje_bialych[b][0]=wiersz;
                sz->pozycje_bialych[b][1]=kolumna;
                b++;
                }

            if(sz->plansza[wiersz][kolumna] == czarny){
                sz->pozycje_czarnych[c][0]=wiersz;
                sz->pozycje_czarnych[c][1]=kolumna;
                c++;
                }
        }
}

void ustawFEN(szachownica *sz, char *fen){
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            sz->plansza[i][j] = pusty;       
        
    int wiersz = 0;
    while(wiersz < 8)
    {
        int kolumna = 0;
        while(kolumna <= 8)
        {
            switch (*fen)
            {
                case '/':
                    break;

                case 'C':
                    sz->plansza[wiersz][kolumna] = czarna_damka;
                    break;
            
                case 'c':
                    sz->plansza[wiersz][kolumna] = czarny;
                    break;
                
                case 'B':
                    sz->plansza[wiersz][kolumna] = biala_damka;
                    break;
            
                case 'b':
                    sz->plansza[wiersz][kolumna] = bialy;
                    break;

                case '1': 
                    break; 

                case '2':
                    kolumna=kolumna+1;
                    break;

                case '3':
                    kolumna=kolumna+2;
                    break;

                case '4':
                    kolumna=kolumna+3;
                    break;

                case '5':
                    kolumna=kolumna+4;
                    break;

                case '6':
                    kolumna=kolumna+5;
                    break;

                case '7':
                    kolumna=kolumna+6;
                    break;

                case '8':
                    kolumna=kolumna+7;
                    break;
            }
            *fen++;
            kolumna++;
        }
        wiersz++;
    }

    sz->tura=biale;
    policz_biale_czarne(sz);
    pozycje(sz);
    wypisz_plansze(sz);
}