/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 13:56:31 by jeada-si          #+#    #+#             */
/*   Updated: 2024/08/20 15:39:52 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria()
{
	std::cout << BLUE "[AMateria] Default constructor called" RESET << std::endl;
}

AMateria::AMateria(std::string const &type)
{
	_type = type;
};

AMateria::AMateria(const AMateria &src)
{
	_type = src._type;
	std::cout << BLUE "[AMateria] Copy constructor called" RESET << std::endl;
}

AMateria& AMateria::operator=(const AMateria &src)
{
	(void) &src;
	std::cout << BLUE "[AMateria] Assignment operator called" RESET << std::endl;
	return *this;
}

AMateria::~AMateria()
{
	std::cout << BLUE "[AMateria] Destructor called" RESET << std::endl;
}

void		AMateria::use(ICharacter& target)
{
	(void) target;
}

std::string const&	AMateria::getType() const
{
	return (_type);
}

