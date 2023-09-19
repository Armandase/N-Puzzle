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
        check_solvability(puzzle, puzzle.size());
        
        // node result = aStarAlgorithmV2(puzzle);
        node result = aStarAlgorithm(puzzle);
        std::cout << "Number of moves: " << result.g << "\n\n";
        print_puzzle(result.puzzle);

        // for (int i = result.parent.size() - 1; i >= 0; i--)
        //     print_puzzle(result.parent[i]);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}