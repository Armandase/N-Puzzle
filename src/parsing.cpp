#include "../inc/parsing.hpp"
#include "../inc/utils.hpp"

std::vector<int> mysplit(std::string & line, std::string delimiter) {
	std::string str;
	std::vector<int> tab;
    char *endPtr;
	for (unsigned long i = 0; i < line.size(); i++) {
		while (line[i] && strchr(delimiter.c_str(), line[i]))
			i++;
		if (line[i] == '\0')
			return (tab);
		while (line[i] && !strchr(delimiter.c_str(), line[i])) {
			str += line[i];
			i++;
		}
        endPtr = nullptr;
        strtod(str.c_str(), &endPtr);
        if (strlen(endPtr) > 0)
            throw (std::logic_error("The puzzle need to contains only number: " + str));
		tab.push_back(std::stoi(str));
		str.clear();
	}
	return (tab);
}

void check_extension(const std::string & file, std::string extension) {
    size_t pointPos = file.find_last_of('.');
    if (pointPos == std::string::npos || file[pointPos - 1] == '/'
        || pointPos == 0 || file.substr(pointPos) != extension)
        throw(std::logic_error("check_extension: bad file extension\n" + std::string(USAGE)));
}

void check_puzzle_number(const vector2d &puzzle) {
    const int size = puzzle.size();
    std::vector<int> puzzle_numbers;
    for (int i = 0; i < size; i++) {
        puzzle_numbers.insert(puzzle_numbers.end(), puzzle[i].begin(), puzzle[i].end());
    }

    const int max_value = size * size - 1;
    for (int i = 0; i < max_value; i++) {
        if (std::find(puzzle_numbers.begin(), puzzle_numbers.end(), i) == puzzle_numbers.end())
            throw(std::logic_error("check_puzzle_number: the puzzle need to have number between 0 and " + std::to_string(max_value)));
    }
}

int get_puzzle_len(std::ifstream &input) {
    std::string line;
    char * endPtr;

    do {
        if (!getline(input, line))
            throw(std::logic_error("pars_file: empty file"));
        line = line.substr(0, line.find_first_of('#'));
    } while (line == "");

    if (line.find_first_of(' ') != std::string::npos
        || line.find_first_of('\t') != std::string::npos)
        throw(std::logic_error("parse_file: need to precise size of the square in the file"));
    strtod(line.c_str(), &endPtr);
    if (strlen(endPtr))
        throw(std::logic_error("parse_file: The puzzle size need to be a number: " + line));
    return std::stoi(line);
}

vector2d parse_file(const char * str) {
    std::string file(str);
    check_extension(file, EXTENSION);

    std::ifstream input(file);
    if (!input)
        throw(std::logic_error("parse_file: the file does not exist or cannot be opened\n" + std::string(USAGE)));
    std::string line;

    const int size = get_puzzle_len(input);
    vector2d puzzle; 
    std::vector<int> puzzle_line;
    while (getline(input, line)) {
        if (line == "")
            continue;
        line = line.substr(0, line.find_first_of('#'));
        puzzle_line = mysplit(line, DELIMITER);
        if (int(puzzle_line.size()) != size)
            throw(std::logic_error("parse_file: the puzzle is not a square of size: " + std::to_string(size)));
        puzzle.push_back(puzzle_line);
    }
    if (int(puzzle.size()) != size)
        throw(std::logic_error("parse_file: the puzzle is not a square of size: " + std::to_string(size)));

    check_puzzle_number(puzzle);
    return puzzle;
}