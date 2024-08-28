/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:20:46 by jeada-si          #+#    #+#             */
/*   Updated: 2024/08/22 12:39:19 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <iomanip>

void	display(std::string label)
{
	std::cout << BLUE << std::setfill(' ') << std::setw(10);
	std::cout << label << " " << RESET;
}

int main( void ) {
	Fixed a;
	Fixed b;
	display("a ="); std::cout << a << std::endl;
	display("++a"); std::cout << ++a << std::endl;
	display("a ="); std::cout << a << std::endl;
	display("a++"); std::cout << a++ << std::endl;
	display("a ="); std::cout << a << std::endl;
	display("a--"); std::cout << a-- << std::endl;
	display("a ="); std::cout << a << std::endl;
	display("--a"); std::cout << --a << std::endl;
	display("a ="); std::cout << a << std::endl;
	a = Fixed(10.70f);
	b = Fixed(05.69f);
	display("a ="); std::cout << a << std::endl;
	display("b ="); std::cout << b << std::endl;
	display("max ?"); std::cout << Fixed::max( a, b ) << std::endl;
	display("min ?"); std::cout << Fixed::min( a, b ) << std::endl;
	display("a < b ?"); std::cout << (a < b) << std::endl;
	display("a > b ?"); std::cout << (a > b) << std::endl;
	display("a == b ?"); std::cout << (a == b) << std::endl;
	display("a != b ?"); std::cout << (a != b) << std::endl;
	return 0;
}