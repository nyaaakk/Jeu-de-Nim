#include <stdio.h>

#include "coup_joueur.h"
#include "grille.h"
#include "voisines.h"
#include "lire_entier.h"

void coup_joueur( int nlig, int ncol, T_case* pion, T_case* tab_case ){
    int i, cpt, coup = 0;//i pour la boucle, cpt pour stocker le nombre de voisines, coup pour update la position du pion en fonction du choix du joueur
    printf("a toi de jouer !\n\n");
    grille( nlig, ncol, *pion );//appel de la fonction grille
    printf("\n");
    cpt = voisines( *pion, tab_case, nlig, ncol );//appel de la fonction voisine
    if( tab_case[1].x == 0 && tab_case[1].y == 0 ){
        printf("une seule possibilite : (%d,%d)\n", tab_case[0].x, tab_case[0].y );
        printf("valider ?");
        getchar();
        coup = 0;
    }
    else{
        printf("choisir la destination :\n\n");
        for( i = 0 ; i < 4 ; i++ ){//boucle pour afficher les differents choix
            if( tab_case[i].x != 0 || tab_case[i].y != 0 ){//si le choix n est pas nul on l affiche
                printf("%d: (%d,%d)\n", i + 1, tab_case[i].x, tab_case[i].y );
            }
        }
        printf("\n---> ");
        coup = lire_entier( 1, cpt ) - 1;//-1 pour correspondre a la numerotation du tableau
    }
    (*pion).x = tab_case[coup].x;//update la position du pion dans tout le programme grace au pointeur
    (*pion).y = tab_case[coup].y;
    printf("-----------------------------------------------------\n");
}
