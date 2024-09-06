/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:20:16 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/03 15:41:29 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat()
{
	_type = "Cat";
	if (VERBOSE)
		std::cout << BLUE "[Cat   ] Default constructor called" RESET << std::endl;
}

Cat::Cat(const Cat &src)
{
	_type = src._type;
	if (VERBOSE)
		std::cout << BLUE "[Cat   ] Copy constructor called" RESET << std::endl;
}


Cat& Cat::operator=(const Cat &src)
{
	_type = src._type;
	if (VERBOSE)
		std::cout << BLUE "[Cat   ] Assignment operator called" RESET << std::endl;
	return *this;
}

Cat::~Cat()
{
	if (VERBOSE)
		std::cout << BLUE "[Cat   ] Destructor called" RESET << std::endl;
}

void		Cat::makeSound(void) const
{
	std::cout << "Meow !" << std::endl;
}
