/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:10:04 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/20 13:39:56 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WHATEVER_HPP__
# define __WHATEVER_HPP__

template<typename T>
void	swap(T& a, T& b)
{
	T	c;

	c = b;
	b = a;
	a = c;
}

template<typename T>
T	min(T a, T b)
{
	if (a >= b)
		return b;
	return a;			
}

template<typename T>
T	max(T a, T b)
{
	if (a <= b)
		return b;
	return a;
}

#endif