/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:32:21 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/05 14:39:40 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat	julien("Julien", 2);
	Bureaucrat	vincent("Vincent", 149);
	
	std::cout << julien << vincent;
	julien.incrGrade();
	vincent.decrGrade();
	std::cout << julien << vincent;
	
	try
	{
		std::cout << julien;
		std::cout << BLUE "Trying to increment Julien's grade :";
		std::cout << RESET << std::endl;
		julien.incrGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << "\n" RESET;
	}

	try
	{
		std::cout << BLUE "Trying to increment Vincent's grade :";
		std::cout << RESET << std::endl;
		vincent.decrGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << "\n" RESET;
	}

	try
	{
		std::cout << BLUE "Trying to instantiate a bureaucrat :";
		std::cout << " with a grade lower than 150" RESET;
		std::cout << std::endl;
		Bureaucrat	carlos("Carlos", 200);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << "\n" RESET;
	}
}
