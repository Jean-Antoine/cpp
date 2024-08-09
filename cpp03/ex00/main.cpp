/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:32:57 by jeada-si          #+#    #+#             */
/*   Updated: 2024/08/08 11:10:47 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include <iomanip>

void	nextScope(std::string title)
{
	std::cout << RED << std::setfill('-') << std::setw(100) << title << RESET << std::endl;
}

int	main(void)
{
	nextScope("CONSTRUCTOR");
	{
		ClapTrap	michmich;
		ClapTrap	jeannot("Jean-Eude");
		ClapTrap	cpy(jeannot);
	};

	nextScope("ASSIGNEMENT");
	{
		ClapTrap	michmich("Michel");
		ClapTrap	random;

		random = michmich;
	};

	nextScope("ATTACK");
	{
		ClapTrap	michmich("Michel");
		ClapTrap	jeannot("Jean-Eude");
		
		for (int i = 0; i < 10; i++)
		{
			michmich.attack("Jean-Eude");
			jeannot.takeDamage(0);
		}
		michmich.attack("Jean-Eude");
		jeannot.takeDamage(9);
		jeannot.beRepaired(1);
		jeannot.takeDamage(2);
		jeannot.attack("un inconnu");
	}	

}