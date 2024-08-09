/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:47:42 by jeada-si          #+#    #+#             */
/*   Updated: 2024/08/09 15:48:05 by jeada-si         ###   ########.fr       */
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
}


ICharacter::~ICharacter()
{
	std::cout << BLUE "[ICharacter] Destructor called" RESET << std::endl;
}

