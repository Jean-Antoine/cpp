/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:17:58 by jeada-si          #+#    #+#             */
/*   Updated: 2024/08/01 17:12:27 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Wrong number of arguments!" << std::endl;
		std::cout << "Usage: ./Sed [filename] [s1] [s2]" << std::endl;
		return 1;
	}
	Sed s(av[1], av[2], av[3]);
	return (s.replace());
}
