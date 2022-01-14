#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#include "lire_entier.h"
#include "nimber.h"
#include "parametres.h"
#include "grille.h"
#include "voisines.h"
#include "hasard.h"
#include "coup_joueur.h"
#include "coup_ordi_hasard.h"
#include "coup_ordi_gagnant.h"
#include "attendre.h"

int main( void ){
    int nlig = 0, ncol = 0;//dimensions de la grille
    int niveau = 0;//niveau de l'ordi
    int next = 0;//variable pour savoir qui va commencer
    int partie_gagnee = 0;//vaut 0 si personne n a gagne, 1 si ordi, 2 si joueur
    int proba = 0;//sert pour le niveau de l ordi
    T_case pion = {1, 1};
    T_case tab_case[4] = {0};

    parametres( &nlig, &ncol, &niveau , &next );//appel de la fonction parametre
    printf("\nc'est parti !\n");
    printf("\n-----------------------------------------------------\n");
    if( next == 1 ){//si l ordi commence
        while( partie_gagnee == 0 ){//tant que personne n a gagne
            if( niveau == 1 ){//ordi niv 1
                coup_ordi_hasard( nlig, ncol, &pion, tab_case );//toujours coup hasard
            }
            else if( niveau == 2 ){//ordi niv 2
                proba = hasard( 1, 3 );
                if( proba == 1 || proba == 2 ){//2/3 chance de coup hasard
                    coup_ordi_hasard( nlig, ncol, &pion, tab_case );
                }
                else{//1/3 chance de coup gagnant
                    coup_ordi_gagnant( nlig, ncol, &pion, tab_case );
                }
            }
            else if( niveau == 3 ){//ordi niv 3
                proba = hasard( 1, 3 );
                if( proba == 1 ){//1/3 chance de coup hasard
                    coup_ordi_hasard( nlig, ncol, &pion, tab_case );
                }
                else{//2/3 chance de coup gagnant
                    coup_ordi_gagnant( nlig, ncol, &pion, tab_case );
                }
            }
            else{//ordi niv 4
                coup_ordi_gagnant( nlig, ncol, &pion, tab_case );//toujours coup gagnant
            }
            if( pion.x == ncol && pion.y == nlig ){//si le pion est au puit
                partie_gagnee = 1;//l ordi gagne
            }
            if( partie_gagnee == 0 ){//si personne n a gagne
                coup_joueur( nlig, ncol, &pion, tab_case );
                if( pion.x == ncol && pion.y == nlig ){//si le pion est au puit
                    partie_gagnee = 2;//le joueur gagne
                }
            }
        }
    }
    else if( next == 2 ){//si le joueur commence
        while( partie_gagnee == 0 ){
            coup_joueur( nlig, ncol, &pion, tab_case );
            if( pion.x == ncol && pion.y == nlig ){//si le pion est au puit
                partie_gagnee = 2;//le joueur gagne
            }
            if( partie_gagnee == 0 ){//si personne n a gagne
            if( niveau == 1 ){//ordi niv 1
                coup_ordi_hasard( nlig, ncol, &pion, tab_case );//toujours coup hasard
            }
            else if( niveau == 2 ){//ordi niv 2
                proba = hasard( 1, 3 );
                if( proba == 1 || proba == 2 ){//2/3 chance de coup hasard
                    coup_ordi_hasard( nlig, ncol, &pion, tab_case );
                }
                else{//1/3 chande de coup gagnant
                    coup_ordi_gagnant( nlig, ncol, &pion, tab_case );
                }
            }
            else if( niveau == 3 ){//ordi niv 3
                proba = hasard( 1, 3 );
                if( proba == 1 ){//1/3 chance de coup hasard
                    coup_ordi_hasard( nlig, ncol, &pion, tab_case );
                }
                else{//2/3 chance de coup gagnant
                    coup_ordi_gagnant( nlig, ncol, &pion, tab_case );
                }
            }
            else{//ordi niv 3
                coup_ordi_gagnant( nlig, ncol, &pion, tab_case );//toujours coup gagnant
            }
            if( pion.x == ncol && pion.y == nlig ){//si le pion est au puit
                partie_gagnee = 1;//l ordi gagne
            }
            }
        }
    }
    grille( nlig, ncol, pion );
    printf("\nc'est termine !\n");//message de fin de partie
    if( partie_gagnee == 1 ){
        printf("l'ordinateur remporte la partie\n");
    }
    else if( partie_gagnee == 2 ){
        printf("\nbravo tu as gagne\n");
    }
    return 0;
}
