#include "../inc/npuzzle.hpp"
#include <cmath>

int hammingHeuristic(const vector2d& puzzle, const vector2d& final) {
    int h = 0;
    int size = puzzle.size();
    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            if (puzzle[x][y] != final[x][y] && puzzle[x][y] > 0){
                h += std::pow((), 0.5)
            }
                h++;
        }
    }
    return h;
}

(2-1)^2 + (3-1)^2
sqrt((xFinal - xActuel)^2 + (yFinal- yActuel)^2)