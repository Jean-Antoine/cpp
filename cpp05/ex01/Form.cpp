/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:03:38 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/05 14:42:10 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>

Form::Form():
	_name("unknown"),
	_signed(false),	
	_gradeSign(150),
	_gradeExec(150)
{
	//std::cout << BLUE "[Form] Default constructor called" RESET << std::endl;
}

Form::Form(std::string name, int gradeSign, int gradeExec):
	_name(name),
	_signed(false),
	_gradeSign(gradeSign),
	_gradeExec(gradeExec)	
{
	checkGrade(gradeSign);
	checkGrade(gradeExec);
}

Form::Form(const Form &src):
	_name(src._name),
	_signed(false),
	_gradeSign(src._gradeSign),
	_gradeExec(src._gradeExec)
{
	//std::cout << BLUE "[Form] Copy constructor called" RESET << std::endl;
}

Form& Form::operator=(const Form &src)
{
	(void) src;
	//std::cout << BLUE "[Form] Assignment operator called" RESET << std::endl;
	return *this;
}

Form::~Form()
{
	//std::cout << BLUE "[Form] Destructor called" RESET << std::endl;
}

const char*	Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high.");
}

const char*	Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low.");
}

void	Form::checkGrade(int grade) const
{
	if (grade > 150)
		throw(GradeTooLowException());
	if (grade < 1)
		throw(GradeTooHighException());
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (_gradeSign < bureaucrat.getGrade())
	{
		throw (GradeTooLowException());
	}
	this->_signed = true;
}

bool		Form::isSigned(void) const
{
	return _signed;
}

std::string	Form::getName(void) const
{
	return _name;
}

int			Form::getGradeExec(void) const
{
	return _gradeExec;
}

int			Form::getGradeSign(void) const
{
	return _gradeSign;
}

std::ostream&		operator<<(std::ostream &os, Form &form)
{
	os << YELLOW "Form " << form.getName() << " is ";
	if (!form.isSigned())
		os << "not ";
	os << "signed. ";
	os << "It needs a grade " << form.getGradeSign() << " to be signed ";
	os << "and a grade " << form.getGradeExec() << " to be executed.";
	os << RESET << std::endl;
	return os;
}