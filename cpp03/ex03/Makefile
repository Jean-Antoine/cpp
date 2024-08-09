SRCS =		main.cpp\
			ClapTrap.cpp\
			ScavTrap.cpp \
			FragTrap.cpp \
			DiamondTrap.cpp
OBJS =		$(SRCS:.cpp=.o)
CXX =		c++
CXXFLAGS =	-Wall -Werror -Wextra -std=c++98 -g3 -Wno-shadow
NAME =		DiamondTrap

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all