/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:32:21 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/05 14:01:36 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main()
{
	AForm*					form1;
	AForm*					form2;
	AForm*					form3;
	AForm*					form4;
	Intern					intern;
	Bureaucrat				director("Director", 1);
	
	try
	{
		form1 = intern.makeForm("robotomy request", "robot");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << *form1;
	director.signForm(*form1);
	director.executeForm(*form1);	
	delete form1;

	try
	{
		form2 = intern.makeForm("presidential pardon", "victime");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << *form2;
	director.signForm(*form2);
	director.executeForm(*form2);	
	delete form2;

	try
	{
		form3 = intern.makeForm("shrubbery creation", "forest");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << *form3;
	director.signForm(*form3);
	director.executeForm(*form3);	
	delete form3;
	
	try
	{
		form4 = intern.makeForm("unknown", "unknown");
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << "\n" RESET;
	}
}
