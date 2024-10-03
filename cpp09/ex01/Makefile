SRCS =		main.cpp\
			RPN.cpp
OBJS =		$(SRCS:.cpp=.o)
CXX =		c++
CXXFLAGS =	-Wall -Werror -Wextra -std=c++98 -g3
NAME =		RPN

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all