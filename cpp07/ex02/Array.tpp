/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 09:36:11 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/19 11:48:10 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <class T>
void			Array<T>::allocate()
{
	if (!_n)
		_array = NULL;
	else
		_array = new T[_n];
}

template <class T>
void			Array<T>::free()
{
	if (_n)
		delete[] _array;
}

template <class T>
void			Array<T>::copy(const Array<T>& src)
{
	for (unsigned int i = 0; i < src.size(); i++)
		this->_array[i] = src[i];
}

template <class T>
				Array<T>::Array()
{
	_n = 0;
	allocate();
}

template <class T>
				Array<T>::Array(unsigned int n)
{
	_n = n;
	allocate();
}

template <class T>
				Array<T>::Array(const Array<T> &src)
{	
	this->_n = src.size();
	allocate();
	this->copy(src);
}

template <class T>
Array<T>&		Array<T>::operator=(const Array<T> &src)
{
	free();
	this->_n = src.size();
	allocate();
	copy(src);
	return *this;
}

template <class T>
				Array<T>::~Array()
{
	free();
}

template <class T>
unsigned int	Array<T>::size() const
{
	return _n;
}

template <class T>
T&				Array<T>::operator[](unsigned int i) const
{
	if (i >= _n)
		throw(Array<T>::IndexOutOfBounds());
	return this->_array[i];
}

template <class T>
std::ostream&	operator<<(std::ostream& os, Array<T> obj)
{
	if (!obj.size())
		return os;
	for (unsigned int i = 0; i < obj.size(); i++)
		os << obj[i];
	return os;
}

template <class T>
const char*	Array<T>::IndexOutOfBounds::what() const throw()
{
	return "Index out of bounds";
}
