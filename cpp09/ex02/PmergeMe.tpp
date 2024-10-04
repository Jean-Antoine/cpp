/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:29:00 by jeada-si          #+#    #+#             */
/*   Updated: 2024/10/04 10:01:28 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <math.h>

template<typename T>
PmergeMe<T>::PmergeMe()
{
}

template<typename T>
PmergeMe<T>::PmergeMe(T v):_v(v)
{
	_odd = _v.size() % 2;
	_offset = 0;
	_sorted = false;
	_aIdx.push_back(0);
}

template<typename T>
PmergeMe<T>::PmergeMe(const PmergeMe<T> &src)
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

template<typename T>
PmergeMe<T>&	PmergeMe<T>::operator=(const PmergeMe<T> &src)
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

template<typename T>
PmergeMe<T>::~PmergeMe()
{
}

template<typename T>
void	PmergeMe<T>::fillPairs()
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

template<typename T>
void	PmergeMe<T>::sortPairs()
{
	PmergeMe	sorted(_a);
	T			idx;
	T			aSorted;
	T 			bSorted;
	T			aIdxSorted;
	T 			bIdxSorted;

	aSorted = sorted.sort();
	idx = sorted.index();
	for (unsigned int i = 0; i < idx.size(); i++)
	{
		bSorted.push_back(_b[idx[i]]);
		aIdxSorted.push_back(_aIdx[idx[i]]);
		bIdxSorted.push_back(_bIdx[idx[i]]);
	}
	if (_odd)
	{
		bSorted.push_back(_b.back());
		bIdxSorted.push_back(_bIdx.back());
	}
	_a = aSorted;
	_b = bSorted;
	_aIdx = aIdxSorted;
	_bIdx = bIdxSorted;
}

template<typename T>
void	PmergeMe<T>::dichotomy(int value, int valueIdx, float idxRight)
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

template<typename T>
T	PmergeMe<T>::sort()
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

template<typename T>
T	PmergeMe<T>::index()
{
	sort();
	return (_aIdx);
}
