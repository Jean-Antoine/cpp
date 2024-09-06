/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:03:38 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/04 15:16:01 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <iostream>

AForm::AForm():
	_name("unknown"),
	_signed(false),	
	_gradeSign(150),
	_gradeExec(150),
	_target("target")
{
	//std::cout << BLUE "[AForm] Default constructor called" RESET << std::endl;
}

AForm::AForm(std::string name, std::string target, int gradeSign, int gradeExec):
	_name(name),
	_signed(false),
	_gradeSign(gradeSign),
	_gradeExec(gradeExec),
	_target(target)
{
	checkGrade(gradeSign);
	checkGrade(gradeExec);
}

AForm::AForm(const AForm &src):
	_name(src._name),
	_signed(false),
	_gradeSign(src._gradeSign),
	_gradeExec(src._gradeExec),
	_target(src._target)
{
	//std::cout << BLUE "[AForm] Copy constructor called" RESET << std::endl;
}

AForm& AForm::operator=(const AForm &src)
{
	(void) src;
	//std::cout << BLUE "[AForm] Assignment operator called" RESET << std::endl;
	return *this;
}

AForm::~AForm()
{
	//std::cout << BLUE "[AForm] Destructor called" RESET << std::endl;
}

const char*	AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high.");
}

const char*	AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low.");
}

const char*	AForm::FormNotSignedException::what(void) const throw()
{
	return ("This form is not signed.");
}

void	AForm::checkGrade(int grade) const
{
	if (grade > 150)
		throw(GradeTooLowException());
	if (grade < 1)
		throw(GradeTooHighException());
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (_gradeSign < bureaucrat.getGrade())
	{
		throw (GradeTooLowException());
	}
	this->_signed = true;
}

void		AForm::execute(const Bureaucrat &executor) const
{
	if (this->getGradeExec() < executor.getGrade())
		throw(AForm::GradeTooLowException());
	if (!this->isSigned())
		throw(AForm::FormNotSignedException());
	executeSpecific();
}

bool		AForm::isSigned(void) const
{
	return _signed;
}

std::string	AForm::getName(void) const
{
	return _name;
}

std::string	AForm::getTarget(void) const
{
	return _target;
}

int			AForm::getGradeExec(void) const
{
	return _gradeExec;
}

int			AForm::getGradeSign(void) const
{
	return _gradeSign;
}

void		AForm::setSigned(bool value)
{
	this->_signed = value;
}

std::ostream&		operator<<(std::ostream &os, AForm &AForm)
{
	os << YELLOW "Form " << AForm.getName() << " is ";
	if (!AForm.isSigned())
		os << "not ";
	os << "signed. ";
	os << "It needs a grade " << AForm.getGradeSign() << " to be signed ";
	os << "and a grade " << AForm.getGradeExec() << " to be executed.";
	os << RESET << std::endl;
	return os;
}
