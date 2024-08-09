/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:32:57 by jeada-si          #+#    #+#             */
/*   Updated: 2024/08/08 14:31:47 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iomanip>

void	nextScope(std::string title)
{
	std::cout << RED << std::setfill('-') << std::setw(100) << title << RESET << std::endl;
}

int	main(void)
{
	nextScope("CONSTRUCTORS");
	{
		ScavTrap	michel("Michel");
		ScavTrap	unknown;
		ScavTrap	jeannot(michel);
		
		michel.displayStats();
		unknown.displayStats();
		jeannot.displayStats();
	}
	nextScope("ASSIGNEMENT");
	{
		ScavTrap	michel("Michel");
		ScavTrap	jeannot;

		jeannot.displayStats();
		michel.displayStats();
		jeannot = michel;
		jeannot.displayStats();
		michel.displayStats();
	}
	nextScope("ATTACK + SAFE GUARD");
	{
		ScavTrap	michel("Michel");
		ScavTrap	jeannot("Jeannot");
		
		for (int i = 0; i < 6; i++)
		{
			michel.attack("Jeannot");
			jeannot.takeDamage(20);
			jeannot.displayStats();
		}
		michel.guardGate();
	}
}
