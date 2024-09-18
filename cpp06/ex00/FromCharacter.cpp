/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FromCharacter.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 08:49:11 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/17 11:12:46 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FromCharacter.hpp"
#include <iostream>

FromCharacter::FromCharacter(): From("0")
{
}

FromCharacter::FromCharacter(std::string s): From(s)
{
}

FromCharacter::FromCharacter(const FromCharacter &src)
{
	(void) src;
}

FromCharacter& FromCharacter::operator=(const FromCharacter &src)
{
	(void) src;
	return *this;
}

FromCharacter::~FromCharacter()
{
}

int FromCharacter::isIt() const
{
	if (_s.size() != 1 || _isCharOverflow)
		return false;
	if (isNum(_s[0]))
		return false;
	return true;
}

int	FromCharacter::print() const
{
	char	c;

	if (!this->isIt())
		return false;
	c = _s[0];
	printChar(c);
	printInt(c);
	printFloat(c);
	printDouble(c);
	return true;
}
