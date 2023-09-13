#include "../inc/npuzzle.hpp"
#include "../inc/parsing.hpp"
#include "../inc/utils.hpp"
#include <random>

vector2d generate_puzzle() {
    vector2d result;
    std::random_device rd;
    std::mt19937 gen(rd());
    int size = 3 + (gen() % 7);
    int len_values = size * size;
    std::vector<int> added_values;
    int index;
    std::vector<int>::iterator begin = added_values.begin();

    for (int i = 0; i < len_values; i++)
        added_values.push_back(i);
    
    for (int i = 0; i < size; i++)
    {
        std::vector<int> tmp;
        for (int j = 0; j < size; j++){
            index = gen() % len_values;
            tmp.push_back(added_values[index]);
            added_values.erase(begin + index);
            len_values--;
        }
        result.push_back(tmp);
    }
    return (result);
}

int main (int ac, char **av) {
    try {
        if (ac > 3)
            throw (std::invalid_argument("main: wrong number of argument\n" + std::string(USAGE)));
        vector2d puzzle;
        if (ac == 2) {
            puzzle = parse_file(av[1]);
        } else {
            puzzle = generate_puzzle();
        }
        print_puzzle(puzzle);
        
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}