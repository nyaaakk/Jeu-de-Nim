#include <stdio.h>
#include <stdlib.h>

#include "coup_ordi_hasard.h"
#include "grille.h"
#include "voisines.h"
#include "hasard.h"
#include "attendre.h"

void coup_ordi_hasard( int nlig, int ncol, T_case* pion, T_case* tab_case ){
    int cpt, coup = 0;//cpt pour stocker le nombre de voisines, coup pour update la position du pion en fonction du nombre aleatoire
    grille( nlig, ncol, *pion );//appel de la fonction grille
    printf("\n");
    cpt = voisines( *pion, tab_case, nlig, ncol );//appel de la fonction voisine
    coup = hasard( 1, cpt ) - 1;//-1 pour correspondre a la numerotation du tableau
    printf("l'ordinateur deplace le pion en (%d,%d)\n", tab_case[coup].x, tab_case[coup].y );
    (*pion).x = tab_case[coup].x;//update la position du pion dans tout le programme grace au pointeur
    (*pion).y = tab_case[coup].y;
    printf("-----------------------------------------------------\n");
    attendre( 1 );//ecrit en secondes
}
