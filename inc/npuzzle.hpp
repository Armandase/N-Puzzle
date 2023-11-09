#ifndef __NPUZZLE_HPP__
#define __NPUZZLE_HPP__

# include <exception>
# include <iostream>
# include <vector>
# include <queue>
# include <set>

# define USAGE "Usage: ./n-puzzle <file.txt>"
# define EXTENSION ".txt"

# ifndef ALGORITHM
#   define ALGORITHM 0
# endif

# define SCREEN_HEIGHT 500
# define SCREEN_WIDTH 500
# define RENDER_SPEED 500000
# define RENDER_FINAL 5


typedef std::vector<std::vector<int> > vector2d;

enum heuristic
{
    MANHATTAN = 1,
    LINEAR,
    HAMMING,
    EUCLIDIAN,
    MISPLACED
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
#elif ALGORITHM == 1
    bool operator()(node const& left, node const& right){
        return (left.h > right.h);
    }
#elif ALGORITHM == 2
    bool operator()(node const& left, node const& right){
        return (left.g > right.g);
    }
#endif
    
};

typedef std::priority_queue<node, std::vector<node>, compare> nodePrioQueue;

#endif