#include "../inc/npuzzle.hpp"
#include "../inc/parsing.hpp"

vector2d generate_puzzle() {
    
}

int main (int ac, char **av){
    try {
        if (ac > 3)
            throw (std::invalid_argument("main: wrong number of argument\n" + std::string(USAGE)));
        vector2d puzzle;
        if (ac == 2) {
            puzzle = pars_file(av[1]);
        } else {
            puzzle = generate_puzzle();
        }
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    
}