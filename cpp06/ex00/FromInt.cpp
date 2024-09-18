/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FromInt.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 10:15:11 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/17 11:12:53 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FromInt.hpp"
#include <iostream>

FromInt::FromInt():From("0")
{
}

FromInt::FromInt(std::string s):From(s)
{
}

FromInt::FromInt(const FromInt &src)
{
	(void) src;
}

FromInt& FromInt::operator=(const FromInt &src)
{
	(void) src;
	return *this;
}

FromInt::~FromInt()
{
}

int		FromInt::isIt() const
{
	unsigned int		i;

	if (_isIntOverflow)
		return false;
	i = 0;
	while (isspace(_s[i]))
		i++;
	if (_s[i] == '-' || _s[i] == '+')
		i++;
	while (i < _s.size())
	{
		if (!isNum(_s[i]))
			return false;
		i++;
	}
	return true;
}

int		FromInt::print() const
{
	if (!isIt())
		return false;
	printChar(static_cast<char>(_d));
	printInt(static_cast<int>(_d));
	printFloat(static_cast<float>(_d));
	printDouble(_d);
	return true;
}