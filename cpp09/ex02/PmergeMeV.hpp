/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeV.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 08:59:12 by jeada-si          #+#    #+#             */
/*   Updated: 2024/10/04 09:27:46 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PMERGEMEV_HPP__
# define __PMERGEMEV_HPP__
# include <string>
# include <iostream>
# include <iomanip>
# include <vector>
typedef std::vector<int>	VEC;
typedef VEC::iterator		ITER;
typedef VEC::const_iterator	CONST_ITER;

class PmergeMeV
{
	private:
		bool			_odd;
		VEC				_v;
		VEC				_a;
		VEC				_b;
		bool			_sorted;
		unsigned int	_offset;
		VEC				_aIdx;
		VEC				_bIdx;
		void			fillPairs();
		void			sortPairs();
		void			dichotomy(int value, int valueIdx, float idxRight);
	public:
						PmergeMeV();
						PmergeMeV(VEC v);
						PmergeMeV(const PmergeMeV &src);
						~PmergeMeV();
		PmergeMeV&		operator=(const PmergeMeV &src);
		VEC				sort();
		VEC				index();
};

std::ostream&	operator<<(std::ostream& os, const VEC& v);

#endif