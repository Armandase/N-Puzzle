#ifndef __NPUZZLE_HPP__
#define __NPUZZLE_HPP__

# include <exception>
# include <iostream>
# include <vector>
# include <queue>

# define USAGE "Usage: ./n-puzzle <file.txt>"

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

    // t_node(vector2d newPuzzle, int newG, int newF, std::vector<vector2d> newParent)
    //     : puzzle(newPuzzle)
    //     , g(newG)
    //     , f(newF)
    //     , parent(newParent)
    // {        
    // }
} node;

typedef std::vector<std::vector<int>> vector2d;
typedef std::priority_queue<node, std::vector<node>, compare> nodePrioQueue;

#endif