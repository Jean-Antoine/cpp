/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 14:39:18 by jeada-si          #+#    #+#             */
/*   Updated: 2024/08/20 16:20:50 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include <iostream>

Ice::Ice()
{
	_type = "ice";
	std::cout << BLUE "[Ice] Default constructor called" RESET << std::endl;
}

Ice::Ice(const Ice &src)
{
	_type = "ice";
	(void) &src;
	std::cout << BLUE "[Ice] Copy constructor called" RESET << std::endl;
}

Ice& Ice::operator=(const Ice &src)
{
	(void) &src;
	std::cout << BLUE "[Ice] Assignment operator called" RESET << std::endl;
	return *this;
}

Ice::~Ice()
{
	std::cout << BLUE "[Ice] Destructor called" RESET << std::endl;
}

void	Ice::use(ICharacter& target)
{
	std::cout << GREEN "* shoots an ice bolt at " << target.getName();
	std::cout << " *" RESET << std::endl;
}

AMateria*	Ice::clone() const
{
	AMateria*	out = new Ice(*this);
	
	return out;
}