/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:20:43 by jeada-si          #+#    #+#             */
/*   Updated: 2024/07/31 16:54:12 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->type = type;
}

Weapon::Weapon()
{
	std::cout << "Weapon created" << std::endl;
};

Weapon::~Weapon()
{
	std::cout << "Weapon " << this->type << " destructed" << std::endl;
};

std::string	const	&Weapon::getType(void) const
{
	std::string const	&ref = this->type;
	return (ref);
};

void	Weapon::setType(std::string newType)
{
	this->type = newType;
};
