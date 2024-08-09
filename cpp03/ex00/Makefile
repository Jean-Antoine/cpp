SRCS =		main.cpp\
			ClapTrap.cpp
OBJS =		$(SRCS:.cpp=.o)
CXX =		c++
CXXFLAGS =	-Wall -Werror -Wextra -std=c++98 -g3
NAME =		ClapTrap

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f ClapTrap

re:			fclean all