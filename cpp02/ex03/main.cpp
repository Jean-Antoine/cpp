/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:20:46 by jeada-si          #+#    #+#             */
/*   Updated: 2024/08/06 16:19:29 by jeada-si         ###   ########.fr       */
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
	
	std::cout << "P1 dans ABC ? " << bsp(A, B, C, P1) << std::endl;
	std::cout << "P2 dans ABC ? " << bsp(A, B, C, P2) << std::endl;
	return 0;
}
