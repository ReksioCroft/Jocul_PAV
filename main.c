#include "pav_master.h"

int lat, pozl, pozc;
int joc[512][512];

int dala[4][2][2] = {     ///definim cele 4 pozitii in care poate sta dala
        { { 1, 1 },
                { 1, 0 } },
        { { 1, 1 },
                { 0, 1 } },
        { { 0, 1 },
                { 1, 1 } },
        { { 1, 0 },
                { 1, 1 } } };

int main() {
    instructiuni( &lat, &pozl, &pozc, &joc[ 0 ][ 0 ], &dala[ 0 ][ 0 ][ 0 ] ); ///initializam jocul
    int ok, co, i, j, ver, x, y, verif;
    ok = 1;
    co = 0;
    while ( ok == 1 && co < ( ( lat * lat ) - 1 ) / 3 ) {
        printf( "introduceti dala %d\n", ++co );
        for ( i = 0; i < lat; i++ ) {             ///afisam matricea la care am ajuns pana acum
            for ( j = 0; j < lat; j++ ) {
                if ( joc[ i ][ j ] < 10 && joc[ i ][ j ] != -1 )
                    fputc( '0', stdout );
                printf( "%d ", joc[ i ][ j ] );
            }
            fputc( '\n', stdout );
        }
        do {
            printf( "introduceti tipul dalei: " );
            scanf( "%d", &ver );
            if ( ver == -1 ) {                      ///daca jucatorul renunta si opteaza pentru aflarea unei solutii
                ok = 0;
                printf( "ma dau batut:(\n\n" );
            }
            else {
                verif = 1;
                printf( "Atentie! identare de la 0! Introduceti pozitia dalei: " );    ///citim coordonatele dalei
                scanf( "%d%d", &x, &y );
                if ( ( y < lat - 1 ) &&
                     ( x < lat - 1 ) ) {                             ///verificam sa fie coordonate valide
                    for ( i = 0; i < 2; i++ ) {
                        for ( j = 0; j < 2; j++ ) {
                            if ( dala[ ver ][ i ][ j ] ==
                                 1 ) {             ///comparam matricea cu dala, sa ne asiguram ca o putem aseza
                                if ( joc[ x + i ][ y + j ] != 0 )
                                    verif = 0;
                            }
                        }
                    }
                }
                else
                    verif = 0;
                if ( verif == 1 ) {                             ///daca este o mutare corecta, completam matricea joc
                    for ( i = 0; i < 2; i++ )
                        for ( j = 0; j < 2; j++ )
                            if ( dala[ ver ][ i ][ j ] == 1 )
                                joc[ x + i ][ y + j ] = co;
                }
                else                                            ///daca s-a efectuat o mutare inorecta, se reia ultima etapa
                    printf( "mutare incorecta\n" );
            }

        } while ( verif == 0 && ok == 1 );
    }
    if ( ok == 1 )                                               ///castigator
        printf( "FELICITARI!!! ESTI UN PROGRAMATOR INNASCUT\n" );
    else {
        for ( i = 0; i < lat; i++ )
            for ( j = 0; j < lat; j++ )
                if ( joc[ i ][ j ] != -1 )
                    joc[ i ][ j ] = 0;
        pavare_diveetimpera( 0, 0, lat, pozl, pozc, &joc[ 0 ][ 0 ] );       ///solutie oficiala
        for ( i = 0; i < lat; i++ ) {
            for ( j = 0; j < lat; j++ ) {
                if ( joc[ i ][ j ] < 10 && joc[ i ][ j ] != -1 )
                    fputc( '0', stdout );
                printf( "%d ", joc[ i ][ j ] );
            }
            fputc( '\n', stdout );
        }
    }
    printf( "apasati q pentru a iesi " );
    while ( fgetc( stdin ) != 'q' );
    return 0;
}