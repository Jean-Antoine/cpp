/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:39:25 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/05 15:02:55 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm():
	AForm("RobotomyRequestForm", "target", 72, 45)
{
	//std::cout << BLUE "[RobotomyRequestForm] Default constructor called" RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target):
	AForm("RobotomyRequestForm", target, 72, 45)
{
	//std::cout << BLUE "[RobotomyRequestForm] Default constructor called" RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src):
	AForm(src.getName(), src.getTarget(), 72, 45)
{
	(void) src;
	//std::cout << BLUE "[RobotomyRequestForm] Copy constructor called" RESET << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	(void) src;
	//std::cout << BLUE "[RobotomyRequestForm] Assignment operator called" RESET << std::endl;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	//std::cout << BLUE "[RobotomyRequestForm] Destructor called" RESET << std::endl;
}

void	RobotomyRequestForm::executeSpecific(void) const
{
	int			random;
	static int	seed = 1;
	
	if (seed)
	{
		seed = 0;
		std::srand(std::time(NULL));
	}
	random = std::rand();
	std::cout << YELLOW "*** DRILLING NOISE ***" << std::endl;
	std::cout << this->getTarget();
	if (random < (RAND_MAX / 2))
		std::cout << " has been robotomized successfully !";
	else
		std::cout << "'s robotomy failed...";
	std::cout << std::endl;
}