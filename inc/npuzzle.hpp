#ifndef __NPUZZLE_HPP__
# define __NPUZZLE_HPP__

# include <exception>
# include <iostream>
# include <vector>
# define USAGE "Usage: ./n-puzzle <file.txt>"

typedef std::vector<std::vector<int> > vector2d;

typedef struct s_point{
    int x;
    int y;
} point;

#endif