#include "../inc/utils.hpp"
#include <algorithm>

void print_puzzle(const vector2d& puzzle) {
    const int puzzle_size = puzzle.size();
    for (int i = 0; i < puzzle_size; i++) {
        for (int j = 0; j < puzzle_size; j++)
            std::cout << puzzle[i][j] << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

vector2d finalPuzzle(const int& size)
{
    const int vectorSize = size * size - 1;

    std::vector<std::vector<bool> > seen(size, std::vector<bool>(size, false));
    vector2d result(size, std::vector<int>(size, 0));
    const int dirRow[] = { 0, 1, 0, -1 };
    const int dirColumn[] = { 1, 0, -1, 0 };
 
    int x = 0, y = 0, dir = 0, newX = 0, newY = 0;
 
    for (int i = 0; i < vectorSize; i++) {
        result[x][y] = i + 1;
        seen[x][y] = true;
        newX = x + dirRow[dir];
        newY = y + dirColumn[dir];
 
        if (newX >= 0 && newX < size && 0 <= newY && newY < size
            && !seen[newX][newY]) {
            x = newX;
            y = newY;
        }
        else {
            dir = (dir + 1) % 4;
            x += dirRow[dir];
            y += dirColumn[dir];
        }
    }
    return (result);
}
