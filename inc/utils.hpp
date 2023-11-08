#ifndef __UTILS_HPP__
# define __UTILS_HPP__

# include "npuzzle.hpp"

# define PUZZLE_SIZE 4

void    print_puzzle(const vector2d&);
vector2d finalPuzzle(const int&);
std::vector<int> convert_vector(const vector2d &);
void    graphical_render(node& result);


#endif