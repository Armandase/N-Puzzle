#include "../inc/npuzzle.hpp"
#include "../inc/parsing.hpp"
#include "../inc/utils.hpp"
#include "../inc/algorithm.hpp"

typedef struct t_point {
    int x;
    int y;
} point;

void    getCoordinate(const int& value, const vector2d& puzzle, const vector2d& final, std::vector<point>& difference)
{
    const int size = puzzle.size();   

    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            if (puzzle[i][j] == value){
                difference.front().x = j;
                difference.front().y = i;
            }
            if (final[i][j] == value){
                difference.back().x = j;
                difference.back().y = i;
            }
        }
    }
}

int   computeDistance(const point& puzzleCoo, const point& finalCoo){
    if (puzzleCoo.x == finalCoo.x && puzzleCoo.y == finalCoo.y)
        return (0);
    
    int result = 0;

    if (puzzleCoo.x < finalCoo.x)
        result += (finalCoo.x - puzzleCoo.x);
    else if (puzzleCoo.x > finalCoo.x)
        result += (puzzleCoo.x - finalCoo.x);

    if (puzzleCoo.y < finalCoo.y)
        result += (finalCoo.y - puzzleCoo.y);
    else if (puzzleCoo.y > finalCoo.y)
        result += (puzzleCoo.y - finalCoo.y);
    return (result);
}

int manhattanHeuristic(const vector2d& puzzle, const vector2d& final){
    const int size = puzzle.size();
    int result = 0;
    std::vector<point> difference(2);

    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            if (puzzle[i][j] == 0)
                continue ;
            getCoordinate(puzzle[i][j], puzzle, final, difference);
            result += computeDistance(difference.front(), difference.back());
        }
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
        // EXPEND NODE FUNCTION THAT RETURN VECTOR<VECTOR2D>
        print_puzzle(puzzle);
        std::cout << "EXPEND NODES:\n" << std::endl;
        node puzzle_node;
        puzzle_node.grid = puzzle;
        puzzle_node.g = 0;
        puzzle_node.parent = NULL;
        std::vector<node> expend_list = expend_node(puzzle_node);
        for (int i = 0; i < expend_list.size(); i++)
            print_puzzle(expend_list[i].grid);

        // MANHATTAN HEURISTIC FUNCTION
        // vector2d final = finalPuzzle(puzzle.size());
        // std::cout << "Man value:" << manhattanHeuristic(puzzle, final) << std::endl;
        // aStarAlgorithm(puzzle);

    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}