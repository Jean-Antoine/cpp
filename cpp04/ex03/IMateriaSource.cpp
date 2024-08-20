/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:58:46 by jeada-si          #+#    #+#             */
/*   Updated: 2024/08/20 15:39:52 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include <iostream>

IMateriaSource::IMateriaSource()
{
	std::cout << BLUE "[IMateriaSource] Default constructor called" RESET << std::endl;
}

IMateriaSource::IMateriaSource(const IMateriaSource &src)
{
	(void) src;
	std::cout << BLUE "[IMateriaSource] Copy constructor called" RESET << std::endl;
}

IMateriaSource& IMateriaSource::operator=(const IMateriaSource &src)
{
	(void) src;
	std::cout << BLUE "[IMateriaSource] Assignment operator called" RESET << std::endl;
	return *this;
}

IMateriaSource::~IMateriaSource()
{
	std::cout << BLUE "[IMateriaSource] Destructor called" RESET << std::endl;
}
