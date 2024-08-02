SRCS =			Harl.cpp\
				main.cpp
OBJS =			$(SRCS:.cpp=.o)
CXXFLAGS =		-Wall -Werror -Wextra -g3 -std=c++98
CXX =			c++
NAME =			Harl

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
				rm -f $(OBJS)

fclean:			clean
				rm -f $(NAME)

re:				fclean all