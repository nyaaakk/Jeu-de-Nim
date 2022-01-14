#include <stdio.h>

#include "lire_entier.h"

int lire_entier( int min, int max ){
    int res;
    if( scanf(" %d", &res) != 1 ){
        res = min - 1;
    }
    getchar();
    while( res < min || res > max ){//tant que l entier saisi n est pas compris dans les bornes on recommence
        printf("erreur de saisie, recommencer : ");
        if( scanf(" %d", &res) != 1 ){
            res = min - 1;
        }
        getchar();
    }
    return res;
}
