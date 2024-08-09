/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:43:40 by jeada-si          #+#    #+#             */
/*   Updated: 2024/08/08 11:13:21 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void ClapTrap::constructorLog(std::string log)
{
	std::cout << BLUE << log << " " << _name << RESET << std::endl;
}

ClapTrap::ClapTrap():
	_name("unknown"),
	_energyPts(10),
	_hitPts(10),
	_attackDamage(0)
{
	constructorLog("Default constructor called:");
}

ClapTrap::ClapTrap(std::string name):
	_name(name),
	_energyPts(10),
	_hitPts(10),
	_attackDamage(0)
{
	constructorLog("Name constructor called:");
}

ClapTrap::ClapTrap(const ClapTrap &src):
	_name(src._name),
	_energyPts(src._energyPts),
	_hitPts(src._hitPts),
	_attackDamage(src._attackDamage)
{
	constructorLog("Copy constructor called:");
}

ClapTrap& ClapTrap::operator=(const ClapTrap &src)
{
	this->_name = src._name;
	this->_energyPts = src._energyPts;
	this->_hitPts = src._hitPts;
	this->_attackDamage = src._attackDamage;
	constructorLog("Assignement operator called:");
	return (*this);
}

ClapTrap::~ClapTrap()
{
	constructorLog("Destructor called:");
}

void	ClapTrap::displayEnergyPts(std::string log)
{
	std::cout << RED "ClapTrap " << _name << log << " but has " << _energyPts;
	std::cout << " energy points left !" RESET << std::endl;
}

bool	ClapTrap::isDead(void)
{
	if (_hitPts)
		return (0);
	std::cout << RED << _name << " is dead." << std::endl;
	return (1);
}

bool	ClapTrap::isUnable(void)
{
	if (this->isDead())
		return (1);
	if (_energyPts)
		return (0);
	std::cout << PINK << _name << " has no energy points left !";
	std::cout << RESET << std::endl;
	return (1);
}

void	ClapTrap::attack(const std::string& target)
{
	if (isUnable())
		return ;
	std::cout << YELLOW "ClapTrap " << _name << " attacks " << target;
	std::cout << ", causing " << _attackDamage << " points of damage !";
	std::cout << RESET << std::endl;
	_energyPts--;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (isUnable())
		return ;
	std::cout << GREEN "ClapTrap " << _name << " got repaired,";
	std::cout << " gaining " << amount << " hit points !" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	int	lost;
	
	if (isDead())
		return ;
	lost = _hitPts > amount ? amount : _hitPts;	
	std::cout << RED "Claptrap " << _name << " lost " << lost;
	std::cout << " hit points !" << RESET << std::endl;
	_hitPts = _hitPts - lost;
}

