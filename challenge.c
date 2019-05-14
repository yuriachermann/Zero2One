#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {

    char str[37] = "abcdefghijklmnopqrstuvwxyz_0123456789" , pass[37] , num ;
    int vet[37] = {0} , n = 0 , c = 0 ;

    FILE *arq = fopen( "text.txt" , "r" ) ;
    if( arq == NULL ) return 0 ;
    while( fscanf( arq , "%c" , &num ) != EOF ){
        if( num > 96 && num < 123 ) vet[(int)num-97]++ ;
        else if( num == 95 ) vet[26]++ ;
        else vet[(int)num-48+27]++ ;
    }
    fclose( arq ) ;
    for( int i=0 ; i<37 ; i++ ) pass[vet[i]-64] = (char)str[i] ;
    while( pass[n] != '_' ) n++ ;
    char defpass[n+1] ;
    for( int j=0 ; j<n ; j++ ) defpass[j] = pass[j] ;
    defpass[n] = '\0' ;
    printf( "%s\n" , defpass ) ;

	return 0 ;
}
