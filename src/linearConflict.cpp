#include "../inc/manhattanHeuristic.hpp"
#include "map"

int checkConflict(const point & coo, const vector2d& puzzle, const vector2d& final, std::map<int , int>& checkValues){
    const int dirRow[] = { 0, 1, 0, -1 };
    const int dirColumn[] = { 1, 0, -1, 0 };
    const int puzzleSize = puzzle.size() - 1;
    const int finalNumber = final[coo.y][coo.x];
    const int currentNumber = puzzle[coo.y][coo.x];
    int result = 0;
    int x = 0, y = 0;

    for (int i = 0; i < 4; i++){
        x = coo.x + dirColumn[i];
        y = coo.y + dirRow[i];
        if (x < 0 || y < 0 
        || x > puzzleSize || y > puzzleSize 
        || puzzle[y][x] == 0
        || puzzle[y][x] != finalNumber || currentNumber != final[y][x])
            continue;
        //add them to a map given as parameter
        // and at the end, check if there is duplicate
        if (currentNumber < puzzle[y][x]){
            if ((checkValues.insert(std::make_pair(puzzle[y][x], currentNumber))).second == false){
                continue ;
            }
        }
        else if ((checkValues.insert(std::make_pair(currentNumber, puzzle[y][x]))).second == false){
                continue ;
        }
        result++;
    }
    return (result);
}

int linearConflict(const vector2d& puzzle, const vector2d& final){
    const int size = puzzle.size();
    int result = 0;
    int conflicts = 0;
    std::vector<point> difference(2);
    // x of checked value == target i;j value
    // y of checked value == expended x value
    std::map<int, int> checkedValues;

    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            if (puzzle[i][j] == 0)
                continue ;
            getCoordinate(puzzle[i][j], puzzle, final, difference);
            result += computeDistance(difference.front(), difference.back());
            conflicts += checkConflict(difference.front(), puzzle, final, checkedValues);
        }
    }
    return (result + 2 * conflicts);
}
