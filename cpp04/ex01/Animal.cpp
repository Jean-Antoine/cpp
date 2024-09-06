/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:16:32 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/03 15:35:51 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>
#include <iomanip>

Animal::Animal()
{
	_type = "Animal";
	std::cout << BLUE << std::setfill('-') << std::setw(40) << "" << std::endl;
	if(VERBOSE)
		std::cout << BLUE "[Animal] Default constructor called" RESET << std::endl;
}

Animal::Animal(const Animal &src)
{
	_type = src._type;
	if(VERBOSE)
		std::cout << BLUE "[Animal] Copy constructor called" RESET << std::endl;
}

Animal& Animal::operator=(const Animal &src)
{
	_type = src._type;
	if(VERBOSE)
		std::cout << BLUE "[Animal] Assignment operator called" RESET << std::endl;
	return *this;
}
Animal::~Animal()
{
	if(VERBOSE)
	{
		std::cout << BLUE "[Animal] Destructor called" RESET << std::endl;
		std::cout << BLUE << std::setfill('-') << std::setw(40) << "";
		std::cout << RESET << std::endl;
	}		
}

std::string	Animal::getType(void) const
{
	return _type;
}

void		Animal::makeSound(void) const
{
	std::cout << "Animal noise" << std::endl;
}
