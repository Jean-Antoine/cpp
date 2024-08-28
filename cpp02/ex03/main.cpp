/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:20:46 by jeada-si          #+#    #+#             */
/*   Updated: 2024/08/22 14:06:35 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>
bool bsp(Point const a, Point const b, Point const c, Point const point);

int main( void ) {
	Point A(0, 0);
	Point B(0, 10);
	Point C(10, 0);
	Point P1(1, 1);
	Point P2(-1, -1);
	Point P3(0, 5);
	Point X;
	
	A = B;
	std::cout << "A" << A << std::endl;
	std::cout << "B" << B << std::endl;
	std::cout << "C" << C << std::endl;
	std::cout << "P1" << P1 << " inside ABC ? " << bsp(A, B, C, P1) << std::endl;
	std::cout << "P2" << P2 << " inside ABC ? " << bsp(A, B, C, P2) << std::endl;
	std::cout << "P3" << P3 << " inside ABC ? " << bsp(A, B, C, P3) << std::endl;
	std::cout << "A" << A << " inside ABC ? " << bsp(A, B, C, A) << std::endl;
	return 0;
}
