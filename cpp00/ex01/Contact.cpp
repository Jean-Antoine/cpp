/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:58:58 by jeada-si          #+#    #+#             */
/*   Updated: 2024/07/31 14:23:18 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iomanip>
#include <cctype>

static std::string purgeNonprintable(std::string s)
{
	std::string	s_;

	for (unsigned i = 0; i < s.size(); i++)
		if (std::isprint(s[i]))
			s_.push_back(s[i]);
	return (s_);
}

static void	ft_getline(std::string msg, std::string *target)
{
	std::string	s = "";
	
	if (std::cin.eof())
		return ;
	while (!s.size() && !std::cin.eof())
	{
		std::cout << msg;
		std::getline(std::cin, s);
		s = purgeNonprintable(s);
		if (!s.size())
			std::cout << WRONG("The field cannot be empty.") << std::endl;
	}		
	*target = s;
}

Contact::Contact()
{
	// std::cout << "Contact constructor called." << std::endl;
}

Contact::~Contact()
{
	// std::cout << "Contact destructor called." << std::endl;
}

void Contact::set(int i)
{
	index = i;
	ft_getline(INSTR("First name: "), &firstName);
	ft_getline(INSTR("Last name: "), &lastName);
	ft_getline(INSTR("Nickname: "), &nickname);
	ft_getline(INSTR("Number: "), &number);
	ft_getline(INSTR("Darkest secret: "), &darkestSecret);
}

static void displayWidth(std::string s, unsigned int n, std::string sep)
{
	if (s.size() > n)
		std::cout << s.substr(0, n - 1) << ".";
	else
		std::cout << std::setfill(' ') << std::setw(n) << std::right << s;
	std::cout << sep;
}

static void displayHeaders()
{
	std::cout << DISPLAY;
	displayWidth("Index", 10, "|");
	displayWidth("First name", 10, "|");
	displayWidth("Last name", 10, "|");
	displayWidth("Nickname", 10, "\n");
}

void	Contact::display()
{
	if (index == 0)
		displayHeaders();
	std::cout << DISPLAY << std::setfill(' ');
	std::cout << std::setw(10) << index << "|";
	displayWidth(firstName, 10, "|");
	displayWidth(lastName, 10, "|");
	displayWidth(nickname, 10, "\n" RESET);
}

static void displayWithLabel(std::string label, std::string value)
{
	std::cout << DISPLAY << std::setfill(' ') << std::setw(20) << std::left;
	std::cout << label << value << RESET << std::endl;
}

void Contact::displayFull()
{
	displayWithLabel("First name:", firstName);
	displayWithLabel("Last name:", lastName);
	displayWithLabel("Nickname:", nickname);
	displayWithLabel("Number:", number);
	displayWithLabel("Darkest secret:", darkestSecret);
}
