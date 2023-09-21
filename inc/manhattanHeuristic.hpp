#ifndef __MANHATTANHEURSITIC_HPP__
# define __MANHATTANHEURSITIC_HPP__

# include "npuzzle.hpp"

typedef struct t_point {
    int x;
    int y;
} point;

void    getCoordinate(const int& value, const vector2d& puzzle, const vector2d& final, std::vector<point>& difference);
int     computeDistance(const point& puzzleCoo, const point& finalCoo);
int     manhattanHeuristic(const vector2d& puzzle, const vector2d& final);
int     euclidianDistance(const vector2d& puzzle, const vector2d& final);

int linearConflict(const vector2d& puzzle, const vector2d& final);


#endif // !__MANHATTANHEURSITIC_HPP__

