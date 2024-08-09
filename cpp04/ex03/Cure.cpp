/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 14:40:00 by jeada-si          #+#    #+#             */
/*   Updated: 2024/08/09 15:44:04 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <iostream>

Cure::Cure()
{
	_type = "cure";
	std::cout << BLUE "[Cure] Default constructor called" RESET << std::endl;
}

Cure::Cure(const Cure &src)
{
	(void) src;
	_type = "cure";
	std::cout << BLUE "[Cure] Copy constructor called" RESET << std::endl;
}

Cure& Cure::operator=(const Cure &src)
{
	(void) &src;
	_type = "cure";
	std::cout << BLUE "[Cure] Assignment operator called" RESET << std::endl;
	return *this;
}

Cure::~Cure()
{
	std::cout << BLUE "[Cure] Destructor called" RESET << std::endl;
}

void	Cure::use(Character& target)
{
	std::cout << "*heals " << target.getName() << "'s wound";
	std::cout << std::endl;
}

AMateria*	Cure::clone() const
{
	AMateria*	out = new Cure(*this);
	
	return out;
}