/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 11:58:11 by jeada-si          #+#    #+#             */
/*   Updated: 2024/10/03 10:04:50 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <ctime>

int	main(int ac, char** av)
{
	if (ac == 1)
		return 1;
	int	i = 1;
	VEC	v;
	while (i < ac)
		v.push_back(static_cast<int>(std::strtol(av[i++], NULL, 10)));
	std::clock_t	t1 = std::clock();
	PmergeMe	p(v);
	std::cout << p.sort() << std::endl;
	std::clock_t	t2 = clock();
	std::cout << std::fixed << std::setprecision(4);
	std::cout << "time is " << static_cast<double>(t2 - t1) / CLOCKS_PER_SEC * 1000 << "ms" << std::endl;
	
}
