#include "../inc/npuzzle.hpp"
#include "../inc/parsing.hpp"
#include "../inc/utils.hpp"
#include "../inc/algorithm.hpp"
#include "../inc/manhattanHeuristic.hpp"

node choose_heuristic(const vector2d& puzzle) {
    std::cout << "Heuristic function:" << std::endl;
    std::cout << "  1: manhattan distance (distance between the number on the puzzle and its final position)" << std::endl;
    std::cout << "  2: linear conflict (Armand explain pls)" << std::endl;
    std::cout << "  3: to define\n" << std::endl;
    std::cout << "Choose an heuristic method: ";
    std::string str;

    while (1) {
        std::getline(std::cin, str);
        if (str == "1" || str == "2" || str == "3")
            break;
        str.clear();
    }
    std::cout << std::endl;
    print_puzzle(puzzle);

    switch (std::stoi(str)) {
        case MANHATTAN:
            return (aStarAlgorithm(puzzle, &manhattanHeuristic));
        case LINEAR:
            return (aStarAlgorithm(puzzle, &linearConflict));
        case TO_DEFINE:
            // return (aStarAlgorithm(puzzle, &linearConflict));
            break;
        default:
            break;
    }
    throw(std::logic_error("choose_heuristic: bad heuristic choice"));

}

int main (int ac, char **av) {
    try {
        if (ac > 3)
            throw (std::invalid_argument("main: wrong number of argument\n" + std::string(USAGE)));
        vector2d puzzle;
        if (ac == 2)
            puzzle = parse_file(av[1]);
        else
            puzzle = generate_puzzle();
        check_solvability(puzzle, puzzle.size());


        
        node result = choose_heuristic(puzzle);
        std::cout << "Number of moves: " << result.g << "\n\n";
        print_puzzle(result.puzzle);

        // for (int i = result.parent.size() - 1; i >= 0; i--)
        //     print_puzzle(result.parent[i]);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}