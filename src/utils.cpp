#include "../inc/utils.hpp"

void findGoal(const vector2d &puzzle, point &coordonates, int number){
    int size = puzzle.size();

    coordonates.y = number / size;
    coordonates.x = number % size;
}