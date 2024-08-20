SRCS =		AMateria.cpp\
			main.cpp\
			Cure.cpp\
			Ice.cpp\
			ICharacter.cpp\
			Character.cpp\
			IMateriaSource.cpp\
			MateriaSource.cpp
OBJS =		$(SRCS:.cpp=.o)
CXX =		c++
CXXFLAGS =	-Wall -Werror -Wextra -std=c++98 -g3
NAME =		Materia

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all