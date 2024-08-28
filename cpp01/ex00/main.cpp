/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:16:23 by jeada-si          #+#    #+#             */
/*   Updated: 2024/08/21 09:41:05 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	nextScope(std::string title)
{
	std::cout << RED << std::setfill('-') << std::setw(100) << title << RESET << std::endl;
}

int	main(void)
{
	nextScope("ZOMBIE 1");
	{		
		Zombie	Z("Zombie 1");
		
		Z.announce();
		//Z destructed automatically when out of scope.
	}
	nextScope("ZOMBIE 2");
	{
		Zombie *Z = new Zombie("Zombie 2"); // Allocated.
		Z->announce();
		// If not deleted -> leak.
		delete Z; 
	}
	nextScope("ZOMBIE 3");
	{
		randomChump("Zombie 3");
	}
}