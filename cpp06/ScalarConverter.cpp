/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:26:40 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/06 10:54:37 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

ScalarConverter::ScalarConverter()
{
	//std::cout << BLUE "[ScalarConverter] Default constructor called" RESET << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	//std::cout << BLUE "[ScalarConverter] Copy constructor called" RESET << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &src)
{
	//std::cout << BLUE "[ScalarConverter] Assignment operator called" RESET << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	//std::cout << BLUE "[ScalarConverter] Destructor called" RESET << std::endl;
}

bool	ScalarConverter::isCharacter(std::string s)
{
	if (s.size() == 1)
		return true;
	if (s.size() == 3 && s[0] == '\'' && s[2] == '\'')
		return true;
}

void	ScalarConverter::convert(std::string s)
{
	
}