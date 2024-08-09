/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:59:24 by jeada-si          #+#    #+#             */
/*   Updated: 2024/08/08 14:56:30 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

void		FragTrap::constructorLog(std::string log)
{
	std::cout << BLUE "[FRAGTRAP] " << log << " ";
	std::cout << this->_name << RESET << std::endl;
}

FragTrap::FragTrap()
{
	this->_name = "unknown";
	this->_hitPts = 100;
	this->_energyPts = 100;
	this->_attackDamage = 30;
	constructorLog("Default constructor called");
}

FragTrap::FragTrap(std::string name)
{
	this->_name = name;
	this->_hitPts = 100;
	this->_energyPts = 100;
	this->_attackDamage = 30;
	constructorLog("Name constructor called");
}

FragTrap::FragTrap(const FragTrap &src)
{
	operator=(src);
	constructorLog("Copy constructor called");
}

FragTrap& FragTrap::operator=(const FragTrap &src)
{
	ClapTrap::operator=(src);
	constructorLog("Assignement operator called");
	return (*this);
}

FragTrap::~FragTrap()
{
	constructorLog("Destructor called");
}

void		FragTrap::highFiveGuys(void)
{
	if (this->isUnable())
		return ;
	std::cout << YELLOW "FragTrap " << this->_name << " gives you a high five !";
	std::cout << RESET << std::endl;
}