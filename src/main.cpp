#include "../inc/npuzzle.hpp"
#include "../inc/parsing.hpp"
#include "../inc/utils.hpp"
#include "../inc/algorithm.hpp"
#include "../inc/heuristic.hpp"

node choose_heuristic(const vector2d &puzzle)
{
    std::cout << "Heuristic function:" << std::endl;
    std::cout << "  1: Manhattan distance (distance between the number on the puzzle and its final position)" << std::endl;
    std::cout << "  2: Linear conflicts (Manhattan multiplied by 2 * the number of conflicts)" << std::endl;
    // std::cout << "  3: Euclidian distance (the shortest straight-line distance between two points in space)\n"
    std::cout << "  3: Hamming Distance + Linear conflict (based on linear conflicts and add every tiles that are not in their final position)\n"
              << std::endl;
    std::cout << "Choose an heuristic method: ";
    std::string str;

    while (1)
    {
        std::getline(std::cin, str);
        if (std::cin.eof()) {
            std::cout << std::endl;
            exit(0);
        }
        if (str == "1" || str == "2" || str == "3")
            break;
        std::cout << "Choose an heuristic method: ";
        str.clear();
    }
    std::cout << std::endl;
    print_puzzle(puzzle);

    switch (std::stoi(str)) {
        case MANHATTAN:
            return (aStarAlgorithm(puzzle, &manhattanHeuristic));
        case LINEAR:
            return (aStarAlgorithm(puzzle, &linearConflict));
        case EUCLIDIAN:
            return (aStarAlgorithm(puzzle, &hammingDistanceBoosted));
        default:
            break;
    }
    throw(std::logic_error("choose_heuristic: bad heuristic choice"));
}

int main(int ac, char **av)
{
    try
    {
        if (ac > 3)
            throw(std::invalid_argument("main: wrong number of argument\n" + std::string(USAGE)));
        vector2d puzzle;
        if (ac == 2)
            puzzle = parse_file(av[1]);
        else
            puzzle = generate_puzzle();
        check_solvability(puzzle, puzzle.size());

        node result = choose_heuristic(puzzle);
        std::cout << "Number of moves: " << result.g << "\n\n";

        std::cout << "Path to found the result:\n";
        for (int i = 0; i < (int)result.parent.size(); i++)
            print_puzzle(result.parent[i]);
        print_puzzle(result.puzzle);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}