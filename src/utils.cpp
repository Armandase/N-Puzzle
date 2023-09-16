#include "../inc/utils.hpp"
#include <algorithm>

void findGoal(const vector2d &puzzle, point &coordonates, int number){
    int size = puzzle.size();

    coordonates.y = number / size;
    coordonates.x = number % size;
}

void print_puzzle(const vector2d& puzzle) {
    const int puzzle_size = puzzle.size();
    for (int i = 0; i < puzzle_size; i++) {
        for (int j = 0; j < puzzle_size; j++)
            std::cout << puzzle[i][j] << " ";
        std::cout << std::endl;
    }
    std::cout << "Solved: " << isSolved(puzzle) << std::endl;
}

bool isSolved(const std::vector<std::vector<int> >& puzzle)
{
    int m = puzzle.size();
    int vectorSize = m * m - 1;

    int before_last = 0;
    std::vector<std::vector<bool> > seen(m, std::vector<bool>(m, false));
    int dirRow[] = { 0, 1, 0, -1 };
    int dirColumn[] = { 1, 0, -1, 0 };
 
    int x = 0, y = 0, di = 0, newX = 0, newY = 0;
 
    for (int i = 0; i < vectorSize; i++) {
        if (i > 0 && before_last > puzzle[x][y])
            return (false);
        before_last = puzzle[x][y];
        seen[x][y] = true;
        newX = x + dirRow[di];
        newY = y + dirColumn[di];
 
        if (newX >= 0 && newX < m && 0 <= newY && newY < m
            && !seen[newX][newY]) {
            x = newX;
            y = newY;
        }
        else {
            di = (di + 1) % 4;
            x += dirRow[di];
            y += dirColumn[di];
        }
    }
    if (puzzle[x][y] != 0)
        return (false);
    return (true);
}
