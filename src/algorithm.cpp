#include "../inc/algorithm.hpp"
#include "../inc/utils.hpp"
#include "../inc/manhattanHeuristic.hpp"
#include <algorithm>



std::vector<node>::iterator findInstance(const node& process, std::vector<node>& list){
    std::vector<node>::iterator end = list.end();
    for (std::vector<node>::iterator it  = list.begin(); it != end; it++){
        if (it->puzzle == process.puzzle)
            return (it);
    }
    return end;
}

std::vector<node>    findLowestF(const std::vector<node>& list, std::vector<node>& close){
    int lowest = INT32_MAX;
    const int size = list.size();
    std::vector<node> result;

    for (int i = 0; i < size; i++){
        if (list[i].f < lowest)
            lowest = list[i].f;
    }

    for (int i = 0; i < size; i++) {
        if (list[i].f == lowest)
            result.push_back(list[i]);
    }

    return (result);
}

#include <unistd.h>
node    aStarAlgorithm(vector2d& puzzle){
    node goal = {finalPuzzle(puzzle.size()), 0, 0, NULL};
    node start = {puzzle, 0, manhattanHeuristic(puzzle, goal.puzzle), NULL};
    std::vector<node> open_list = {start};
    std::vector<node> closed_list;
    std::vector<node> tmp;
    std::vector<node> check_node;
    std::vector<node> process_list;
    // node process;

    while (!open_list.empty()) {
        process_list = findLowestF(open_list, closed_list);

        for (node process : process_list) {
            if (process.puzzle == goal.puzzle)
                return (process);

            open_list.erase(findInstance(process, open_list));

            check_node = expend_node(process, goal);
            for (node current: check_node) {
                if (current.puzzle == goal.puzzle)
                    return (current);

                std::vector<node>::iterator it_close = findInstance(current, closed_list);
                if (it_close != closed_list.end()){
                    continue;
                }


                std::vector<node>::iterator it_tmp = findInstance(current, tmp);
                if (it_tmp != tmp.end()){
                    // if (current.g < it_tmp->g){
                        continue;
                    // }
                }else{
                    tmp.push_back(current);
                }

            }
            closed_list.push_back(process);
        }
        open_list = tmp;
        tmp.clear();
    }
    throw(std::logic_error("aStarAlgorithm: No solution found"));
}

