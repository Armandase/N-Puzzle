#include "../inc/npuzzle.hpp"
#include "../inc/parsing.hpp"
#include "../inc/utils.hpp"
#include "../inc/algorithm.hpp"
#include "../inc/manhattanHeuristic.hpp"

int main (int ac, char **av) {
    try {
        if (ac > 3)
            throw (std::invalid_argument("main: wrong number of argument\n" + std::string(USAGE)));
        vector2d puzzle;
        if (ac == 2)
            puzzle = parse_file(av[1]);
        else
            puzzle = generate_puzzle();
        print_puzzle(puzzle);
        
        node result = aStarAlgorithm(puzzle);
        std::cout << "result in " << result.g << "\n";
        print_puzzle(result.puzzle);

    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}