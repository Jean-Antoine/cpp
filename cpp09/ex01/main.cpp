/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:35:04 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/26 10:02:41 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

static int	checkInput(std::string in)
{
	std::string	str = "0123456789+-*/";
	
	if (in.size() % 2 == 0)
		return false;
	for (unsigned int i = 0; i < in.size(); i++)
	{
		if (i % 2 == 0
			&& str.find(in[i]) == std::string::npos)
			return false;
		if (i % 2 == 1 && in[i] != ' ')
			return false;
	}
	return true;
}

int	main(int ac, char** av)
{
	if (ac != 2 || !checkInput(av[1]))
	{
		std::cerr << RED "Error\n";
		return 1;
	}
	RPN out(av[1]);
	try
	{
		std::cout << out.compute() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET "\n";
	}	
	return 0;
}