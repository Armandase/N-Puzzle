#include "../inc/algorithm.hpp"
#include "../inc/utils.hpp"
#include "../inc/manhattanHeuristic.hpp"

struct compare
{
    bool operator()(node const& left, node const& right){
        return (left.f < right.f);
    }
};

std::vector<node>::iterator findInstance(const node& process, std::vector<node>& list){
    std::vector<node>::iterator end = list.end();
    for (std::vector<node>::iterator it  = list.begin(); it != end; it++){
        if (it->puzzle == process.puzzle)
            return (it);
    }
    return end;
}

nodePrioQueue    findLowestF(nodePrioQueue queue){
    std::priority_queue<node> result;
    const int value = queue.top().f;
    const int size = queue.size();

    for (int i = 0; i < size; i++) {
        if (queue.top().f > value)
            break;
        result.push(queue.top());
        queue.pop();
    }

    return (result);
}

bool compareNodeByF(const node& a, const node& b) {
    return (a.f < b.f);
}

node    aStarAlgorithm(const vector2d& puzzle, int heuristic(const vector2d &, const vector2d &)){
    node goal = {finalPuzzle(puzzle.size()), 0, 0, std::vector<vector2d>(0)};
    node start = {puzzle, 0, heuristic(puzzle, goal.puzzle), std::vector<vector2d>(0)};
    nodePrioQueue open_list;
    open_list.push(start);
    
    std::vector<node> closed_list;
    std::vector<node> check_node;
    nodePrioQueue process_list;
    int i = 1;
    unsigned long max_open = 0;

    while (!open_list.empty()) {
        process_list = findLowestF(open_list);

        for (node process : process_list) {
            if (process.puzzle == goal.puzzle){
                std::cout << "complexity in size: " << max_open << std::endl;
                std::cout << "complexity in time: " << i << std::endl;
                return (process);
            }
            open_list.erase(findInstance(process, open_list));

            check_node = expend_node(process, goal, heuristic);
            for (node current: check_node) {
                if (current.puzzle == goal.puzzle){
                    std::cout << "complexity in size: " << max_open << std::endl;
                    std::cout << "complexity in time: " << i << std::endl;
                    return (current);
                }

                std::vector<node>::iterator it_close = findInstance(current, closed_list);
                if (it_close != closed_list.end()){
                    continue;
                }

                std::vector<node>::iterator it_tmp = findInstance(current, open_list);
                if (it_tmp != open_list.end()){
                    continue;
                } else {
                    std::vector<node>::iterator insert_pos = std::lower_bound(open_list.begin(), open_list.end(), current, compareNodeByF);
                    open_list.insert(insert_pos, current);
                    i++;
                }
            }
            closed_list.push_back(process);
        }
        if (max_open < open_list.size())
            max_open = open_list.size();
    }
    std::cout << "complexity in size: " << max_open << std::endl;
    std::cout << "complexity in time: " << i << std::endl;
    throw(std::logic_error("aStarAlgorithm: No solution found"));
}
