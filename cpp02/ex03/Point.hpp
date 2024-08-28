/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 13:45:43 by jeada-si          #+#    #+#             */
/*   Updated: 2024/08/22 13:45:02 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __POINT_H__
# define __POINT_H__
# include "Fixed.hpp"

class Point
{
	private:
		Fixed const	_x;
		Fixed const	_y;
	public:
		Point();
		Point(float const x, float const y);
		Point(const Point &src);
		Point& operator=(const Point &src);
		~Point();
		Fixed const&	getX(void) const;
		Fixed const&	getY(void) const;
		bool			sign(Point const &A, Point const &B) const;
};

std::ostream&	operator<<(std::ostream& out, Point& point);

#endif