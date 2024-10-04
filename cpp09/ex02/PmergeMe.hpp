/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 08:59:12 by jeada-si          #+#    #+#             */
/*   Updated: 2024/10/04 11:36:13 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PMERGEME_HPP__
# define __PMERGEME_HPP__
# include <string>
# include <iostream>
# include <iomanip>
# include <vector>
int	jacobsthal(int n);
template<typename T>
class PmergeMe
{
	typedef typename T::iterator		ITER;
	typedef typename T::const_iterator	CONST_ITER;
	private:
		bool			_odd;
		T				_v;
		T				_a;
		T				_b;
		bool			_sorted;
		unsigned int	_offset;
		T				_aIdx;
		T				_bIdx;
		void			fillPairs();
		void			sortPairs();
		void			dichotomy(int value, int valueIdx, float idxRight);
	public:
						PmergeMe();
						PmergeMe(T v);
						PmergeMe(const PmergeMe &src);
						~PmergeMe();
		PmergeMe&		operator=(const PmergeMe &src);
		T				sort();
		T				index();
};
#include "PmergeMe.tpp"

#endif