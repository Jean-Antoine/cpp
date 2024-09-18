/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FromFloat.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:13:35 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/17 11:13:36 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FromFloat.hpp"
#include <iostream>

FromFloat::FromFloat()
{
}

FromFloat::FromFloat(std::string s):From(s)
{
}

FromFloat::FromFloat(const FromFloat &src)
{
	(void) src;
}

FromFloat& FromFloat::operator=(const FromFloat &src)
{
	(void) src;
	return *this;
}

FromFloat::~FromFloat()
{
}

int		FromFloat::isIt() const
{
	unsigned int	i;

	i = 0;
	if (isNan() || isInf())
		return true;
	if (_isFloatOverflow)
		return false;
	while (isspace(_s[i]))
		i++;
	if (_s[i] == '+' || _s[i] == '-')
		i++;
	while (_s[i])
	{
		if (!isNum(_s[i]))
			break;
		i++;
	}
	if (_s[i] != '.' && _s[i] != 'f')
		return false;
	if (_s[i] == 'f' && !_s[i + 1])
		return true;
	i++;
	while (_s[i])
	{
		if (!isNum(_s[i]))
			break;
		i++;
	}	
	if (_s[i] != 'f')
		return false;
	if (_s[i + 1])
		return false;
	return true;
}

int		FromFloat::print() const
{

	if (!isIt())
		return false;
	printChar(static_cast<char>(_d));
	printInt(static_cast<int>(_d));
	printFloat(static_cast<float>(_d));
	printDouble(_d);
	return true;
}