/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:39:25 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/05 14:55:45 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm():
	AForm("PresidentialPardonForm", "target", 25, 5)
{
	//std::cout << BLUE "[PresidentialPardonForm] Default constructor called" RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target):
	AForm("PresidentialPardonForm", target, 25, 5)
{
	//std::cout << BLUE "[PresidentialPardonForm] Default constructor called" RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src):
	AForm(src.getName(), src.getTarget(), 25, 5)
{
	(void) src;
	//std::cout << BLUE "[PresidentialPardonForm] Copy constructor called" RESET << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	(void) src;
	//std::cout << BLUE "[PresidentialPardonForm] Assignment operator called" RESET << std::endl;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	//std::cout << BLUE "[PresidentialPardonForm] Destructor called" RESET << std::endl;
}

void	PresidentialPardonForm::executeSpecific(void) const
{
	std::cout << YELLOW << this->getTarget();
	std::cout << " has been pardoned by Zaphod Beeblebrox.";
	std::cout << std::endl;
}