/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:52:28 by jeada-si          #+#    #+#             */
/*   Updated: 2024/08/22 12:42:01 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _rawBits(0)
{
	std::cout << BLUE "Default constructor called" RESET << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << BLUE "Copy constructor called" RESET << std::endl;
	*this = src;
}

Fixed& Fixed::operator=(const Fixed &src)
{
	std::cout << BLUE "Assignment operator called" RESET << std::endl;
	if (this != &src)
		_rawBits = src.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << BLUE "Destructor called" RESET << std::endl;
}

int		Fixed::getRawBits(void) const
{
	std::cout << BLUE "getRawBits called" RESET << std::endl;
	return (_rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
};