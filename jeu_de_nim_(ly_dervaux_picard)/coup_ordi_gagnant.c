#include <stdio.h>
#include <stdlib.h>

#include "coup_ordi_gagnant.h"
#include "grille.h"
#include "voisines.h"
#include "hasard.h"
#include "nimber.h"
#include "attendre.h"

void coup_ordi_gagnant( int nlig, int ncol, T_case* pion, T_case* tab_case ){
    int cpt, coup = -1, i;//cpt pour stocker le nombre de voisines, coup pour update la position du pion en fonction du nombre aleatoire
    grille( nlig, ncol, *pion );//appel de la fonction grille
    printf("\n");
    cpt = voisines( *pion, tab_case, nlig, ncol );//appel de la fonction voisine
    for( i = 0 ; i < cpt ; i++ ){//parcourt le tableau des cases voisines
        if( nimber( tab_case[i].y, tab_case[i].x, nlig, ncol ) == 0 ){//si la case i du tableau a un nimber de 0
            coup = i;
        }
    }
    if( coup == -1 ){//si aucune case du tableau n avait de nimber a 0
        coup = hasard( 1, cpt ) - 1;//-1 pour correspondre a la numerotation du tableau
    }
    printf("l'ordinateur deplace le pion en (%d,%d)\n", tab_case[coup].x, tab_case[coup].y );
    (*pion).x = tab_case[coup].x;//update la position du pion dans tout le programme grace au pointeur
    (*pion).y = tab_case[coup].y;
    printf("-----------------------------------------------------\n");
    attendre( 1 );//en secondess
}
