#include "../inc/npuzzle.hpp"
#include <cmath>

typedef struct t_point
{
    int x;
    int y;
} point;

void getFinalCoordinate(const int &value, const vector2d &final, point &coo)
{
    const int size = final.size();

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (final[i][j] == value)
            {
                coo.x = j;
                coo.y = i;
            }
        }
    }
}

int euclidianDistance(const vector2d &puzzle, const vector2d &final)
{
    int h = 0;
    int size = puzzle.size();
    point coo;
    int distanceX;
    int distanceY;

    for (int x = 0; x < size; x++)
    {
        for (int y = 0; y < size; y++)
        {
            if (puzzle[x][y] != final[x][y] && puzzle[x][y] > 0)
            {
                getFinalCoordinate(puzzle[x][y], final, coo);
                if (coo.x == x || coo.y == y)
                    h += (x + y);
                else{
                    distanceX = coo.x - x;
                    distanceY = coo.y - y;
                    h += std::pow((distanceX * distanceX) + (distanceY * distanceY), 0.5);
                }
            }
        }
    }
    if (h - (int)h > 0.5)
        h++;
    return h;
}