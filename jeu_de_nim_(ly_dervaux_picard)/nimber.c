#include "nimber.h"

int nimber( int i, int j, int nlig, int ncol ){
    int res = 1;//valeur du nimber
    int decal = 0;//nombre de 1 sur la ligne avant de trouver un 0
    int cpt_lig;
    int x;//contient les multiples de 3

    for( cpt_lig = nlig ; cpt_lig > 0 ; cpt_lig-- ){//parcours les lignes du tableau de bas en haut
        if( decal == 3 ){
            decal = 0;
        }
        if( i == cpt_lig ){//si la boucle est a la meme ligne que la case entree en parametre
            for( x = 0 ; x < ncol ; x = x + 3 ){//x prend successivement la valeur des multiples de 3 inferieur au nombre de colonnes
                if( j == ncol - x - decal ){//si la case est de nimber 0
                res = 0;
                }
            }
        }
        decal++;
    }
    return res;
}
