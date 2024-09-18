/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:33:43 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/17 14:45:32 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

Serializer::Serializer()
{
	//std::cout << BLUE "[Serializer] Default constructor called" RESET << std::endl;
}

Serializer::Serializer(const Serializer &src)
{
	(void) src;
	//std::cout << BLUE "[Serializer] Copy constructor called" RESET << std::endl;
}

Serializer& Serializer::operator=(const Serializer &src)
{
	(void) src;
	//std::cout << BLUE "[Serializer] Assignment operator called" RESET << std::endl;
	return *this;
}

Serializer::~Serializer()
{
	//std::cout << BLUE "[Serializer] Destructor called" RESET << std::endl;
}

uintptr_t	Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*		Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}
