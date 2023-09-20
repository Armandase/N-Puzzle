#ifndef __ALGORITHM_HPP__
# define __ALGORITHM_HPP__

# include "npuzzle.hpp"
# include <algorithm>

enum direction {
    UP,
    DOWN,
    RIGHT,
    LEFT,
};

typedef struct t_node
{
    vector2d    puzzle;
    int         g;
    int         f;
    std::vector<vector2d>  parent;
} node;


node    aStarAlgorithm(const vector2d&, int heuristic(const vector2d &, const vector2d &));
node    aStarAlgorithmV2(vector2d&);
std::vector<node> expend_node(node &, node &, int heuristic(const vector2d &, const vector2d &));
std::vector<node> findLowestF(const std::vector<node>& );

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