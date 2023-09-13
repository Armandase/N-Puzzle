#include "../inc/npuzzle.hpp"
#include "../inc/parsing.hpp"
#include "../inc/utils.hpp"
#include <random>

vector2d generate_puzzle() {
    vector2d result;
    std::random_device rd;
    std::mt19937 gen(rd());
    int size = 3 + (gen() % 7);
    int max_value = size * size - 1;
    
    for (int i = 0; i < size; i++)
    {
        std::vector<int> tmp;
        for (int j = 0; j < size; j++)
            tmp.push_back(gen() % max_value);
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