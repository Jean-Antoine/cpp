/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:41:49 by jeada-si          #+#    #+#             */
/*   Updated: 2024/07/31 15:05:11 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie	*horde = new Zombie[N];
	
	for (int i = 0; i < N; i++)
	{
		std::string	name_ = name;
		name_.push_back(i + '0');
		horde[i].setName(name_);
	}		
	return (horde);
}
