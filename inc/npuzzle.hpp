#ifndef __NPUZZLE_HPP__
#define __NPUZZLE_HPP__

#include <exception>
#include <iostream>
#include <vector>

#define USAGE "Usage: ./n-puzzle <file.txt>"
#define EXTENSION ".txt"

enum heuristic
{
    MANHATTAN = 1,
    LINEAR,
    EUCLIDIAN,
};

typedef std::vector<std::vector<int>> vector2d;

#endif