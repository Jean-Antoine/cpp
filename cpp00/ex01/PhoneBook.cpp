/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:17:02 by jeada-si          #+#    #+#             */
/*   Updated: 2024/07/31 14:10:31 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>
#include <string>
#include <iostream>

PhoneBook::PhoneBook()
{
	i = 0;
	// std::cout << "PhoneBook created." << std::endl;
}

PhoneBook::~PhoneBook()
{
	// std::cout << "PhoneBook destructed." << std::endl;
}

void	PhoneBook::add()
{
	int	index;

	index = i % MAX_CONTACT;
	arr[index].set(index);
	i++;
}

int	getIndex(int i)
{
	std::string	index;

	std::cout << INSTR("Enter index ");
	std::getline(std::cin, index);
	if (index.size() == 1
		&& index[0] >= '0'
		&& index[0] < '0' + i
		&& index[0] < '0' + MAX_CONTACT)
		return (index[0] - '0');
	std::cout << WRONG("Wrong index") << std::endl;
	return (-1);
}

void	PhoneBook::display()
{
	int	nb_contacts;
	
	if (i == 0)
		std::cout << WRONG("PhoneBook is empty.") << std::endl;
	nb_contacts = i < MAX_CONTACT ? i : MAX_CONTACT;
	for (int j = 0; j < nb_contacts; j++)
		arr[j].display();
}

void	PhoneBook::search()
{
	int	index;
	
	this->display();
	if (i == 0)
		return ;
	index = getIndex(i);
	if (index == -1)
		return ;
	arr[index].displayFull();
}

void	PhoneBook::run()
{
	std::string		instruction;
	
	while (1 && !std::cin.eof())
	{
		std::cout << INSTR("Enter instruction (ADD, SEARCH, EXIT) ");
		std::getline(std::cin, instruction);
		if (!instruction.compare("ADD"))
			this->add();
		else if (!instruction.compare("SEARCH"))
			this->search();
		else if (!instruction.compare("EXIT"))
			break ;
		else
			std::cout << WRONG("Wrong instruction.") << std::endl;
	}
	if (std::cin.eof())
		std::cout << WRONG("Stdin has been closed.") << std::endl;
}