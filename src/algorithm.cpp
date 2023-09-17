#include "../inc/algorithm.hpp"
#include "../inc/utils.hpp"


void    aStarAlgorithm(vector2d& puzzle){
    std::cout << "received\n"; 
}

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

std::vector<vector2d> add_nodes(const vector2d & node, int & x, int & y) {
    vector2d new_node;
    std::vector<vector2d> expend_list;
    for (int i = 0; i < 4; i++) {
        new_node = node_movement(node, x, y, i);
        if (new_node != node)
            expend_list.push_back(new_node);
    }
    return expend_list;
}

std::vector<vector2d> expend_node(const vector2d & node) {
    const int size = node.size();
    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            if (node[x][y] == 0)
                return add_nodes(node, x, y);
        }
    }
    throw(std::logic_error("expend_node: no zero in this puzzle"));
}
