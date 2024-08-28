/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:16:23 by jeada-si          #+#    #+#             */
/*   Updated: 2024/08/21 10:06:49 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int		N = 10;
	Zombie	*horde = zombieHorde(N, "zomby");

	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete [] horde;
}
