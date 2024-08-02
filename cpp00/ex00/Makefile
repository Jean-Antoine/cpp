# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/23 16:10:43 by jeada-si          #+#    #+#              #
#    Updated: 2024/07/23 16:46:07 by jeada-si         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: 				megaphone

megaphone: 			megaphone.cpp
					c++ -Wall -Wextra -Werror -std=c++98 megaphone.cpp -o megaphone

clean:
					rm megaphone

fclean:				clean

re:					fclean megaphone

test:				megaphone
					./megaphone "shhhhh... I think the students are asleep..."
					./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
					./megaphone