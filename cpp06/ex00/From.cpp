/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   From.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 08:46:31 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/17 11:13:07 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "From.hpp"
#include <iostream>
#include <cstdlib>
#include <limits>

From::From(): _s("0")
{
}

From::From(std::string s): _s(s)
{
	if (!s.compare("nanf"))
		_s = "nan";
	if (!s.compare("-inff"))
		_s = "-inf";
	if (!s.compare("+inff"))
		_s = "+inf";	
	_d = std::strtod(_s.data(), NULL);
	_isIntOverflow = false;
	_isCharOverflow = false;
	_isFloatOverflow = false;
	if (_d > std::numeric_limits<char>::max() || _d < std::numeric_limits<char>::min())
		_isCharOverflow = true;
	if (_d > std::numeric_limits<int>::max() || _d < std::numeric_limits<int>::min())
		_isIntOverflow  = true;
	if (_d > std::numeric_limits<float>::max() || _d < -std::numeric_limits<float>::max())
		_isFloatOverflow  = true;
}

From::From(const From &src)
{
	(void) src;
}

From& From::operator=(const From &src)
{
	(void) src;
	return *this;
}

From::~From()
{
}

int		From::isDisplayable(char c) const
{
	if (c > 32 && c < 127)
		return true;
	return false;
}

int		From::isNan() const
{
	return !_s.compare("nan");
}

int		From::isInf() const
{
	return !_s.compare("-inf") || !_s.compare("+inf");
}

void	From::printChar(char c) const
{
	std::cout << "char: \t\t";
	if (isNan() || isInf() || _isCharOverflow)
	{
		std::cout << RED "Impossible" RESET << std::endl;
		return ;
	}
	if (!isDisplayable(c))
	{
		std::cout << BLUE "Non displayable" RESET << std::endl;
		return ;
	}
	std::cout << c << std::endl;
}

void	From::printInt(int i) const
{
	std::cout << "int: \t\t";
	if (isNan() || isInf() || _isIntOverflow)
	{
		std::cout << RED "Impossible" RESET << std::endl;
		return;
	}
	std::cout << i << std::endl;
}

void	From::printFloat(float f) const
{
	std::cout << "float: \t\t";	
	if (isNan() || isInf())
		std::cout << _s;
	else if (_isFloatOverflow)
	{
		if (_d > 0)
			std::cout << "+inf";
		else
			std::cout << "-inf";
	}		
	else
		std::cout << std::fixed << std::setprecision(1) << f;
	std::cout << "f" << std::endl;
}

void	From::printDouble(double d) const
{
	std::cout << "double: \t";
	if (isNan() || isInf())
		std::cout << _s << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << d << std::endl;
}

int		isNum(char c)
{
	if (c < 0 + '0' || c > '0' + 9)
		return false;
	return true;
}