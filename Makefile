CXX			=	c++
NAME 		= 	n-puzzle
SRC 		=	main.cpp parsing.cpp \
			utils.cpp algorithm.cpp \
			expend.cpp manhattanHeuristic.cpp \
			hammingDistanceBoosted.cpp solvable.cpp \
			linearConflict.cpp otherHeuristic.cpp \
			graphicalRender.cpp
HEADER	=	inc/parsing.hpp inc/npuzzle.hpp \
			inc/utils.hpp inc/algorithm.hpp \
			inc/heuristic.hpp
OBJS		=	$(addprefix obj/, $(SRC:.cpp=.o))
CXXFLAGS	=	-Wall -Wextra --std=c++14 -g
ALGORITHM	=	-D ALGORITHM=0

all		:	${NAME}

lib:
	git clone https://github.com/raysan5/raylib.git raylib
	make -C raylib/src



greedy: ALGORITHM = -D ALGORITHM=1

greedy	: ${NAME}

uninformed: ALGORITHM = -D ALGORITHM=2

uninformed: ${NAME}

${NAME}	:	${OBJS} ${HEADER}
			${CXX} ${CXXFLAGS} -o ${NAME} ${OBJS} -Lraylib/src -lraylib

obj/%.o: src/%.cpp $(HEADER)
	@mkdir -p $(@D)
	${CXX} ${CXXFLAGS} ${ALGORITHM} -c $< -o $@

fclean: clean
	rm -f $(NAME)

clean:
	rm -rf obj/

re: fclean all

.PHONY: all fclean clean re greedy uninformed lib
