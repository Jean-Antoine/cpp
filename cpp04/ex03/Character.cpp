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
	this->_name = "unknown";
	this->setInventoryNull();
	this->_trash_idx = 0;
	if(VERBOSE)
		std::cout << BLUE "[Character] Default constructor called" RESET << std::endl;
}

Character::Character(std::string name)
{
	this->_name = name;
	this->_trash_idx = 0;
	this->setInventoryNull();
	if(VERBOSE)
		std::cout << BLUE "[Character] Name constructor called" RESET << std::endl;
}

void	Character::purgeInventory(void)
{
	for (int i = 0; i < 4; i++)
		if (_inventory[i])
			delete _inventory[i];
	setInventoryNull();
}

void	Character::copyInventory(const Character &src)
{
	setInventoryNull();
	for (int i = 0; i < 4; i++)
	{
		if (src._inventory[i])
			_inventory[i] = src._inventory[i]->clone();
	}		
}

Character::Character(const Character &src)
{
	this->copyInventory(src);
	_name = src._name;
	_trash_idx = 0;
	if(VERBOSE)
		std::cout << BLUE "[Character] Copy constructor called" RESET << std::endl;
}

Character& Character::operator=(const Character &src)
{
	this->purgeInventory();
	this->copyInventory(src);
	_name = src._name;
	if(VERBOSE)
		std::cout << BLUE "[Character] Assignment operator called" RESET << std::endl;
	return *this;
}

Character::~Character()
{
	if(VERBOSE)
		std::cout << BLUE "[Character] Destructor called" RESET << std::endl;
	this->purgeInventory();
	if (!_trash_idx)
		return ;
	for (int i = 0; i < _trash_idx; i++)
		delete _trash[i];
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
			std::cout << YELLOW "Materia of type " << m->getType();
			std::cout << " equipped in slot " << i <<  "." << std::endl;
			std::cout << RESET;
			return;
		}
	};
	delete m;
	std::cout << RED "Inventory is full." RESET << std::endl;
}

void	Character::unequip(int idx)
{
	if (!_inventory[idx])
	{
		std::cout << YELLOW "/!\\ Slot " << idx << " is already empty";
		std::cout << RESET << std::endl;
		return ;
	}
	std::cout << YELLOW "Dropping materia of type " << _inventory[idx]->getType();
	std::cout << " from slot " << idx << "." << std::endl;
	std::cout << RESET;
	_trash[_trash_idx++] = _inventory[idx];
	_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (!_inventory[idx])
	{
		std::cout << YELLOW "/!\\ Slot " << idx << " is empty";
		std::cout << RESET << std::endl;
		return ;
	}
	_inventory[idx]->use(target);
	delete _inventory[idx];
	_inventory[idx] = NULL;
}
