/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:45:09 by jeada-si          #+#    #+#             */
/*   Updated: 2024/08/06 15:57:28 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	bool	sign;

	sign = point.sign(a, b);
	if (sign != point.sign(b,c))
		return (0);
	if (sign != point.sign(c, a))
		return (0);
	return (1);
};
