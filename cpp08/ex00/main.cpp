/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:05:16 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/26 13:14:26 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <iostream>
#define RESET	"\e[0m"
#define RED	"\e[1;31m"

const char*	NotFound::what() const throw()
{
	return "Not found";
}

int	main(void)
{
	std::vector<int>	v(100);
	
	std::fill(v.begin(), v.end(), 1);
	v.insert(v.begin() + 50, 9);
	try
	{
		std::cout << "Index is " << easyfind(v, 9) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET "\n";
	}
	try
	{
		std::cout << "Index is " << easyfind(v, 99) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET "\n";
	}	
}
