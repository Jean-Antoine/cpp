/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 15:31:36 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/26 14:32:23 by jeada-si         ###   ########.fr       */
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
	_mlts = src._mlts;
}

Span& Span::operator=(const Span &src)
{
	_n = src._n;
	_mlts = src._mlts;
	return *this;
}

Span::~Span()
{
}

void	Span::addNumber(int i)
{
	if (_mlts.size() == _n)
		throw(Span::SpanFull());
	_mlts.insert(i);
}

void	Span::print(void) const
{
	if (! _mlts.size())
	{
		std::cout << "( empty )" << std::endl;
		return;
	}
	std::cout << "( ";
	for (CONST_ITER it = _mlts.begin(); it != _mlts.end(); ++it)
		std::cout << *it << " ";
	std::cout << ")" << std::endl;
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
	return "Not enough space left";
}

void		Span::checkSpan() const
{
	if (_mlts.size() <= 1)
		throw(Span::NotEnoughElements());
}

unsigned int	Span::shortestSpan() const
{
	this->checkSpan();
	if (anyDuplicate())
		return 0;
	unsigned int	out = longestSpan();
	for (CONST_ITER it = _mlts.begin(); it != --_mlts.end(); ++it)
	{
		unsigned int	diff = *(++it) - *(--it);
		if (diff < out)
			out = diff;
	}
	return out;
}

unsigned int	Span::longestSpan() const
{
	this->checkSpan();
	return *(--_mlts.end()) - *_mlts.begin();
}

int		Span::anyDuplicate() const
{
	this->checkSpan();
	for (CONST_ITER it = _mlts.begin(); it != --_mlts.end(); ++it)
	{
		if (*(++it) == *(--it))
			return true;
	}
	return  false;
}
