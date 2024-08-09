/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:32:57 by jeada-si          #+#    #+#             */
/*   Updated: 2024/08/08 14:55:54 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iomanip>

void	nextScope(std::string title)
{
	std::cout << RED << std::setfill('-') << std::setw(100) << title << RESET << std::endl;
}

int	main(void)
{
	nextScope("CONSTRUCTORS");
	{
		FragTrap	michel("Michel");
		FragTrap	unknown;
		FragTrap	jeannot(michel);
		
		michel.displayStats();
		unknown.displayStats();
		jeannot.displayStats();
	}
	nextScope("ASSIGNEMENT");
	{
		FragTrap	michel("Michel");
		FragTrap	jeannot;

		jeannot.displayStats();
		michel.displayStats();
		jeannot = michel;
		jeannot.displayStats();
		michel.displayStats();
	}
	nextScope("HIGH FIVE");
	{
		FragTrap	michel("Michel");

		michel.highFiveGuys();
	}
}
