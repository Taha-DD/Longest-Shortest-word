#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *h;
    char *l;
} hilo;

hilo highNlow ( char *str ) {

    char c[2] = " ";
    
    hilo hnl;
    
    hnl.h = ( char* ) malloc ( strlen( str ) + 1 );
    hnl.l = ( char* ) malloc ( strlen( str ) + 1 );
    
    if ( (hnl.h == NULL) || (hnl.l == NULL) ) {
        printf(" hnl's memory allocation failed");
        abort();
    }
    
    strcpy( hnl.l, str );
    strcpy( hnl.h, "" );
    
    
    
    char *temp = strtok( str, c );
    
    if ( temp == NULL ) {
        hnl.h = "\0";
        return hnl;
    }
    
    while( temp ) {
    
        if ( strlen( temp ) > strlen( hnl.h ) )
            strcpy( hnl.h, temp );
            
        if ( strlen( temp ) < strlen( hnl.l ) )
            strcpy( hnl.l, temp );
    
    
        temp = strtok( NULL, c );
    }
    
    
    
    
    hnl.h = ( char* ) realloc ( hnl.h, strlen( hnl.h ) + 1 );
    hnl.l = ( char* ) realloc ( hnl.l, strlen( hnl.l ) + 1 );
    
    if ( (hnl.h == NULL) || (hnl.l == NULL) ) {
        printf(" hnl's memory re-allocation failed");
        abort();
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
    
    
    
    hilo b = highNlow( s );
    
    if ( *b.h ) {
        printf(" the longest word is %s ( %ld characters )\n", b.h, strlen(b.h));
        printf(" the lilest word is %s ( %ld characters )\n", b.l, strlen(b.l));
    } else 
        puts(" there's no characters in here ");
        
    return 0;
}