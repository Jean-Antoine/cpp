/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:00:43 by jeada-si          #+#    #+#             */
/*   Updated: 2024/08/20 15:39:52 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include <iostream>

ICharacter::ICharacter()
{
	std::cout << BLUE "[ICharacter] Default constructor called" RESET << std::endl;
}

ICharacter::ICharacter(const ICharacter &src)
{
	(void) src;
	std::cout << BLUE "[ICharacter] Copy constructor called" RESET << std::endl;
}

ICharacter& ICharacter::operator=(const ICharacter &src)
{
	(void) src;
	std::cout << BLUE "[ICharacter] Assignment operator called" RESET << std::endl;
	return (*this);
}

ICharacter::~ICharacter()
{
	std::cout << BLUE "[ICharacter] Destructor called" RESET << std::endl;
}
