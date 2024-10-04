/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeV.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:29:00 by jeada-si          #+#    #+#             */
/*   Updated: 2024/10/04 10:01:28 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMeV.hpp"
#include <iostream>
#include <math.h>

PmergeMeV::PmergeMeV()
{
}

PmergeMeV::PmergeMeV(VEC v):_v(v)
{
	_odd = _v.size() % 2;
	_offset = 0;
	_sorted = false;
	_aIdx.push_back(0);
}

PmergeMeV::PmergeMeV(const PmergeMeV &src)
{
	_odd = src._odd;
	_v = src._v;
	_a = src._a;
	_b = src._b;
	_sorted = src._sorted;
	_offset = src._offset;
	_aIdx = src._aIdx;
	_bIdx = src._bIdx;
}

PmergeMeV&	PmergeMeV::operator=(const PmergeMeV &src)
{
	_odd = src._odd;
	_v = src._v;
	_a = src._a;
	_b = src._b;
	_sorted = src._sorted;
	_offset = src._offset;
	_aIdx = src._aIdx;
	_bIdx = src._bIdx;
	return *this;
}

PmergeMeV::~PmergeMeV()
{
}

void	PmergeMeV::fillPairs()
{
	_aIdx.clear();
	_bIdx.clear();
	for (unsigned int i = 0; i < (_v.size() - _odd); i++)
	{
		_b.push_back(_v[i]);
		_bIdx.push_back(i);
		_a.push_back(_v[++i]);
		_aIdx.push_back(i);
		if (_a.back() < _b.back())
		{
			std::swap(_a.back(), _b.back());
			std::swap(_aIdx.back(), _bIdx.back());
		}
	}
	if (_odd)
	{
		_b.push_back(_v.back());
		_bIdx.push_back(_v.size() - 1);
	}
}

void	PmergeMeV::sortPairs()
{
	PmergeMeV	sorted(_a);
	VEC			idx;
	VEC			aSorted;
	VEC 		bSorted;
	VEC			aIdxSorted;
	VEC 		bIdxSorted;

	aSorted = sorted.sort();
	idx = sorted.index();
	for (unsigned int i = 0; i < idx.size(); i++)
	{
		bSorted.push_back(_b[idx[i]]);
		aIdxSorted.push_back(_aIdx[idx[i]]);
		bIdxSorted.push_back(_bIdx[idx[i]]);
	}
	_a = aSorted;
	_b = bSorted;
	_aIdx = aIdxSorted;
	_bIdx = bIdxSorted;
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

// void	PmergeMeV::dichotomy(int value, int valueIdx, float idxRight)
// {
// 	ITER	left = _a.begin();
// 	ITER	right = _a.begin() + idxRight;
// 	ITER	leftIdx = _aIdx.begin();
// 	ITER	rightIdx = _aIdx.begin() + idxRight;

// 	if (*left > value)
// 	{
// 		_a.insert(_a.begin(), value);
// 		_aIdx.insert(_aIdx.begin(), valueIdx);
// 		return ;
// 	}
// 	while (std::distance(left, right) > 1)
// 	{
// 		int dist = std::distance(left, right) / 2;
// 		ITER	middle = left + dist;
// 		ITER	middleIdx = leftIdx + dist;
// 		if (value < *middle)
// 		{
// 			right = middle;
// 			rightIdx = middleIdx;
// 		}
// 		else
// 		{
// 			left = middle;
// 			leftIdx = middleIdx;
// 		}
// 	}
// 	_a.insert(right, value);
// 	_aIdx.insert(rightIdx, valueIdx);
// }

void	PmergeMeV::dichotomy(int value, int valueIdx, float idxRight)
{
	int		i = 0;
	int		j = idxRight;

	if (_a[0] > value)
	{
		_a.insert(_a.begin(), value);
		_aIdx.insert(_aIdx.begin(), valueIdx);
		return ;
	}
	while (j - i != 1)
	{
		int middle = (j + i) / 2;
		if (value < _a[middle])
			j = middle;
		else
			i = middle;
	}
	_a.insert(_a.begin() + j, value);
	_aIdx.insert(_aIdx.begin() + j, valueIdx);
}

VEC	PmergeMeV::sort()
{
	if (_sorted)
		return _a;
	if (_v.size() <= 1)
		return _v;
	fillPairs();
	sortPairs();
	_a.insert(_a.begin(), _b[0]);
	_aIdx.insert(_aIdx.begin(), _bIdx[0]);
	_offset++;
	
	int 			step = 2;
	unsigned int	begin = 0;
	unsigned int	end = 0;
	while (begin < _b.size() - 1)
	{
		begin = jacobsthal(step + 1) - 1;
		end = jacobsthal(step++);
		if (begin > _b.size() - 1)
			begin = _b.size() - 1;
		for (unsigned int j = begin; j != end - 1; j--)
			dichotomy(_b[j], _bIdx[j], begin + _offset++);
	}
	_sorted = true;
	return _a;
}

VEC	PmergeMeV::index()
{
	sort();
	return (_aIdx);
}


std::ostream&	operator<<(std::ostream& os, const VEC& v)
{
	for (CONST_ITER it = v.begin(); it != v.end(); ++it)
		os << std::right << std::setw(3) << *it << "|";
	return os;
}
