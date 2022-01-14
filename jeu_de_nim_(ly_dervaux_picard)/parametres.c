#include <stdio.h>

#include "parametres.h"
#include "lire_entier.h"

#define VMIN 5
#define VMAX 30

void parametres( int* nlig, int* ncol, int* niveau, int* next ){//donner une adresse en parametre pour modifier la variable sans return
    printf("--Parametres du jeu--\n\n");
    printf("nombre de lignes (entre %d et %d)\n--> ", VMIN, VMAX);
    *nlig = lire_entier( VMIN, VMAX );
    printf("nombre de colonnes (entre %d et %d)\n--> ", VMIN, VMAX);
    *ncol = lire_entier( VMIN, VMAX );
    printf("niveau de difficulte de l'IA (entre 1 et 4)\n--> ");
    *niveau = lire_entier( 1, 4 );
    printf("qui va commencer ?\n(1) l'ordi\n(2) le joueur\n--> ");
    *next = lire_entier( 1, 2 );
}
