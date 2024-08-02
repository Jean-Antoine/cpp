SRCS_F =		Contact.cpp\
				PhoneBook.cpp\
				main.cpp
OBJS_F =		$(SRCS_F:.cpp=.o)
CXXFLAGS =		-Wall -Werror -Wextra -std=c++98 -g3
CXX =			c++
NAME =			PhoneBook

all:			$(NAME)

$(NAME):		$(OBJS_F)
				$(CXX) $(CFLAGS) -o $(NAME) $(OBJS_F)

clean:
				rm -f *.o

fclean:			clean
				rm -f PhoneBook

re:				clean all