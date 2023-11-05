#include "../inc/heuristic.hpp"

int hammingDistanceBoosted(const vector2d &puzzle, const vector2d &final)
{
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
            if (puzzle[i][j] != final[i][j])
                ++result;
            getCoordinate(puzzle[i][j], puzzle, final, difference);
            result += computeDistance(difference.front(), difference.back());
            conflicts += checkConflict(difference.front(), puzzle, final, checkedValues);
        }
    }
    return (result + 2 * conflicts);
}