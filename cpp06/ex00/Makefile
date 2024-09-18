SRCS =		From.cpp\
			FromCharacter.cpp\
			ScalarConverter.cpp\
			main.cpp\
			FromInt.cpp\
			FromFloat.cpp\
			FromDouble.cpp
OBJS =		$(SRCS:.cpp=.o)
CXX =		c++
CXXFLAGS =	-Wall -Werror -Wextra -std=c++98 -g3
NAME =		ScalarConverter

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

echo:		
			echo $(OBJS)