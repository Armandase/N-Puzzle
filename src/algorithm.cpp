#include "../inc/algorithm.hpp"
#include "../inc/utils.hpp"
#include "../inc/manhattanHeuristic.hpp"

bool findInstance(const node& toFind, nodePrioQueue list){
    while (!list.empty()){
        if (list.top().puzzle == toFind.puzzle)
            return (true);
        list.pop();
    }
    return false;
}

void    printPrioQueue(nodePrioQueue list){
    std::cout << "LIST BEGIN: \n";
    while (!list.empty()){
        std::cout << list.top().f << "\n";
        list.pop();
    }
    std::cout << "END: \n";
}

node    aStarAlgorithm(const vector2d& puzzle, int heuristic(const vector2d &, const vector2d &)){
    nodePrioQueue open_list;
    node goal = {finalPuzzle(puzzle.size()), 0, 0, std::vector<vector2d>(0)};
    node start = {puzzle, 0, heuristic(puzzle, goal.puzzle), std::vector<vector2d>(0)};
    open_list.push(start);

    std::map<vector2d, int> close_list;
    
    std::vector<node> check_node;
    unsigned long max_open = 0;
    unsigned long i = 0;

    while (!open_list.empty()) {
        node process = open_list.top();

        if (process.puzzle == goal.puzzle){
            std::cout << "complexity in size: " << max_open << std::endl;
            std::cout << "complexity in time: " << i << std::endl;
            return (process);
        }
        open_list.pop();
        check_node = expend_node(process, goal, heuristic);
        for (node current: check_node) {
            if (current.puzzle == goal.puzzle){
                std::cout << "complexity in size: " << max_open << std::endl;
                std::cout << "complexity in time: " << i << std::endl;
                return (current);
            }

            if (close_list.find(current.puzzle) != close_list.end())
                continue;

            // if (findInstance(current, open_list) == true)
            //     continue;
            
            //made a copy of open list and iter through we found current
            open_list.push(current);
            i++;
        }
        close_list.insert(std::make_pair(process.puzzle, process.f));
        if (max_open < open_list.size())
            max_open = open_list.size();
        // printPrioQueue(open_list);
    }
    std::cout << "complexity in size: " << max_open << std::endl;
    std::cout << "complexity in time: " << i << std::endl;
    throw(std::logic_error("aStarAlgorithm: No solution found"));
}
