#ifndef T_CASE
#define T_CASE

struct T_case{
        int x;//indice de colonne
        int y;//indice de ligne
    };
typedef struct T_case T_case;

#endif // T_CASE

void coup_ordi_gagnant( int, int, T_case*, T_case* );
