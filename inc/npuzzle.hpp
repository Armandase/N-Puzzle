#ifndef __NPUZZLE_HPP__
#define __NPUZZLE_HPP__

# include <exception>
# include <iostream>
# include <vector>
# include <queue>

#define USAGE "Usage: ./n-puzzle <file.txt>"
#define EXTENSION ".txt"

typedef std::vector<std::vector<int> > vector2d;

enum heuristic
{
    MANHATTAN = 1,
    LINEAR,
    EUCLIDIAN,
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