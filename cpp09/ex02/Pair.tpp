/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pair.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 08:41:00 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/27 08:57:06 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pair.hpp"
#include <iostream>

template <typename T>
Pair<T>::Pair()
{
	
}

template <typename T>
Pair<T>::Pair(T i, T j):_a(i), b(j)
{
	if (i > j)
		return;
	_a = j;
	_b = i;
}

template <typename T>
Pair<T>::Pair(const Pair<T> &src)
{
	_a = src._a;
	_b = src._b;
}

template <typename T>
Pair<T>& Pair<T>::operator=(const Pair<T> &src)
{
	_a = src._a;
	_b = src._b;
	return *this;
}

template <typename T>
Pair<T>::~Pair()
{
}

template <typename T>
bool	Pair<T>::operator<=(const Pair &src)
{
	return this->_a <= src._a;
}

template <typename T>
bool	Pair<T>::operator>=(const Pair &src)
{
	return this->_a >= src._a;
}
