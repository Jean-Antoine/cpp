/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:43:40 by jeada-si          #+#    #+#             */
/*   Updated: 2024/08/28 11:58:24 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <string>
#include <iomanip>

void ClapTrap::constructorLog(std::string log)
{
	std::cout << BLUE "[CLAPTRAP] " << log << " " << _name << RESET << std::endl;
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

void	ClapTrap::displayEnergyPts(std::string prefix)
{
	std::cout << RED "ClapTrap " << _name << prefix << "It has " << _energyPts;
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
	_hitPts += amount;
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

void			formatStat(std::string label, unsigned int value)
{
	std::cout << "|" << label << ": " << BLUE;
	std::cout << std::setfill(' ') << std::setw(2)<< value << RESET;
}

void			ClapTrap::displayStats(void)
{
	std::cout << "Name: " << BLUE;
	if (_name.size() > 10)
		std::cout << _name.substr(0, 9) << ".";
	else
		std::cout << std::setfill(' ') << std::setw(10) << _name;
	std::cout << RESET;
	formatStat("Hit points", _hitPts);
	formatStat("Energy points", _energyPts);
	formatStat("Attack damage", _attackDamage);
	std::cout << std::endl;	
}