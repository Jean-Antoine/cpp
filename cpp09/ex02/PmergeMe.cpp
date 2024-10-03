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
}

PmergeMe::PmergeMe(const PmergeMe &src)
{
	_v = src._v;
	_odd = _v.size() % 2;
	_offset = 0;
}

PmergeMe&	PmergeMe::operator=(const PmergeMe &src)
{
	_v = src._v;
	_odd = _v.size() % 2;
	_offset = 0;
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
	VEC	aSorted;
	VEC bSorted;

	aSorted = _a;
	std::sort(aSorted.begin(), aSorted.end());
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

void	PmergeMe::algoVerbose()
{
	int 			step = 2;
	unsigned int	begin = 0;
	std::cout << BLUE << "Pairing :\n" RESET;
	fillPairs();
	print();
	std::cout << BLUE << "Sorting :\n" RESET;
	sortPairs();
	print();

	_a.insert(_a.begin(), _b[0]);
	_offset++;
	_b[0] = -1;
	_b.insert(_b.begin(), -1);
	std::cout << BLUE "Insert b0\n" RESET;
	print();
	while (begin < _bSize - 1)
	{
		begin = jacobsthal(step + 1) - 1;
		unsigned int	end = jacobsthal(step++);
		if (begin > _bSize)
			begin = _bSize - 1;
		std::cout << BLUE "Elements b" << begin << " to b" << end << RESET << std::endl;
		for (unsigned int j = begin; j != end - 1; j--)
		{
			std::cout << GREEN "Element b" << j << " = " << _b[j + _offset];
			std::cout << " before a" << begin << " = " << _a[begin + _offset] << RESET << std::endl;
			dichotomy(_a, _b[j + _offset], begin + _offset);
			_b[j + _offset] = -1;
			_b.insert(_b.begin() + 1, -1);
			_offset++;
			print();
		}
	}
}


std::ostream&	operator<<(std::ostream& os, const VEC& v)
{
	for (CONST_ITER it = v.begin(); it != v.end(); ++it)
	{
		if (*it == -1)
			os << std::right << std::setw(3) << " " << "|";
		else
			os << std::right << std::setw(3) << *it << "|";
	}
	return os;
}

void	PmergeMe::print() const
{
	std::cout << GREEN "    ";
	for (unsigned int i = 0; i < _bSize; i++)
	{
		if (i < _offset)
		{
			std::cout << std::right << std::setw(3) << " " << "|";
			std::cout << std::right << std::setw(3) << " " << "|";
		}
		else
			std::cout << "a" << std::left << std::setw(2) << i << "|";
	}
	std::cout << RESET << std::endl;
	std::cout << "_a: " << _a << std::endl;
	std::cout << "_b: " << _b << std::endl;
	std::cout << GREEN "    ";
	for (unsigned int i = 0; i < _b.size(); i++)
	{
		if (_b[i] == -1)
		{
			std::cout << std::right << std::setw(3) << " " << "|";
		}
		else
			std::cout << "b" << std::left << std::setw(2) << i - _offset << "|";
	}
	std::cout << RESET << std::endl;
}
