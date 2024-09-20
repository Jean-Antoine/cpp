SRCS =		main.cpp\
			Span.cpp
HEADERS =	Span.hpp
OBJS =		$(SRCS:.cpp=.o)
CXX =		c++
CXXFLAGS =	-Wall -Wextra -Wall -std=c++98 -g3
NAME =		ex01

all:		$(NAME)

re:			fclean all

$(NAME):	$(OBJS)
			$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)