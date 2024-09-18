/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:26:40 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/18 09:50:00 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	(void) src;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &src)
{
	(void) src;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
}

void	ScalarConverter::convert(std::string s)
{	
	if (!s.size())
	{
		std::cout << RED "String is empty." RESET << std::endl;
		return ;
	}
	FromCharacter	Character(s);
	if (Character.print())
		return ;	
	FromInt			Int(s);
	if (Int.print())
		return ;
	FromFloat		Float(s);
	if (Float.print())
		return ;
	FromDouble		Double(s);
	if (Double.print())
		return ;
	std::cout << RED "Could not convert input." RESET << std::endl;
}