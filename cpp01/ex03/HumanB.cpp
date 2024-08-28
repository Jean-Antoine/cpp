/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:56:10 by jeada-si          #+#    #+#             */
/*   Updated: 2024/08/21 10:44:30 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;
}

HumanB::~HumanB()
{
	
}

void HumanB::setWeapon(Weapon &w)
{
	this->weapon = &w;
}

void	HumanB::attack() const
{
	std::cout << this->name;
	std::cout << " attacks with their ";
	std::cout << this->weapon->getType() << std::endl;
};
