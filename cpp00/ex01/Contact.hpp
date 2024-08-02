/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:30:21 by jeada-si          #+#    #+#             */
/*   Updated: 2024/07/29 16:32:03 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H
# include <iostream>
# define RESET		"\e[0m"
# define DISPLAY	"\e[1;35m"
# define BOLD(x)	"\e[1m" x RESET
# define WRONG(x)	"\e[31m" x RESET
# define INSTR(x)	BOLD("\e[36m" x)

class Contact
{
	private:
		int			index;
		std::string	firstName;
		std::string	lastName;
		std::string nickname;
		std::string	number;
		std::string	darkestSecret;
	public:
		Contact();
		~Contact();
		void	set(int i);
		void	display();
		void	displayFull();
};

#endif