SRCS =		main.cpp\
			Fixed.cpp\
			Point.cpp\
			bsp.cpp
OBJS =		$(SRCS:.cpp=.o)
CXXFLAGS = 	-Wall -Werror -Wextra -std=c++98 -g3
CXX =		c++
NAME =		Fixed

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all