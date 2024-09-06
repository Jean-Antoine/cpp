/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:03:56 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/05 14:56:13 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm():
	AForm("ShrubberyCreationForm", "target", 145, 137)
{
	//std::cout << BLUE "[ShrubberyCreationForm] Default constructor called" RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target):
	AForm("ShrubberyCreationForm", target, 145, 137)
{
	//std::cout << BLUE "[ShrubberyCreationForm] Default constructor called" RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src):
	AForm(src.getName(), src.getTarget(), 145, 137)
{
	//std::cout << BLUE "[ShrubberyCreationForm] Copy constructor called" RESET << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	(void) src;
	//std::cout << BLUE "[ShrubberyCreationForm] Assignment operator called" RESET << std::endl;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	//std::cout << BLUE "[ShrubberyCreationForm] Destructor called" RESET << std::endl;
}

void	ShrubberyCreationForm::executeSpecific(void) const
{	
	std::string		filename = this->getTarget() + "_shrubbery";
	std::ofstream	os;
	
	os.open(filename.data());
	if (!os)
		throw(FileWrittingException());
	os << "       _-_" << std::endl;
	os << "    /~~   ~~\\" << std::endl;
	os << " /~~         ~~\\" << std::endl;
	os << "{               }" << std::endl;
	os << " \\  _-     -_  /" << std::endl;
	os << "   ~  \\\\ //  ~" << std::endl;
	os << "_- -   | | _- _" << std::endl;
	os << "  _ -  | |   -_" << std::endl;
	os << "      // \\\\" << std::endl;
	os.close();
}

const char* ShrubberyCreationForm::FileWrittingException::what(void) const throw()
{
	return "Could not open output file.";
}
