/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 15:31:36 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/20 09:52:29 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <limits.h>

Span::Span(): _n(0)
{
}

Span::Span(unsigned long n): _n(n)
{
}

Span::Span(const Span &src)
{
	_n = src._n;
	_v = src._v;
}

Span& Span::operator=(const Span &src)
{
	_n = src._n;
	_v = src._v;
	return *this;
}

Span::~Span()
{
}

void	Span::addNumber(int i)
{
	if (_v.size() == _n)
		throw(Span::SpanFull());
	std::vector<int>::iterator upper = std::upper_bound(_v.begin(), _v.end(), i);		
	if (upper == _v.end())
		_v.push_back(i);
	else
		_v.insert(upper, i);	
}

void	Span::print(void) const
{
	if (! _v.size())
	{
		std::cout << "( empty )" << std::endl;
		return;
	}
	std::cout << "(";
	for (CONST_ITER it = _v.begin(); it != _v.end(); ++it)
		std::cout << " " << *it;
	std::cout << " )" << std::endl;
}

char const*	Span::SpanFull::what() const throw()
{
	return "Span is full";
}

char const*	Span::NotEnoughElements::what() const throw()
{
	return "Not enough elements to compute span";
}

char const*	Span::NotEnoughSpaceLeft::what() const throw()
{
	return "Not enough space left in span";
}

void		Span::checkSpan() const
{
	if (_v.size() <= 1)
		throw(Span::NotEnoughElements());
}

int			Span::shortestSpan() const
{
	this->checkSpan();
	
	int	out = INT_MAX;
	for (CONST_ITER it = _v.begin(); it != _v.end() - 1; ++it)
	{
		int	diff = *(it + 1) - *it;
		if (diff < out)
			out = diff;
	}
	return out;
}

int			Span::longestSpan() const
{
	this->checkSpan();
	return *(_v.end() - 1) - *_v.begin();
}

int		Span::anyDuplicate() const
{
	this->checkSpan();
	for (CONST_ITER it = _v.begin(); it != _v.end() - 1; ++it)
	{
		if (*(it + 1) == *it)
			return true;
	}
	return  false;
}

void	Span::addRange(CONST_ITER begin, CONST_ITER end)
{
	if ((unsigned long) std::distance(begin, end) > (_n - _v.size()))
		throw(Span::NotEnoughSpaceLeft());
	for (CONST_ITER it = begin; it != end; ++it)
		this->addNumber(*it);
}