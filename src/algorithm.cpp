#include "../inc/algorithm.hpp"


void    aStarAlgorithm(vector2d& puzzle){
    std::cout << "received\n"; 
}

vector2d node(const vector2d node, const int & x, const int & y, const int & direction) {
    switch (direction) {
        case UP:
        case DOWN:
        case RIGHT:
        case LEFT:
        default:
    }
}

std::vector<node> expend_node(const std::vector<vector2d> & closed, const vector2d & node) {
    std::vector<t_node> expend_list;
    const int size = node.size();
    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            if (node[x][y] == 0)
                expend_list(node(node, x, y, UP));
                expend_list(node(node, x, y, DOWN));
        }
    }
}
