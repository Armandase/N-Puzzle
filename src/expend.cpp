#include "../inc/algorithm.hpp"
#include "../inc/utils.hpp"
#include "../inc/manhattanHeuristic.hpp"


vector2d node_movement(vector2d node, int & x, int & y, const int & direction) {
    int switch_number;
    switch (direction) {
        case UP:
            if (x == 0)
                break;
            switch_number = node[x - 1][y];
            node[x - 1][y] = 0;
            node[x][y] = switch_number;
            break;
        case DOWN:
            if (x == int(node.size()) - 1)
                break;
            switch_number = node[x + 1][y];
            node[x + 1][y] = 0;
            node[x][y] = switch_number;
            break;
        case RIGHT:
            if (y == int(node.size()) - 1)
                break;
            switch_number = node[x][y + 1];
            node[x][y + 1] = 0;
            node[x][y] = switch_number;
            break;
        case LEFT:
            if (y == 0)
                break;
            switch_number = node[x][y - 1];
            node[x][y - 1] = 0;
            node[x][y] = switch_number;
            break;
        default:
            throw(std::logic_error("node: bad directions"));
    }
    return node;
}

std::vector<node> add_nodes(node p_node, node & goal, int & x, int & y) {
    node new_node;
    std::vector<node> expend_list;
    for (int i = 0; i < 4; i++) {
        new_node.puzzle = node_movement(p_node.puzzle, x, y, i);
        new_node.g = p_node.g + 1;
        new_node.f = new_node.g + linearConflict(new_node.puzzle, goal.puzzle);
        new_node.parent = p_node.parent;
        new_node.parent.push_back(p_node.puzzle);
        if (new_node.puzzle != p_node.puzzle)
            expend_list.push_back(new_node);
    }
    return expend_list;
}

std::vector<node> expend_node(node & p_node, node & goal) {
    const int size = p_node.puzzle.size();
    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            if (p_node.puzzle[x][y] == 0)
                return add_nodes(p_node, goal, x, y);
        }
    }
    throw(std::logic_error("expend_node: no zero in this puzzle"));
}
