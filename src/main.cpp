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
        
        // EXPEND NODE FUNCTION THAT RETURN VECTOR<VECTOR2D>
        // print_puzzle(puzzle);
        // std::cout << "EXPEND NODES:\n" << std::endl;
        // node puzzle_node;
        // puzzle_node.grid = puzzle;
        // puzzle_node.g = 0;
        // puzzle_node.parent = NULL;
        // std::vector<node> expend_list = expend_node(puzzle_node);
        // for (int i = 0; i < expend_list.size(); i++)
        //     print_puzzle(expend_list[i].grid);

        // MANHATTAN HEURISTIC FUNCTION
        // vector2d final = finalPuzzle(puzzle.size());
        // std::cout << "Man value:" << manhattanHeuristic(puzzle, final) << std::endl;
        // aStarAlgorithm(puzzle);

    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}