/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 12:52:32 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/05 14:21:31 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <iostream>

Intern::Intern()
{
	//std::cout << BLUE "[Intern] Default constructor called" RESET << std::endl;
}

Intern::Intern(const Intern &src)
{
	(void) src;
	//std::cout << BLUE "[Intern] Copy constructor called" RESET << std::endl;
}

Intern& Intern::operator=(const Intern &src)
{
	(void) src;
	//std::cout << BLUE "[Intern] Assignment operator called" RESET << std::endl;
	return *this;
}

Intern::~Intern()
{
	//std::cout << BLUE "[Intern] Destructor called" RESET << std::endl;
}

const char*	Intern::FormDoesNotExistsException::what(void) const throw()
{
	return "This type of form does not exists.";
}

AForm*	Intern::makePresidentialPardonForm(std::string target)
{
	AForm*	form = new PresidentialPardonForm(target);
	return (form);
}

AForm*	Intern::makeRobotomyRequestForm(std::string target)
{
	AForm*	form = new RobotomyRequestForm(target);
	return (form);
}

AForm*	Intern::makeShrubberyCreationForm(std::string target)
{
	AForm*	form = new ShrubberyCreationForm(target);
	return (form);
}

AForm*	Intern::makeForm(std::string formName, std::string target)
{
	const std::string	types[3] = {
		"robotomy request",
		"presidential pardon",
		"shrubbery creation"
	};
	AForm*		(Intern::*func[])(std::string) = 
	{
		&Intern::makeRobotomyRequestForm,
		&Intern::makePresidentialPardonForm,
		&Intern::makeShrubberyCreationForm
	};
	
	for (int i = 0; i < 3; i++)
	{
		if (!types[i].compare(formName))
		{
			std::cout << BLUE "Intern creates " << types[i];
			std::cout << "." RESET << std::endl;
			return ((this->*func[i])(target));
		}			
	}
	throw(FormDoesNotExistsException());
}
