/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:20:16 by jeada-si          #+#    #+#             */
/*   Updated: 2024/08/08 17:02:29 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat()
{
	_type = "WrongCat";
	if(VERBOSE)
		std::cout << BLUE "[WrongCat] Default constructor called" RESET << std::endl;
}


WrongCat::WrongCat(const WrongCat &src)
{
	_type = src._type;
	if(VERBOSE)
		std::cout << BLUE "[WrongCat] Copy constructor called" RESET << std::endl;
}


WrongCat& WrongCat::operator=(const WrongCat &src)
{
	_type = src._type;
	if(VERBOSE)
		std::cout << BLUE "[WrongCat] Assignment operator called" RESET << std::endl;
	return *this;
}

WrongCat::~WrongCat()
{
	if(VERBOSE)
		std::cout << BLUE "[WrongCat] Destructor called" RESET << std::endl;
}

void		WrongCat::makeSound(void) const
{
	std::cout << "Wrong Meow !" << std::endl;
}
