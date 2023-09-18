#include "../inc/parsing.hpp"
#include "../inc/utils.hpp"

unsigned int get_inv_score(const vector2d & puzzle, const int & size) {
    int y;
    int number;
    int inv_count = 0;
    for (int x_check = 0; x_check < size; x_check++) {
        for (int y_check = 0; y_check < size; y_check++) {
            number = puzzle[x_check][y_check];
            if (number == 0)
                continue ;
            y = y_check;
            for (int x = x_check; x < size; x++) {
                for (; y < size; y++) {
                    if (puzzle[x][y] != 0 && puzzle[x][y] < number)
                        inv_count++;
                }
                y = 0;
            }
        }
    }
    return (inv_count);
}

int get_zero_row(const vector2d & puzzle, const int & size) {
    for (int x = 0; x < size;x++) {
        for (int y = 0; y < size; y++) {
            if (puzzle[x][y] == 0)
                return x + 1;
        }
    }
    throw(std::logic_error("get_zero_row: no zero in this puzzle"));
}

void check_solvability(const vector2d & puzzle, const int & size) {
    const int inv_initial = get_inv_score(puzzle, size);
    const vector2d goal_state = finalPuzzle(size);
    const int inv_goal = get_inv_score(goal_state, size);
    if (size % 2 == 1 && inv_goal % 2 == inv_initial % 2)
        return ;    
    if (size % 2 == 0) {
        const int blank_row_s = get_zero_row(puzzle, size);
        const int blank_row_g = get_zero_row(goal_state, size);
        if (inv_goal % 2 == 0 && inv_initial % 2 == abs(blank_row_g - blank_row_s) % 2)
            return ;
        if (inv_goal % 2 == 1 && inv_initial % 2 != abs(blank_row_g - blank_row_s) % 2)
            return ;
    }
    throw(std::logic_error("check_solvability: the puzzle is not solvable"));
}