/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:32:21 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/05 14:48:08 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	try
	{
		std::cout << BLUE "Trying to create a form that needs a ";
		std::cout << "grade 151 to be signed." RESET << std::endl;
		Form	test("test", 151, 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << '\n' << RESET;
	}

	try
	{
		std::cout << BLUE "Trying to create a form that needs a ";
		std::cout << "grade 0 to be executed." RESET << std::endl;
		Form	test("test", 100, 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << '\n' << RESET;
	}
	
	Bureaucrat	julien("Julien", 30);
	Bureaucrat	vincent("Vincent", 100);
	Form		form1("Formulaire1", 50, 20);
	Form		form2("Formulaire2", 120, 50);
	std::cout << julien << vincent << form1;
	vincent.signForm(form1);
	julien.signForm(form1);
	vincent.signForm(form2);
	std::cout << form1 << form2;
}
