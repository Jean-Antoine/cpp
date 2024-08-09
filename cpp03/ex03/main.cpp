/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:32:57 by jeada-si          #+#    #+#             */
/*   Updated: 2024/08/08 14:56:57 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iomanip>

void	nextScope(std::string title)
{
	std::cout << RED << std::setfill('-') << std::setw(100);
	std::cout << title << RESET << std::endl;
}

int	main(void)
{
	nextScope("DEFAULT CONSTRUCTORS");
	{
		DiamondTrap	unknown;

		unknown.displayStats();
	}
	nextScope("NAME CONSTRUCTORS");
	{
		DiamondTrap	michmich("Michel");

		michmich.displayStats();
	}
	nextScope("COPY CONSTRUCTOR");
	{
		DiamondTrap michmich("michel");
		michmich.takeDamage(100);
		DiamondTrap	unknown(michmich);
		unknown.displayStats();	
	}
	nextScope("ASSIGNEMENT");
	{
		DiamondTrap	michel("Michel");
		DiamondTrap	jeannot;

		jeannot.displayStats();
		michel.displayStats();
		michel.takeDamage(100);
		jeannot = michel;
		jeannot.displayStats();
		michel.displayStats();
	}
	nextScope("ATTACK + SAFE GUARD");
	{
		DiamondTrap	michel("Michel");
		DiamondTrap	jeannot("Jeannot");
		
		for (int i = 0; i < 6; i++)
		{
			michel.attack("Jeannot");
			jeannot.takeDamage(20);
			jeannot.displayStats();
		}
		michel.highFiveGuys();
	}
}
