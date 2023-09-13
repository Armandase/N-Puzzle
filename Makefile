CXX		=	c++
NAME 	= 	n-puzzle
SRC 	=	main.cpp parsing.cpp utils.cpp
HEADER	=	inc/parsing.hpp inc/npuzzle.hpp inc/utils.hpp
OBJS	=	$(addprefix obj/, $(SRC:.cpp=.o))
CXXFLAGS=	-Wall -Wextra --std=c++14 -g


all		:	${NAME}

${NAME}	:	${OBJS} ${HEADER}
			${CXX} ${CXXFLAGS} -o ${NAME} ${OBJS}

obj/%.o: src/%.cpp $(HEADER)
	@mkdir -p $(@D)
	${CXX} ${CXXFLAGS} -c $< -o $@

fclean: clean
	rm -f $(NAME)

clean:
	rm -rf obj/

re: fclean all

.PHONY: all fclean clean re
