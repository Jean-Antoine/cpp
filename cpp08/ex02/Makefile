SRCS =		main.cpp
HEADERS =	MutantStack.hpp\
			MutantStack.tpp
OBJS =		$(SRCS:.cpp=.o)
CXX =		c++
CXXFLAGS =	-Wall -Wextra -Wall -std=c++98 -g3
NAME =		ex02

all:		$(NAME)

re:			fclean all

$(NAME):	$(OBJS)
			$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)