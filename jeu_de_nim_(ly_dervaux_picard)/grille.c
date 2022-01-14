#include <stdio.h>

#include "grille.h"

void grille( int nlig, int ncol, T_case pion ){
    int i, j;
    printf("  ");
    for( i = 1 ; i <= ncol ; i++ ){//affichage des caracteres de la premiere ligne
        if( i <= 10 ){
            printf("   %d", i);
        } else {
            printf("  %d", i);
        }

    }
    printf("\n");
    for( i = 1 ; i <= nlig ; i++ ){//gere le passage a la ligne suivante
            printf("%2d | ", i);
        for( j = 1 ; j <= ncol ; j++ ){//affiche les caracteres d une ligne
            if( pion.x == j && pion.y == i ){//teste la position du pion
                printf("o ");
            } else {
                printf("- ");
            }
            printf("| ");
        }
        printf("\n");
    }
}
