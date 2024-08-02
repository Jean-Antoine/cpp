/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:16:23 by jeada-si          #+#    #+#             */
/*   Updated: 2024/07/31 14:46:40 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

static void	scopeIn()
{
	std::cout << "Entering scope >>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
}

static void	scopeOut()
{
	std::cout << "Leaving scope  <<<<<<<<<<<<<<<<<<<<<<<" << std::endl << std::endl;
}

int	main(void)
{
	scopeIn();
	{		
		Zombie	Z("Zombie 1");
		
		Z.announce();
		//Z destructed automatically when out of scope.
	}
	scopeOut();
	scopeIn();
	{
		Zombie *Z = new Zombie("Zombie 2"); // Allocated.
		Z->announce();
		// If not deleted -> leak.
		delete Z; 
	}
	scopeOut();
	scopeIn();
	{
		randomChump("Zombie 3");
	}
	scopeOut();
}