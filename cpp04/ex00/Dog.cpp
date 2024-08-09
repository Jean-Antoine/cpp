/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:23:03 by jeada-si          #+#    #+#             */
/*   Updated: 2024/08/08 17:02:32 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
	_type = "Dog";
	std::cout << BLUE "[Dog] Default constructor called" RESET << std::endl;
}


Dog::Dog(const Dog &src)
{
	_type = src._type;
	std::cout << BLUE "[Dog] Copy constructor called" RESET << std::endl;
}


Dog& Dog::operator=(const Dog &src)
{
	_type = src._type;
	std::cout << BLUE "[Dog] Assignment operator called" RESET << std::endl;
	return *this;
}


Dog::~Dog()
{
	std::cout << BLUE "[Dog] Destructor called" RESET << std::endl;
}

void		Dog::makeSound(void) const
{
	std::cout << "Woof !" << std::endl;
}
