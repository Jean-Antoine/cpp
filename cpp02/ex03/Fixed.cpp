/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:52:28 by jeada-si          #+#    #+#             */
/*   Updated: 2024/08/06 13:55:33 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed(): _rawBits(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i)
{
	// std::cout << "int constructor called" << std::endl;
	this->_rawBits = i << 8;
}

Fixed::Fixed(const float f)
{
	// std::cout << "Float constructor called" << std::endl;
	this->_rawBits = (int) roundf(f * (1 << this->_fracBits));
}

Fixed::Fixed(const Fixed &src)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed& Fixed::operator=(const Fixed &src)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		_rawBits = src.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (_rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
};

int		Fixed::toInt(void) const
{
	return _rawBits >> 8;
}

float	Fixed::toFloat(void) const
{
	return (((float) _rawBits) / (1 << _fracBits));
}

std::ostream& operator<<(std::ostream &out, const Fixed &obj)
{
	out << obj.toFloat();
	return out;
}

bool	Fixed::operator>(Fixed const &obj) const
{
	return (getRawBits() > obj.getRawBits());
}

bool	Fixed::operator<(Fixed const &obj) const
{
	return (getRawBits() < obj.getRawBits());
}

bool	Fixed::operator>=(Fixed const &obj) const
{
	return (getRawBits() >= obj.getRawBits());
}

bool	Fixed::operator<=(Fixed const &obj) const
{
	return (getRawBits() <= obj.getRawBits());
}

bool	Fixed::operator==(Fixed const &obj) const
{
	return (getRawBits() == obj.getRawBits());
}

bool	Fixed::operator!=(Fixed const &obj) const
{
	return (getRawBits() != obj.getRawBits());
}

Fixed Fixed::operator+(Fixed const &obj) const
{
	Fixed	out;

	out.setRawBits(this->getRawBits() + obj.getRawBits());
	return out;
}

Fixed Fixed::operator-(Fixed const &obj) const
{
	Fixed	out;

	out.setRawBits(this->getRawBits() - obj.getRawBits());
	return out;
}

Fixed Fixed::operator*(Fixed const &obj) const
{
	Fixed	out;

	out.setRawBits((this->getRawBits() * obj.getRawBits()) >> this->_fracBits);
	return out;
}

Fixed Fixed::operator/(Fixed const &obj) const
{
	Fixed	out;

	out.setRawBits((this->getRawBits() / obj.getRawBits()) << this->_fracBits);
	return out;
}

Fixed&	Fixed::operator++()
{
	this->_rawBits++;
	return (*this);
}

Fixed&	Fixed::operator--()
{
	this->_rawBits--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed temp = *this;
	++(*this);
	return (temp);
}

Fixed	Fixed::operator--(int)
{
	Fixed temp = *this;
	--(*this);
	return (temp);
}

Fixed&	Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed&	Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

Fixed const&	Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed const&	Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a > b)
		return (a);
	return (b);
}
