#include <stdio.h>
#include <string.h>

int main()
{
    char chaine[200], Long[200], court[200], sauvegarde[200];
    int comptoir = 0;
    
    printf(" entrez une chaîne: ");
    gets(chaine);
    
    
    strcpy( Long, "");
    strcpy( court, chaine );
    
    
    for ( int i = 0; i <= strlen( chaine ); ++i )
    {
        if ( (chaine[i] != ' ') && (chaine[i] != '\0') )
        {
            sauvegarde[comptoir] = chaine[i];
            comptoir = comptoir + 1;
            sauvegarde[comptoir] = '\0';
        }
        
        else
        {
            if ( strlen( sauvegarde ) < strlen( court ) ) 
            {
                strcpy( court, sauvegarde );
            }
            
            if ( strlen( sauvegarde ) > strlen( Long ) ) 
            {
                strcpy( Long, sauvegarde );
            }
            
            sauvegarde[0] = '\0';
            comptoir = 0;
        }
    }
    
    if ( court[0] )
    {
        printf(" Le mot le plus long est %s ( %ld characters )\n", Long, strlen(Long));
        printf(" Le mot le plus court est %s ( %ld characters )\n", court, strlen(court));
    }
    
    else
    {
        puts(" il n'y a pas de caractères alphabétiques ici ");
    }
    
    return 0;
}