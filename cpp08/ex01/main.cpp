/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 08:11:41 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/20 12:12:02 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>
#include <ctime>
#include <limits.h>
#include <vector>

int main()
{
	Span	empty;
	try
	{
		empty.addNumber(10);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << '\n' << RESET;
	}
	try
	{
		empty.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << '\n' << RESET;
	}	
	
	Span	sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	sp.print();
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	
	int		n = 10;
	Span	sp2 = Span(n);
	std::srand(std::time(NULL));
	for (int i = 0; i < n; i++)
		sp2.addNumber(std::rand() % INT_MAX);
	sp2.print();
	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;
	std::cout << "Any duplicates ? " << (sp2.anyDuplicate() ? "true" : "false");
	std::cout << std::endl;

	std::vector<int>	v;
	for (int i = 0; i < 10; i++)
		v.push_back(std::rand() % INT_MAX);
	try
	{
		empty.addRange(v.begin(), v.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << '\n' << RESET;
	}
	Span	sp3 = Span(10);
	sp3.addRange(v.begin(), v.end());
	sp3.print();
	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;
	return 0;
}