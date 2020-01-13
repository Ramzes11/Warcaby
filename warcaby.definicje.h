
typedef enum { pusty = 0, bialy = 1, czarny = 2, biala_damka = 3, czarna_damka = 4} figura; 

typedef enum { biale = 0, czarne = 1 } kto;

char kodyfigurek[] = " bcBC";

typedef struct {
    figura plansza[9][9];
    int liczba_bialych;
    int liczba_czarnych;
    int wartosc_planszy;
    kto tura;
    int ocena;
    int pozycje_bialych[3][15];
    int pozycje_czarnych[3][15];

}szachownica;


typedef struct{
    int wiersz, kolumna;
}pole;


typedef struct{
    pole point;
    void *nast;
} listazbic;


typedef struct {
    pole z, na;
    listazbic *zbicie;
    int czy_bicie;
} ruch;


typedef struct {
    ruch r;
    void* nast;
} listaruchow;




