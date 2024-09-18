/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FromDouble.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:55:41 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/17 13:58:38 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FromDouble.hpp"
#include <iostream>

FromDouble::FromDouble(): From("0")
{
}

FromDouble::FromDouble(std::string s): From(s)
{
}

FromDouble::FromDouble(const FromDouble &src)
{
	(void) src;
}

FromDouble& FromDouble::operator=(const FromDouble &src)
{
	(void) src;
	return *this;
}

FromDouble::~FromDouble()
{
}

int		FromDouble::isIt() const
{
	unsigned int	i;

	i = 0;
	if (isNan() || isInf())
		return true;
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
	if (!_s[i])
		return true;
	if (_s[i] != '.')
		return false;
	if (!_s[i + 1])
		return true;
	i++;
	while (_s[i])
	{
		if (!isNum(_s[i]))
			break;
		i++;
	}	
	if (_s[i])
		return false;
	return true;
}

int		FromDouble::print() const
{

	if (!isIt())
		return false;
	printChar(static_cast<char>(_d));
	printInt(static_cast<int>(_d));
	printFloat(static_cast<float>(_d));
	printDouble(_d);
	return true;
}