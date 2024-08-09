/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:16:32 by jeada-si          #+#    #+#             */
/*   Updated: 2024/08/08 16:58:34 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal()
{
	_type = "WrongAnimal";
	std::cout << BLUE "[WrongAnimal] Default constructor called" RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	_type = src._type;
	std::cout << BLUE "[WrongAnimal] Copy constructor called" RESET << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &src)
{
	_type = src._type;
	std::cout << BLUE "[WrongAnimal] Assignment operator called" RESET << std::endl;
	return *this;
}
WrongAnimal::~WrongAnimal()
{
	std::cout << BLUE "[WrongAnimal] Destructor called" RESET << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return _type;
}

void		WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal noise" << std::endl;
}