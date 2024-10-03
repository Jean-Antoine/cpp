/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 08:59:12 by jeada-si          #+#    #+#             */
/*   Updated: 2024/10/03 09:22:43 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PMERGEME_HPP__
# define __PMERGEME_HPP__
# include <string>
# include <iostream>
# include <iomanip>
# include <vector>
# include <algorithm>
# define GREEN	"\e[1;32m"
# define YELLOW	"\e[1;33m"
# define RED	"\e[1;31m"
# define BLUE	"\e[1;34m"
# define PINK	"\e[1;35m"
# define RESET	"\e[0m"

typedef std::vector<int>	VEC;
typedef VEC::iterator		ITER;
typedef VEC::const_iterator	CONST_ITER;

class PmergeMe
{
	private:
		bool			_odd;
		VEC				_v;
		VEC				_a;
		VEC				_b;
		VEC				_sorted;
		unsigned int	_offset;
		unsigned int	_bSize;
						PmergeMe();
	public:
						PmergeMe(VEC v);
						PmergeMe(const PmergeMe &src);
						~PmergeMe();
		PmergeMe&		operator=(const PmergeMe &src);
		void			fillPairs();
		void			sortPairs();
		void			algoVerbose();
		void			print() const;
};

std::ostream&	operator<<(std::ostream& os, const VEC& v);

#endif