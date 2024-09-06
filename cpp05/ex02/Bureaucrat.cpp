/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 10:04:00 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/05 11:22:42 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat():_name("Unknown"), _grade(150)
{
	//std::cout << BLUE "[Bureaucrat] Default constructor called" RESET << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade):
	_name(name)
{
	this->setGrade(grade);
	//std::cout << BLUE "[Bureaucrat] Parameters constructor called" RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src):
	_name(src.getName()),
	_grade(src.getGrade())
{
	//std::cout << BLUE "[Bureaucrat] Copy constructor called" RESET << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &src)
{
	this->_grade = src.getGrade();
	//std::cout << BLUE "[Bureaucrat] Assignment operator called" RESET << std::endl;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	// std::cout << BLUE "[Bureaucrat] Destructor called" RESET << std::endl;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high !");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low !");
}

std::string	Bureaucrat::getName(void) const
{
	return _name;
}

int			Bureaucrat::getGrade(void) const
{
	return _grade;
}

void		Bureaucrat::setGrade(int grade)
{
	if (grade > 150)
		throw(GradeTooLowException());
	if (grade < 1)
		throw(GradeTooHighException());
	this->_grade = grade;
}

void		Bureaucrat::incrGrade(void)
{
	this->setGrade(_grade - 1);
}

void		Bureaucrat::decrGrade(void)
{
	this->setGrade(_grade + 1);
}

std::ostream&	operator<<(std::ostream& os, Bureaucrat& i)
{
	os << YELLOW << i.getName() << ", bureaucrat grade " << i.getGrade();
	os << "." RESET << std::endl;
	return os;	
}

int			Bureaucrat::signForm(AForm &form) const
{
	try
	{
		form.beSigned(*this);
	}
	catch(const std::exception& e)
	{
		std::cout << RED << _name << " couldn't sign ";
		std::cout << form.getName() << " because: ";
		std::cout << e.what() << "\n" RESET;
		return false;
	}
	std::cout << GREEN << _name << " signed ";
	std::cout << form.getName() << "." RESET << std::endl;
	return true;
}

int			Bureaucrat::executeForm(AForm &form) const
{
	try
	{
		form.execute(*this);
	}
	catch(const std::exception& e)
	{
		std::cout << RED << _name << " couldn't execute ";
		std::cout << form.getName() << " because: ";
		std::cout << e.what() << "\n" RESET;
		return false;
	}
	std::cout << GREEN << _name << " executed ";
	std::cout << form.getName() << "." RESET << std::endl;
	return true;
}