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

unsigned int get_inv_score(const vector2d & puzzle, const int & size) {
    int y;
    int number;
    int inv_count = 0;
    for (int x_check = 0; x_check < size; x_check++) {
        for (int y_check = 0; y_check < size; y_check++) {
            number = puzzle[x_check][y_check];
            if (number == 0)
                continue ;
            y = y_check;
            for (int x = x_check; x < size; x++) {
                for (; y < size; y++) {
                    if (puzzle[x][y] != 0 && puzzle[x][y] < number)
                        inv_count++;
                }
                y = 0;
            }
        }
    }
    return (inv_count);
}
int get_zero_row(const vector2d & puzzle, const int & size) {
    for (int x = 0; x < size;x++) {
        for (int y = 0; y < size; y++) {
            if (puzzle[x][y] == 0)
                return x + 1;
        }
    }
}

void check_solvability(const vector2d & puzzle, const int & size) {
    const int inv_initial = get_inv_score(puzzle, size);
    const vector2d goal_state = finalPuzzle(size);
    const int inv_goal = get_inv_score(goal_state, size);
    if (size % 2 == 1 && inv_goal % 2 == inv_initial % 2)
        return ;    
    if (size % 2 == 0) {
        const int blank_row_s = get_zero_row(puzzle, size);
        const int blank_row_g = get_zero_row(goal_state, size);
        if (inv_goal % 2 == 0 && inv_initial % 2 == abs(blank_row_g - blank_row_s) % 2)
            return ;
        if (inv_goal % 2 == 1 && inv_initial % 2 != abs(blank_row_g - blank_row_s) % 2)
            return ;
    }
    throw(std::logic_error("check_solvability: the puzzle is not solvable"));
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