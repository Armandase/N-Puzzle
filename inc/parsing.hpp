#ifndef __PARSING_HPP__
# define __PARSING_HPP__

# include "npuzzle.hpp"
# include <fstream>
# define DELIMITER "\n\r\t "
# include <cstring>
# include <algorithm>

vector2d parse_file(const char *);
vector2d generate_puzzle(void);

#endif