#ifndef __PARSING_HPP__
# define __PARSING_HPP__

# include "npuzzle.hpp"
# include <fstream>
# include <cstring>
# include <algorithm>

# define DELIMITER "\n\r\t "


vector2d parse_file(const char *);
vector2d generate_puzzle(void);

#endif