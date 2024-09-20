/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:30:12 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/20 11:55:49 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <class T>
				MutantStack<T>::MutantStack()
{
}

template <class T>
				MutantStack<T>::MutantStack(const MutantStack<T> &src)
{
	*this = src;
}

template <class T>
MutantStack<T>&	MutantStack<T>::operator=(const MutantStack<T> &src)
{
	if (*this != src)
		this->c = src.c;
	return *this;
}

template <class T>
				MutantStack<T>::~MutantStack<T>()
{
}

template <class T>
typename MutantStack<T>::iterator		MutantStack<T>::begin()
{
	return this->c.begin();
}

template <class T>
typename MutantStack<T>::iterator		MutantStack<T>::end()
{
	return this->c.end();
}

template <class T>
typename MutantStack<T>::const_iterator	MutantStack<T>::cbegin()
{
	return this->c.cbegin();
}

template <class T>
typename MutantStack<T>::const_iterator	MutantStack<T>::cend()
{
	return this->c.cend();
}
