#include "../inc/utils.hpp"

void findGoal(const vector2d &puzzle, point &coordonates, int number){
    int size = puzzle.size();

    coordonates.y = number / size;
    coordonates.x = number % size;
}

void print_puzzle(const vector2d puzzle) {
    const int puzzle_size = puzzle.size();
    for (int i = 0; i < puzzle_size; i++) {
        for (int j = 0; j < puzzle_size; j++)
            std::cout << puzzle[i][j] << " ";
        std::cout << std::endl;
    }
}