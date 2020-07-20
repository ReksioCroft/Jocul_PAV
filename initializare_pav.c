#include "pav_master.h"

void instructiuni( int *lat, int *pozl, int *pozc, int *joc, int *dala ) {
    int i, j, ver, ok;
    printf( "instructiuni:\n" );
    printf( "matricea este identata de la 0\n" );
    printf( "pentru a introduce o dala, specificati, in aceasta ordine, tipul de dala,\n" );
    printf( "apoi linia si coloana coltului din stanga sus\n\n" );
    for ( ver = 0; ver < 4; ver++ ) {
        printf( "tipul %d:\n", ver );
        for ( i = 0; i < 2; i++ ) {
            for ( j = 0; j < 2; j++ ) {
                printf( "%d ", *( dala + ver * 4 + i * 2 + j ) );
            }
            fputc( '\n', stdout );
        }
        fputc( '\n', stdout );
    }
    printf( "daca simtiti ca nu reusiti, introduceti la tipul dalei numarul '-1' \n\n" );
    printf( "Sa inceapa jocul!!!\n\n" );
    printf( "introduceti numarul n pt a selecta un joc cu 2^n linii si coloana:" );
    scanf( "%d", lat );
    fputc( '\n', stdout );
    ( *lat ) = 1 << ( *lat );
    do {
        printf( "introduceti unde este pozitionat iepurasul:" );
        ok = 1;
        scanf( "%d%d", pozl, pozc );
        if ( ( *pozl ) < 0 || ( *pozl ) >= ( *lat ) || ( *pozc ) < 0 || ( *pozc ) >= ( *lat ) ) {
            ok = 0;
            printf( "pozitie incorecta, mai incearca...\n" );
        }
    } while ( ok == 0 );
    *( joc + 512 * ( *pozl ) + ( *pozc ) ) = -1;
    fputc( '\n', stdout );
}