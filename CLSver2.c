#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 2

char** highNlow ( char *str ) {

    char hnl = ( char ) malloc ( N * sizeof( char* ) ), *temp = ( char* ) malloc ( strlen( str ) + 1 );
    if ( hnl == NULL ) {
        puts(" hnl memory allocation failed");
        abort();
    }
    
    for ( char **h = hnl; h < hnl + N; ++h ) {
        *h = ( char* ) malloc ( strlen( str ) + 1 );
        if ( *h == NULL ) {
            puts(" h memory allocation failed");
            abort();
        }
    }
    strcpy( hnl[0], "" );
    strcpy( hnl[1], str );
    
    for ( char *s = str; *s; ) {
        int i = 0;
        
        while( *s && isspace( *s ) ) s++;
        
        while( *s && isgraph( *s ) ) {
            temp[i++] = *s;
            s++;
        }
        temp[i] = '\0';
        
        if ( i > strlen( hnl[0] ) )
            strcpy( hnl[0], temp );
        if ( i && (i < strlen( hnl[1] )) )
            strcpy( hnl[1], temp );
    }
    
    
    for ( char **h = hnl; h < hnl + N; ++h ) {
        *h = ( char* ) realloc ( *h, strlen( *h ) + 1 );
        if ( *h == NULL ) {
            puts(" h memory allocation failed");
            abort();
        }
    }
    
    return hnl;
}

int main()
{
    char *s = ( char* ) malloc ( 8888 );
    
    if ( s == NULL ) {
        printf(" s's memory allocation failed");
        abort();
    }
    
    
    printf(" enter a string: ");
    
    gets(s);
    
    s = ( char* ) realloc ( s, strlen( s ) + 1 );
    if ( s == NULL ) {
        printf(" s's memory re-allocation failed");
        abort();
    }
    
    
    char **b = highNlow( s );
    
    if ( **b ) {
        printf(" the longest word is %s ( %ld characters )\n", *b++, strlen(*b));
        printf(" the lilest  word is %s ( %ld characters )\n", *b--, strlen(*b));
    } else 
        puts(" there's no characters in here ");
    
    free( s );
    for ( char **baby = b; baby < b + N; ++baby ) {
        free( *baby );
        *baby = NULL;
    }
    
    free( b );
    s = NULL; b = NULL;
    
    return 0;
}