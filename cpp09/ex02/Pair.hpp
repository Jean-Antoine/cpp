/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 08:39:36 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/27 10:11:32 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PAIR_HP__
# define __PAIR_HP__
# include <string>
# include <iostream>
# include <iomanip>
# define GREEN  "\e[1;32m"
# define YELLOW "\e[1;33m"
# define RED    "\e[1;31m"
# define BLUE   "\e[1;34m"
# define PINK   "\e[1;35m"
# define RESET  "\e[0m"

template <typename T>
class Pair
{
	private:
		T		_a;
		T		_b;
				Pair();
	public:
				Pair(T i, T j);
				Pair(const Pair &src);
				~Pair();
		Pair&	operator=(const Pair &src);
		bool	operator<=(const Pair &src);
		bool	operator>=(const Pair &src);
};
# include "Pair.tpp"

#endif