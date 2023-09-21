#include "../inc/manhattanHeuristic.hpp"

void    getCoordinate(const int& value, const vector2d& puzzle, const vector2d& final, std::vector<point>& difference)
{
    const int size = puzzle.size();   

    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            if (puzzle[i][j] == value){
                difference.front().x = j;
                difference.front().y = i;
            }
            if (final[i][j] == value){
                difference.back().x = j;
                difference.back().y = i;
            }
        }
    }
}

int   computeDistance(const point& puzzleCoo, const point& finalCoo){
    if (puzzleCoo.x == finalCoo.x && puzzleCoo.y == finalCoo.y)
        return (0);
    
    int result = 0;

    if (puzzleCoo.x < finalCoo.x)
        result += (finalCoo.x - puzzleCoo.x);
    else if (puzzleCoo.x > finalCoo.x)
        result += (puzzleCoo.x - finalCoo.x);

    if (puzzleCoo.y < finalCoo.y)
        result += (finalCoo.y - puzzleCoo.y);
    else if (puzzleCoo.y > finalCoo.y)
        result += (puzzleCoo.y - finalCoo.y);
    return (result);
}

float manhattanHeuristic(const vector2d& puzzle, const vector2d& final){
    const int size = puzzle.size();
    int result = 0;
    std::vector<point> difference(2);

    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            if (puzzle[i][j] == 0)
                continue ;
            getCoordinate(puzzle[i][j], puzzle, final, difference);
            result += computeDistance(difference.front(), difference.back());
        }
    }
    return (result);
}
