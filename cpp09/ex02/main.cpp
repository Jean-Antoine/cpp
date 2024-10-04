/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 11:58:11 by jeada-si          #+#    #+#             */
/*   Updated: 2024/10/04 11:29:58 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <ctime>
#include <algorithm>
#include <vector>
#include <deque>
#include <limits>

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

int	checkInput(std::string s)
{
	if (!s.size())
		return -1;
	for (std::string::iterator it = s.begin(); it != s.end(); it++)
	{
		if (!std::isdigit(*it))
			return -1;		
	}	
	double value = std::strtol(s.data(), NULL, 10);
	if (value > std::numeric_limits<int>::max())
		return -1;
	return static_cast<int>(value);
}

std::ostream&	operator<<(std::ostream& os, std::vector<int> const &v)
{
	for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
		os << *it << " "; 
	return os;
}

int	main(int ac, char** av)
{
	if (ac == 1)
		return 1;
	int	i = 1;
	
	std::deque<int>		d;
	std::vector<int>	v;
	while (i < ac)
	{
		int value = checkInput(av[i++]);
		if (value < 0)
		{
			std::cout << "Error\n";
			return 1;
		}
		v.push_back(value);
		d.push_back(value);
	}
	std::clock_t		t1;
	std::clock_t		t2;
	
	t1 = clock();
	PmergeMe< std::vector<int> >	pv(v);
	pv.sort();
	t2 = clock();
	std::cout << "Before:\t" << v << std::endl;
	std::cout << "After:\t" << pv.sort() << std::endl;
	std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector : ";
	std::cout << static_cast<double>(t2 - t1) / CLOCKS_PER_SEC * 1e6 << " us" << std::endl;


	t1 = clock();
	PmergeMe< std::deque<int> >	pd(d);
	pd.sort();
	t2 = clock();
	std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque  : ";
	std::cout << static_cast<double>(t2 - t1) / CLOCKS_PER_SEC * 1e6 << " us" << std::endl;

	if (!isSorted(pd.sort()) || !isSorted(pv.sort()))
	{
		std::cout << "Sorting failed!" << std::endl;
		return EXIT_FAILURE;
	}
	return 0;
}
