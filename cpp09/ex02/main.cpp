/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 11:58:11 by jeada-si          #+#    #+#             */
/*   Updated: 2024/10/04 09:58:20 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMeV.hpp"
#include <ctime>
#include <algorithm>

template<typename T>
bool	isSorted(T c)
{
	for (typename T::iterator it = c.begin(); it != c.end() - 1; it++)
	{
		typename T::iterator next = it + 1;
		if (*it > *next)
			return false;
	}
	return true;
}

int	main(int ac, char** av)
{
	if (ac == 1)
		return 1;
	int	i = 1;
	VEC	v;
	while (i < ac)
		v.push_back(static_cast<int>(std::strtol(av[i++], NULL, 10)));
	// std::cout << v << std::endl;
	std::clock_t	t1 = std::clock();
	PmergeMeV	p(v);
	p.sort();
	// std::cout << p.sort() << std::endl;
	std::clock_t	t2 = clock();
	std::cout << std::fixed << std::setprecision(4);
	std::cout << "time is " << static_cast<double>(t2 - t1) / CLOCKS_PER_SEC * 1000 << "ms" << std::endl;
	std::cout << "is sorted " << (isSorted(p.sort()) == true ? "true": "false") << std::endl;
}
