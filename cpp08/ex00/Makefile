SRCS =		main.cpp
HEADERS =	easyfind.hpp\
			easyfind.tpp
OBJS =		$(SRCS:.cpp=.o)
CXX =		c++
CXXFLAGS =	-Wall -Wextra -Wall -std=c++98 -g3
NAME =		ex00

all:		$(NAME)

re:			fclean all

$(NAME):	$(OBJS)
			$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)