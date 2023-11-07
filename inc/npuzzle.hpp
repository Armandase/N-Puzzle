#ifndef __NPUZZLE_HPP__
#define __NPUZZLE_HPP__

# include <exception>
# include <iostream>
# include <vector>
# include <queue>
# include <set>

#define USAGE "Usage: ./n-puzzle <file.txt>"
#define EXTENSION ".txt"
#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"

typedef std::vector<std::vector<int> > vector2d;

enum heuristic
{
    MANHATTAN = 1,
    LINEAR,
    HAMMING,
    EUCLIDIAN,
    MISPLACED
};

typedef struct t_node
{
    vector2d    puzzle;
    int         g;
    int         f;
    std::vector<vector2d>  parent;
} node;

struct compare
{
    bool operator()(node const& left, node const& right){
        return (left.f > right.f);
    }
};

typedef std::priority_queue<node, std::vector<node>, compare> nodePrioQueue;

#endif