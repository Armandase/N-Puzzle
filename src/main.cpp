#include "../inc/algorithm.hpp"
#include "../inc/heuristic.hpp"
#include "../inc/npuzzle.hpp"
#include "../inc/parsing.hpp"
#include "../inc/utils.hpp"

node choose_heuristic(const vector2d &puzzle)
{
    std::cout << "Heuristic function:" << std::endl;
    std::cout << "  1: Manhattan distance (distance between the number on the puzzle and its final position)\n";
    std::cout << "  2: Linear conflicts (Manhattan multiplied by 2 * the number of conflicts)" << std::endl;
    std::cout << "  3: Hamming Distance + Linear conflict (based on linear conflicts and add every tiles that are not in their final position)\n";
    std::cout << "Bonus Heuristic:" << std::endl;
    std::cout << "  4: Euclidian distance (the shortest straight-line distance between two points in space)\n";
    std::cout << "  5: Misplaced tiles (add 1 to heuristc when a  tile is misplaced, slowest/simplest heuristic)\n"
              << std::endl;
    std::cout << "Choose an heuristic method: ";
    std::string str;

    std::set<std::string> validValues = {"1", "2", "3", "4", "5"};
    while (1)
    {
        std::getline(std::cin, str);
        if (std::cin.eof())
        {
            std::cout << std::endl;
            exit(0);
        }
        if (validValues.find(str) != validValues.end())
            break;
        std::cout << "Choose an heuristic method: ";
        str.clear();
    }
    std::cout << std::endl;
    print_puzzle(puzzle);

    switch (std::stoi(str))
    {
    case MANHATTAN:
        return (aStarAlgorithm(puzzle, &manhattanHeuristic));
    case LINEAR:
        return (aStarAlgorithm(puzzle, &linearConflict));
    case HAMMING:
        return (aStarAlgorithm(puzzle, &hammingDistanceBoosted));
    case EUCLIDIAN:
        return (aStarAlgorithm(puzzle, &euclidianDistance));
    case MISPLACED:
        return (aStarAlgorithm(puzzle, &misplacedTiles));
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
        {
            puzzle = parse_file(av[1]);
            check_solvability(puzzle, puzzle.size());
        }
        else {
            while (1) {
                try {
                    puzzle = generate_puzzle();
                    check_solvability(puzzle, puzzle.size());
                    break;
                } catch (std::exception &e) {}
            }
        }

        bool graphic = graphicExtension();
        node result;
        if (ALGORITHM == UNINFORMED){
            result = aStarAlgorithm(puzzle, &manhattanHeuristic);
        } else {
            result = choose_heuristic(puzzle);
        }
        std::cout << "Number of moves: " << result.g << "\n\n";

        if (graphic)
            graphical_render(result);
        else {
            std::cout << "Path to found the result:\n";
            for (int i = 0; i < (int)result.parent.size(); i++)
                print_puzzle(result.parent[i]);
            print_puzzle(result.puzzle);
        }
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}