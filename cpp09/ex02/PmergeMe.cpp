/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 08:59:45 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/27 08:59:53 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(VEC v):_v(v)
{
	_odd = _v.size() % 2;
	_offset = 0;
	_sorted = false;
}

PmergeMe::PmergeMe(const PmergeMe &src)
{
	_odd = src._odd;
	_v = src._v;
	_a = src._a;
	_b = src._b;
	_sorted = src._sorted;
	_offset = src._offset;
	_bSize = src._bSize;
}

PmergeMe&	PmergeMe::operator=(const PmergeMe &src)
{
	_odd = src._odd;
	_v = src._v;
	_a = src._a;
	_b = src._b;
	_sorted = src._sorted;
	_offset = src._offset;
	_bSize = src._bSize;
	return *this;
}

PmergeMe::~PmergeMe()
{
}

void	PmergeMe::fillPairs()
{
	for (ITER it = _v.begin(); it != _v.end() - _odd; ++it)
	{
		_b.push_back(*it);
		_a.push_back(*++it);
		if (_a.back() < _b.back())
			std::swap(_a.back(), _b.back());
	}
	if (_odd)
		_b.push_back(*(_v.end() - 1));
	_bSize = _b.size();
}

void	PmergeMe::sortPairs()
{
	PmergeMe	sorted(_a);
	VEC			aSorted;
	VEC 		bSorted;

	aSorted = sorted.sort();
	for (ITER it = aSorted.begin(); it != aSorted.end(); ++it)
	{
		ITER	ait = std::find(_a.begin(), _a.end(), *it);
		int		idx = std::distance(_a.begin(), ait);

		bSorted.push_back(_b[idx]);
	}
	if (_odd)
		bSorted.push_back(*(_b.end() - 1));
	_a = aSorted;
	_b = bSorted;
}

static int	jacobsthal(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

static void	dichotomy(VEC& _a, int value, int idxRight)
{
	ITER	left = _a.begin();
	ITER	right = _a.begin() + idxRight;

	if (*left > value)
	{
		_a.insert(_a.begin(), value);
		return ;
	}
	while (std::distance(left, right) > 1)
	{
		ITER	middle = left + std::distance(left, right) / 2;
		if (value < *middle)
			right = middle;
		else
			left = middle;
	}
	_a.insert(right, value);
}

VEC	PmergeMe::sort()
{
	if (_v.size() <= 1)
		return _v;
	if (_sorted)
		return _a;
	int 			step = 2;
	unsigned int	begin = 0;
	unsigned int	end = 0;
	fillPairs();
	sortPairs();

	_a.insert(_a.begin(), _b[0]);
	_offset++;
	while (begin < _bSize - 1)
	{
		begin = jacobsthal(step + 1) - 1;
		end = jacobsthal(step++);
		if (begin > _bSize - 1)
			begin = _bSize - 1;
		for (unsigned int j = begin; j != end - 1; j--)
			dichotomy(_a, _b[j], begin + _offset++);
	}
	return _a;
}


std::ostream&	operator<<(std::ostream& os, const VEC& v)
{
	for (CONST_ITER it = v.begin(); it != v.end(); ++it)
		os << std::right << std::setw(3) << *it << "|";
	return os;
}

void	PmergeMe::print() const
{
	std::cout << "_a: " << _a << std::endl;
	std::cout << "_b: " << _b << std::endl;
}
