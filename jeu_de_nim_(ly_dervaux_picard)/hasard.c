#include <stdlib.h>
#include <time.h>

#include "hasard.h"

int hasard( int min, int max ){
    int res = 0;
    srand((unsigned int)time(NULL));//initialise la seed pour avoir des valeurs aleatoires differentes a chaque fois
    res = (rand() % (max - min + 1)) + min;//genere un nombre au hasard entre min et max
    return res;
}
