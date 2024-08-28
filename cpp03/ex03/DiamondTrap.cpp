/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:47:52 by jeada-si          #+#    #+#             */
/*   Updated: 2024/08/28 13:14:46 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

void	DiamondTrap::constructorLog(std::string log)
{
	std::cout << BLUE "[DIAMONDTRAP] " << log << " " << _name << RESET << std::endl;
}

DiamondTrap::DiamondTrap()
{
	this->_name = "unknown";
	ClapTrap::_name = this->_name + "_clap_name";
	this->_hitPts = FragTrap::_hitPts;
	this->_energyPts = ScavTrap::_energyPts;
	this->_attackDamage = FragTrap::_attackDamage;
	constructorLog("Default constructor called");
}

DiamondTrap::DiamondTrap(std::string name)
{
	this->_name = name;
	ClapTrap::_name = this->_name + "_clap_name";
	this->_hitPts = FragTrap::_hitPts;
	this->_energyPts = ScavTrap::_energyPts;
	this->_attackDamage = FragTrap::_attackDamage;
	constructorLog("Name constructor called");
}

DiamondTrap::DiamondTrap(const DiamondTrap &src)
{
	operator=(src);
	constructorLog("Copy constructor called");
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &src)
{
	this->_name = src._name;
	this->_hitPts = src._hitPts;
	this->_energyPts = src._energyPts;
	this->_attackDamage = src._attackDamage;
	this->ClapTrap::_name = src.ClapTrap::_name;
	constructorLog("Assignement operator called");
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	constructorLog("Destuctor called:");
}

void	DiamondTrap::displayStats()
{
	std::cout << RESET "Name: " << BLUE << this->_name;
	std::cout << RESET "|ClapTrap ";
	ClapTrap::displayStats();
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << RESET "Clap name: " << BLUE << ClapTrap::_name;
	std::cout << RESET "| Name: " << BLUE << this->_name;
	std::cout << RESET << std::cout;
}
