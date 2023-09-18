#include "../inc/parsing.hpp"
#include "../inc/utils.hpp"

std::vector<int> mysplit(std::string & line, std::string delimiter) {
	std::string str;
	std::vector<int> tab;
	for (unsigned long i = 0; i < line.size(); i++) {
		while (line[i] && strchr(delimiter.c_str(), line[i]))
			i++;
		if (line[i] == '\0')
			return (tab);
		while (line[i] && !strchr(delimiter.c_str(), line[i])) {
			str += line[i];
			i++;
		}
		tab.push_back(std::stoi(str));
		str.clear();
	}
	return (tab);
}

void check_extension(const std::string & file, std::string extension) {
    if (file.substr(file.find_last_of('.')) != extension)
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

    do {
        if (!getline(input, line))
            throw(std::logic_error("pars_file: empty file"));
        line = line.substr(0, line.find_first_of('#'));
    } while (line == "");

    if (line.find_first_of(' ') != std::string::npos
        || line.find_first_of('\t') != std::string::npos)
        throw(std::logic_error("parse_file: need to precise size of the square in the file"));

    return std::stoi(line);
}

vector2d parse_file(const char * str) {
    std::string file(str);
    check_extension(file, ".txt");

    std::ifstream input(file);
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
    check_solvability(puzzle, size);  
    return puzzle;
}