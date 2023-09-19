#include "../inc/algorithm.hpp"
#include "../inc/utils.hpp"
#include "../inc/manhattanHeuristic.hpp"
#include <algorithm>

node    aStarAlgorithmV2(vector2d& puzzle){
    node goal = {finalPuzzle(puzzle.size()), 0, 0, std::vector<vector2d>(0)};
    node start = {puzzle, 0, 0, std::vector<vector2d>(0)};
    std::vector<node> open_list = { start };
    std::vector<node> closed_list;
    std::vector<node> child;

    while (!open_list.empty()) {
        node current = open_list[0];
        int current_index = 0;
        const int size = open_list.size();
        for (int i = 0; i < size; i++) {
            if (open_list[i].f < current.f) {
                current = open_list[i];
                current_index = i;
            }
        }

        open_list.erase(open_list.begin() + current_index);
        closed_list.push_back(current);

        if (current.puzzle == goal.puzzle)
            return (current);

        child = expend_node(current, goal);
        const int child_size = child.size();
        for (int i = 0; i < child_size; i++) {
            const int closed_size = closed_list.size();
            for (int j = 0; j < closed_size; j++) {
                if (child[i].puzzle == closed_list[j].puzzle)
                    continue;
            }

            const int open_size = open_list.size();
            for (int j = 0; j < open_size; j++) {
                if (child[i].puzzle == open_list[j].puzzle && child[i].g > open_list[j].g)
                    continue;
            }

            open_list.push_back(child[i]);
        }
    }
    throw(std::logic_error("aStarAlgorithm: No solution found"));
}