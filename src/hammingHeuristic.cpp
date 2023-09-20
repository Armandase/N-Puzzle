#include "../inc/npuzzle.hpp"
#include <cmath>

typedef struct t_point {
    int x;
    int y;
} point;

void    getFinalCoordinate(const int &value, const vector2d& final, point& coo)
{
    const int size = final.size();


    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            if (final[i][j] == value){
                coo.x = j;
                coo.y = i;
            }
        }
    }
}

int hammingHeuristic(const vector2d& puzzle, const vector2d& final) {
    int h = 0;
    int size = puzzle.size();
    point coo;
    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            if (puzzle[x][y] != final[x][y] && puzzle[x][y] > 0){
                getFinalCoordinate(puzzle[x][y], final, coo);
                h += std::pow(std::pow((coo.x - x), 2) + std::pow((coo.y - y), 2), 0.5);
            }
            h++;
        }
    }
    // std::cout << "Value de heuristic:" << h << std::endl;
    return h;
}

// (2-1)^2 + (3-1)^2
// sqrt((xFinal - xActuel)^2 + (yFinal- yActuel)^2)