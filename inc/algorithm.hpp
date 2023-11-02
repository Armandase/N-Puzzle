#ifndef __ALGORITHM_HPP__
# define __ALGORITHM_HPP__

# include   "npuzzle.hpp"
# include   <algorithm>
# include   <limits>
# include   <map>

enum direction {
    UP,
    DOWN,
    RIGHT,
    LEFT,
};

node    aStarAlgorithm(const vector2d&, int heuristic(const vector2d &, const vector2d &));
node    aStarAlgorithmV2(vector2d&);
std::vector<node> expend_node(node &, node &, int heuristic(const vector2d &, const vector2d &));
nodePrioQueue    findLowestF(nodePrioQueue);

#endif