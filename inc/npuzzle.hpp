#ifndef __NPUZZLE_HPP__
#define __NPUZZLE_HPP__

# include <exception>
# include <iostream>
# include <vector>
# include <queue>

# define USAGE "Usage: ./n-puzzle <file.txt>"
# define EXTENSION ".txt"

# ifndef ALGORITHM
#   define ALGORITHM 0
# endif


typedef std::vector<std::vector<int> > vector2d;

enum heuristic
{
    MANHATTAN = 1,
    LINEAR,
    EUCLIDIAN,
};

enum algorithm
{
    ASTAR = 0,
    GREEDY,
    UNINFORMED,
};

typedef struct t_node
{
    vector2d    puzzle;
    int         g;
    int         f;
    int         h;
    std::vector<vector2d>  parent;
} node;

struct compare
{
#if ALGORITHM == 0
    bool operator()(node const& left, node const& right){
        return (left.f > right.f);
    }
#endif

#if ALGORITHM == 1
    bool operator()(node const& left, node const& right){
        return (left.h > right.h);
    }
#endif

#if ALGORITHM == 2
    bool operator()(node const& left, node const& right){
        return (left.g > right.g);
    }
#endif
    
};

typedef std::priority_queue<node, std::vector<node>, compare> nodePrioQueue;

#endif