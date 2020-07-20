#include "pav_master.h"

int v[512][512];                            ///matricea pe care o completam cu dale
char dlin[4] = { 0, 0, 1, 1 };              ///luam fiecare submatrice in ordinea: st sus, dr sus, st jos, dr jos
char dcol[4] = { 0, 1, 0, 1 };
int nr_dala;
int v[512][512];                            ///matricea pe care o completam cu dale

void pavare_diveetimpera( int lstart, int cstart, int lat, int lgaura, int cgaura, int *v ) {
    int i, i0 = 0;
    if ( lat > 1 ) {                          ///daca matricea se mai poate impartii in submatrici
        lat >>= 1;                              ///injumatatim latura
        for ( i = 0; i < 4; i++ )
            if ( lgaura >= lstart + lat * dlin[ i ] && lgaura < lstart + lat * ( dlin[ i ] + 1 ) &&
                 cgaura >= cstart + lat * dcol[ i ] && cgaura < cstart + lat * ( dcol[ i ] + 1 ) )
                i0 = i;                             ///luam fiecare din cele 4 submatrici, si retinem in care se afla gaura
        nr_dala++;                                 ///incrementam nr dalei cu care pavam
        for ( i = 0; i < 4; i++ )
            if ( i != i0 )                        ///daca nu suntem in submatricea cu gaura
                *( v + 512 * ( lstart + lat + dlin[ i ] - 1 ) +
                   ( cstart + lat + dcol[ i ] - 1 ) ) = nr_dala;       ///pavam colturile din jurul dalei
        for ( i = 0; i < 4; i++ ) {                                      ///impartim matricea in cele 4 submatrici
            if ( i !=
                 i0 )                                                 ///daca suntem in submatricea fara gaura, setam gaura artificiala creata de noi
                pavare_diveetimpera( lstart + lat * dlin[ i ], cstart + lat * dcol[ i ], lat,
                                     lstart + lat + dlin[ i ] - 1, cstart + lat + dcol[ i ] - 1, v );
            else                                                          ///daca suntem in submatricea ce are deja gaura, o transmitem mai departe
                pavare_diveetimpera( lstart + lat * dlin[ i ], cstart + lat * dcol[ i ], lat, lgaura, cgaura, v );
        }
    }
}