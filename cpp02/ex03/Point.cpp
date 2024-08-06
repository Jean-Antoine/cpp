/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 13:45:20 by jeada-si          #+#    #+#             */
/*   Updated: 2024/08/06 15:49:24 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point()
{
}

Point::Point(float const x, float const y): _x(Fixed(x)), _y(Fixed(y))
{
}

Point::Point(const Point &src): _x(src._x), _y(src._y)
{
}

Point& Point::operator=(const Point &src)
{
	(void) src;
	return (*this);
}

Point::~Point()
{
}

Fixed const&	Point::getX(void) const
{
	return (this->_x);
}

Fixed const&	Point::getY(void) const
{
	return (this->_y);
}

bool	Point::sign(Point const &A, Point const &B) const
{	
	return ((this->getX() - B.getX()) * (A.getY() - B.getY())
		- (A.getX() - B.getX()) * (this->getY() - B.getY()) > 0);
}
