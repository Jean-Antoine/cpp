/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:59:24 by jeada-si          #+#    #+#             */
/*   Updated: 2024/08/08 14:56:24 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void		ScavTrap::constructorLog(std::string log)
{
	std::cout << BLUE "[SCAVTRAP] " << log << " ";
	std::cout << this->_name << RESET << std::endl;
}

ScavTrap::ScavTrap()
{
	this->_name = "unknown";
	this->_hitPts = 100;
	this->_energyPts = 50;
	this->_attackDamage = 20;
	constructorLog("Default constructor called");
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->_hitPts = 100;
	this->_energyPts = 50;
	this->_attackDamage = 20;
	constructorLog("Name constructor called");
}

ScavTrap::ScavTrap(const ScavTrap &src)
{
	operator=(src);
	constructorLog("Copy constructor called");
}

ScavTrap& ScavTrap::operator=(const ScavTrap &src)
{
	ClapTrap::operator=(src);
	constructorLog("Assignement operator called");
	return (*this);
}

ScavTrap::~ScavTrap()
{
	constructorLog("Destructor called");
}

void		ScavTrap::attack(std::string target)
{
	if (this->isUnable())
		return ;
	std::cout << YELLOW "ScavTrap " << this->_name << " attacks " << target;
	std::cout << ", causing " << this->_attackDamage << " points of damage !";
	std::cout << RESET << std::endl;
	this->_energyPts--;
}

void		ScavTrap::guardGate(void)
{
	if (this->isUnable())
		return ;
	std::cout << YELLOW "ScavTrap " << this->_name << " is guarding the gate.";
	std::cout << RESET << std::endl;
}