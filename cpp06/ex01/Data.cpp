/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:22:16 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/17 14:33:03 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include <iostream>

Data::Data():
	_name("Unknown"),
	_age(30),
	_height(1.80)
{
	//std::cout << BLUE "[Data] Default constructor called" RESET << std::endl;
}

Data::Data(std::string name, unsigned int age, float height):
	_name(name),
	_age(age),
	_height(height)
{
	//std::cout << BLUE "[Data] Default constructor called" RESET << std::endl;
}

Data::Data(const Data &src)
{
	(void) src;
	//std::cout << BLUE "[Data] Copy constructor called" RESET << std::endl;
}

Data& Data::operator=(const Data &src)
{
	(void) src;
	//std::cout << BLUE "[Data] Assignment operator called" RESET << std::endl;
	return *this;
}

Data::~Data()
{
	//std::cout << BLUE "[Data] Destructor called" RESET << std::endl;
}

std::string		Data::getName() const
{
	return _name;
}

unsigned int	Data::getAge() const
{
	return _age;
}

float			Data::getHeight() const
{
	return _height;
}

std::ostream&	operator<<(std::ostream& os, Data& data)
{
	os << data.getName() << " is " << data.getAge();
	os << "yo and " << std::fixed << std::setprecision(2);
	os << data.getHeight() << "m tall." << std::endl;
	return os;
}