##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Libgraph
##

CXX			=	g++

RM			=	rm -f

CXXFLAGS	=	-Wextra -Wall
CXXFLAGS	+=	-I ./

NAME		=	libgraph.a

SRCS		=
TSRCS		=	tests/Test_Graph.cpp          \
                tests/Test_Dijkstra.cpp

TBIN		=	test_result_libgraph

all			: 	$(NAME)

$(NAME)		:
			@echo "Nothing to do."
			@echo "This library is written directly in header .hpp. You can use it by including the .hpp files in your source code."
			@echo "Type :	make tests_run    to run tests."

clean		:	;

fclean		:	clean
			$(RM) $(NAME)
			$(RM) $(TBIN)

re		:	fclean all

tests_run	:
			$(CXX) $(CXXFLAGS) -o $(TBIN) $(TSRCS) -lcriterion && ./$(TBIN)

.PHONY: all clean fclean re tests_run
