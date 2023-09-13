#include "../inc/parsing.hpp"

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

vector2d parse_file(const char * str) {
    std::string file(str);
    check_extension(file, ".txt");
    std::ifstream input(file);
    std::string line;
    if (!getline(input, line))
        throw(std::logic_error("pars_file: empty file"));
    int puzzle_len = std::stoi(line);
    vector2d puzzle; 
    while (getline(input, line)) {
        std::string no_comment_line = line.substr(0, line.find_first_of('#'));
        puzzle.push_back(mysplit(no_comment_line, DELIMITER));
    }
    print_puzzle();
}