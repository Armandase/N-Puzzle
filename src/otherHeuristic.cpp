#include "../inc/npuzzle.hpp"
#include <cmath>

int euclidianDistance(const vector2d &puzzle, const vector2d &final)
{
    int distance = 0;
    int n = puzzle.size();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int value = puzzle[i][j];

            if (value != 0) {
                int goalX = -1;
                int goalY = -1;
                for (int k = 0; k < n; ++k) {
                    for (int l = 0; l < n; ++l) {
                        if (final[k][l] == value) {
                            goalX = k;
                            goalY = l;
                            break;
                        }
                    }
                    if (goalX != -1)
                        break;
                }
                int dx = i - goalX;
                int dy = j - goalY;
                distance += static_cast<int>(std::sqrt(dx * dx + dy * dy));
            }
        }
    }
    return distance;
}

int misplacedTiles(const vector2d &puzzle, const vector2d &final)
{
    int h = 0;
    int size = puzzle.size();

    for (int x = 0; x < size; x++)
        for (int y = 0; y < size; y++)
            if (puzzle[x][y] != final[x][y] && puzzle[x][y] > 0)
                ++h;
    return h;
}

