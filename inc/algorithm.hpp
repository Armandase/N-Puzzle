#ifndef __ALGORITHM_HPP__
# define __ALGORITHM_HPP__

# include "npuzzle.hpp"

void    aStarAlgorithm(vector2d&);

typedef struct t_node
{
    vector2d    grid;
    int         g;
    struct t_node        *parent;
} node;



/*
g est égal au nombre de coup, 
par rapport a la position initiale,
pour arrivé a la position actuel

h (version manhattan) est egal à la somme
du nombre de coup que chaque tuile doit faire pour arrive à sa position final

h (version hamming) est egal aux nombres de tuiles mal placées

h (version linear conflict) est egal à la version manhattan multiplié par 2 *
le nombre de conflit (si deux tuiles doivent échanger de place en ligne ou colonne)

f = g + h
*/



#endif