#include "../inc/algorithm.hpp"
#include "../inc/utils.hpp"
#include "../inc/heuristic.hpp"

bool findInstance(const node& toFind, nodePrioQueue list){
    while (!list.empty()){
        if (list.top().puzzle == toFind.puzzle)
            return (true);
        list.pop();
    }
    return false;
}

static void printComplexity(unsigned long i, unsigned long max_open){
    std::cout << "complexity in size: " << max_open << std::endl;
    std::cout << "complexity in time: " << i << std::endl;
}

node    aStarAlgorithm(const vector2d& puzzle, int heuristic(const vector2d &, const vector2d &)){
    nodePrioQueue open_list;
    node goal = {finalPuzzle(puzzle.size()), 0, 0, 0, std::vector<vector2d>(0)};
    node start = {puzzle, 0, heuristic(puzzle, goal.puzzle), heuristic(puzzle, goal.puzzle), std::vector<vector2d>(0)};
    open_list.push(start);

    std::map<vector2d, int> close_list;
    
    std::vector<node> check_node;
    unsigned long max_open = 0;
    unsigned long i = 0;

    while (!open_list.empty()) {
        node process = open_list.top();

        if (process.puzzle == goal.puzzle){
            printComplexity(i, max_open);
            return (process);
        }
        open_list.pop();
        check_node = expend_node(process, goal, heuristic);
        for (node current: check_node) {
            if (current.puzzle == goal.puzzle){
                printComplexity(i, max_open);
                return (current);
            }

            if (close_list.find(current.puzzle) != close_list.end())
                continue;
            // if (findInstance(current, open_list) == true)
            //     continue;
            open_list.push(current);
            i++;
        }
        close_list.insert(std::make_pair(process.puzzle, process.f));
        if (max_open < open_list.size())
            max_open = open_list.size();
    }
    printComplexity(i, max_open);
    throw(std::logic_error("aStarAlgorithm: No solution found"));
}

// node UCSAlgorithm(const vector2d& puzzle) {
//     nodePrioQueue open_list;
//     node goal = {finalPuzzle(puzzle.size()), 0, 0, std::vector<vector2d>(0)};
//     node start = {puzzle, 0, 0, std::vector<vector2d>(0)};
//     open_list.push(start);

//     std::map<vector2d, int> close_list;
    
//     unsigned long max_open = 0;
//     unsigned long i = 0;

//     while (!open_list.empty()) {
//         node process = open_list.top();
//         open_list.pop();

//         if (process.puzzle == goal.puzzle){
//             printComplexity(i, max_open);
//             return process;
//         }

//         if (close_list.find(process.puzzle) != close_list.end())
//             continue;

//         close_list[process.puzzle] = process.g;

//         std::vector<node> check_node = expend_node(process, goal);
//         for (node current : check_node) {
//             if (close_list.find(current.puzzle) != close_list.end())
//                 continue;
            
//             open_list.push(current);
//             i++;
//         }

//         if (max_open < open_list.size())
//             max_open = open_list.size();
//     }

//     printComplexity(i, max_open);
//     throw std::logic_error("UCSAlgorithm: No solution found");
// }