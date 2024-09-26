/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 08:11:41 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/26 14:40:52 by jeada-si         ###   ########.fr       */
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
	
	std::srand(std::time(NULL));
	Span	sp = Span(5);
	for (int i = 0; i < 5; i++)
		sp.addNumber(std::rand() % 20);
	sp.print();
	std::cout << BLUE "Shortest span is " << sp.shortestSpan() << std::endl << RESET;
	std::cout <<BLUE "Longest span is " <<  sp.longestSpan() << std::endl << RESET;
	
	int		n = 10;
	Span	sp2 = Span(n);
	for (int i = 0; i < n; i++)
		sp2.addNumber(std::rand() % 1000);
	sp2.print();
	std::cout << BLUE "Shortest span is " << sp2.shortestSpan() << std::endl << RESET;
	std::cout << BLUE "Longest span is " << sp2.longestSpan() << std::endl << RESET;

	std::vector<int>	v;
	for (int i = 0; i < 10; i++)
		v.push_back(std::rand() % INT_MAX);
	try
	{
		empty.addNumber(v.begin(), v.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << '\n' << RESET;
	}
	Span	sp3 = Span(10);
	sp3.addNumber(v.begin(), v.end());
	sp3.print();
	std::cout << BLUE "Shortest span is " << sp3.shortestSpan() << std::endl << RESET;
	std::cout << BLUE "Longest span is " << sp3.longestSpan() << std::endl << RESET;
	return 0;
}