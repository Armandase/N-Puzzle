#include "../inc/utils.hpp"
#include <algorithm>
#include <random>

void print_puzzle(const vector2d &puzzle)
{
    const int puzzle_size = puzzle.size();
    for (int i = 0; i < puzzle_size; i++)
    {
        for (int j = 0; j < puzzle_size; j++)
            std::cout << puzzle[i][j] << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

vector2d finalPuzzle(const int &size)
{
    const int vectorSize = size * size - 1;

    std::vector<std::vector<bool>> seen(size, std::vector<bool>(size, false));
    vector2d result(size, std::vector<int>(size, 0));
    const int dirRow[] = {0, 1, 0, -1};
    const int dirColumn[] = {1, 0, -1, 0};

    int x = 0, y = 0, dir = 0, newX = 0, newY = 0;

    for (int i = 0; i < vectorSize; i++)
    {
        result[x][y] = i + 1;
        seen[x][y] = true;
        newX = x + dirRow[dir];
        newY = y + dirColumn[dir];

        if (newX >= 0 && newX < size && 0 <= newY && newY < size && !seen[newX][newY])
        {
            x = newX;
            y = newY;
        }
        else
        {
            dir = (dir + 1) % 4;
            x += dirRow[dir];
            y += dirColumn[dir];
        }
    }
    return (result);
}

vector2d generate_puzzle()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    const int size = PUZZLE_SIZE;
    vector2d result(size, std::vector<int>());

    int len_values = size * size;
    std::vector<int> added_values;
    for (int i = 0; i < len_values; i++)
        added_values.push_back(i);
    std::vector<int>::iterator begin = added_values.begin();
    int index;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            index = gen() % len_values;
            result[i].push_back(added_values[index]);
            added_values.erase(begin + index);
            len_values--;
        }
    }
    return (result);
}

bool graphicExtension()
{
    std::string str;
    std::cout << "Do you want graphic render ? [y/n] ";
    while (1)
    {
        std::getline(std::cin, str);
        if (std::cin.eof())
        {
            std::cout << std::endl;
            exit(0);
        }
        if (str == "y" || str == "n")
            return str == "y" ? true : false;
        std::cout << "Do you want graphic render ? [y/n] ";
        str.clear();
    }
}
