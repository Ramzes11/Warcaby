#include<stdio.h>
#include<time.h>

#include"warcaby.definicje.h"
#include"warcaby.fen.h"
#include"warcaby.alfa.beta.h"
#include"warcaby.wykonaj.ruch.h"

void main(){
    szachownica stan;
    //ustawFEN(&stan, "c1c1c1c1/BCbc1111/3bb2C/BB4Cc/5c2/8/6B1/c7");
    //ustawFEN(&stan, "1c6/8/1c6/b3b3/8/8/8/8");
    ustawFEN(&stan, "1c6/8/1c6/b3c3/8/8/8/8");
    //ustawFEN(&stan, "cbcbcbcb/cbcbcbcb/cbcbcbcb/cbcbcbcb/cbcbcbcb/cbcbcbcb/cbcbcbcb/cbcbcbcb");
    //ustawFEN(&stan, "cccccc11bcbc11221ccbcbcccccc11cccccc11cccccc11cccccc11cccccc11");
    
    clock_t start = clock();
    
        int ocena = alfabeta(&stan, 2, -100, 100);
        //int ocena = alfabeta_po_calosci(&stan, 2, -100, 100);

    clock_t stop = clock();
    //printf("Ocena: %d\n", ocena);
    printf("\nIle bialych: %d\nIle czarnych: %d\n Czyja tura: %d\n Ocena: %d\n ile bd: ", stan.liczba_bialych, stan.liczba_czarnych, stan.tura, stan.ocena);
    printf("\n\ntime: %f s\n", 1.0 * (stop - start) / CLOCKS_PER_SEC);
} 


