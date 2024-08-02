SRCS_F =		Account.cpp\
				tests.cpp
OBJS_F =		$(SRCS_F:.cpp=.o)
CXXFLAGS =		-Wall -Werror -Wextra -std=c++98 -g3
CXX =			c++
NAME =			Account

all:			$(NAME)

$(NAME):		$(OBJS_F)
				$(CXX) $(CFLAGS) -o $(NAME) $(OBJS_F)

clean:
				rm -f *.o

fclean:			clean
				rm -f $(NAME)

re:				clean all