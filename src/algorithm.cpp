#include "../inc/algorithm.hpp"
#include "../inc/utils.hpp"


node    findLowestF(const std::vector<node>& list){
    int lowest = INT64_MAX;
    const int size = list.size();
    int instance = 0;

    for (int i = 0; i < size; i++){
        if (list[i].f < lowest){
            instance = i;
            lowest = list[i].f;
        }
    }
    return (list[instance]);
}

void    aStarAlgorithm(vector2d& puzzle){
    node start = {puzzle, 0, 0, NULL};
    node goal = {finalPuzzle(puzzle.size()), 0, 0, NULL};
    std::vector<node> open_list = {start};
    std::vector<node> closed_list;
    node process;

    while (!open_list.empty()){
        process = findLowestF(open_list);
        if (process.puzzle == goal.puzzle)
            return (process);
        
    }
}

