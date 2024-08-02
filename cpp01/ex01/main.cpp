/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:16:23 by jeada-si          #+#    #+#             */
/*   Updated: 2024/07/31 15:03:57 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*horde;
	int		N;

	N = 10;
	horde = zombieHorde(N, "zomby");
	for (int i = 0; i < N; i++)
		(horde + i)->announce();
	delete [] horde;
}