/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:41:49 by jeada-si          #+#    #+#             */
/*   Updated: 2024/08/21 10:07:33 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>

static std::string	nameIdx(std::string name, int i)
{
	name.push_back(i + '0');
	return (name);
}

Zombie*	zombieHorde(int N, std::string name)
{
	if (N < 1)
		return 0;
	Zombie	*horde = new Zombie[N];
	for (int i = 0; i < N; i++)
		horde[i].setName(nameIdx(name, i));
	return (horde);
}
