/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 13:58:53 by jeada-si          #+#    #+#             */
/*   Updated: 2024/08/09 15:38:29 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

void	Character::setInventoryNull()
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character()
{
	this->setInventoryNull();
	std::cout << BLUE "[Character] Default constructor called" RESET << std::endl;
}

Character::Character(std::string name)
{
	_name = name;
		this->setInventoryNull();
	std::cout << BLUE "[Character] Name constructor called" RESET << std::endl;
}

void	Character::purgeInventory(void)
{
	for (int i = 0; i < 4; i++)
		if (_inventory[i])
			delete _inventory[i];
}

void	Character::copyInventory(const Character &src)
{
	this->purgeInventory();
	for (int i = 0; i < 4; i++)
		_inventory[i] = src._inventory[i]->clone();
}

Character::Character(const Character &src)
{
	this->copyInventory(src);
	_name = src._name;
	std::cout << BLUE "[Character] Copy constructor called" RESET << std::endl;
}

Character& Character::operator=(const Character &src)
{
	this->copyInventory(src);
	_name = src._name;
	std::cout << BLUE "[Character] Assignment operator called" RESET << std::endl;
	return *this;
}

Character::~Character()
{
	this->purgeInventory();
	std::cout << BLUE "[Character] Destructor called" RESET << std::endl;
}

std::string const &	Character::getName() const
{
	return _name;
}

void	Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			return;
		}
	}
	delete m;
	return;
}

void	Character::unequip(int idx)
{
	if (!_inventory[idx])
		return ;
	
}

void	Character::use(int idx, Character& target)
{

}
