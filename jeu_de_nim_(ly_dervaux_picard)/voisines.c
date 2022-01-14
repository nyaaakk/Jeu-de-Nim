#include "voisines.h"

int voisines( T_case pion, T_case* tab_case, int nlig, int ncol ){
    int nb_vois = 0;//contient le nombre de voisines
    int cpt = 0;//sert pour remplir les cases du tableau
    int i;
    for( i = 0 ; i < 4 ; i++ ){
        tab_case[i].x = 0;
        tab_case[i].y = 0;
    }
    if( pion.x < ncol ){//pour savoir si le pion peut se deplacer d une case a droite
        nb_vois++;
        tab_case[cpt].x = pion.x + 1;
        tab_case[cpt].y = pion.y;
        cpt++;
    }
    if( pion.x < ncol - 1 ){//pour savoir si le pion peut se deplacer de deux cases a doite
        nb_vois++;
        tab_case[cpt].x = pion.x + 2;
        tab_case[cpt].y = pion.y;
        cpt++;
    }
    if( pion.y < nlig ){//pour savoir si le pion peut se deplacer d une case en bas
        nb_vois++;
        tab_case[cpt].x = pion.x;
        tab_case[cpt].y = pion.y + 1;
        cpt++;
    }
    if( pion.y < nlig - 1 ){//pour savoir si le pion peut se deplacer de deux cases en bas
        nb_vois++;
        tab_case[cpt].x = pion.x;
        tab_case[cpt].y = pion.y + 2;
    }
    return nb_vois;
}
