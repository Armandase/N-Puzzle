#include "../inc/npuzzle.hpp"

int hammingHeuristic(const vector2d& puzzle, const vector2d& final) {
    int h = 0;
    int size = puzzle.size();
    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            if (puzzle[x][y] != final[x][y])
                h++;
        }
    }
    return h;
}