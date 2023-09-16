#include "../inc/npuzzle.hpp"
#include "../inc/parsing.hpp"
#include "../inc/utils.hpp"
#include "../inc/algorithm.hpp"

typedef struct t_point {
    int x;
    int y;
} point;

point   getCoordinate(const int& value, const vector2d& puzzle)
{
    const int size = puzzle.size();   
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            if (puzzle[i][j] == value){
                point result = {j, i};
                return (result);
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
    point puzzleCoo;
    point finalCoo;

    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            if (puzzle[i][j] == 0)
                continue ;
            puzzleCoo = getCoordinate(puzzle[i][j], puzzle);
            finalCoo = getCoordinate(puzzle[i][j], final);
            result += computeDistance(puzzleCoo, finalCoo);
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
        vector2d final = finalPuzzle(puzzle.size());
        std::cout << "Man value:" << manhattanHeuristic(puzzle, final) << std::endl;
        // aStarAlgorithm(puzzle);

    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}