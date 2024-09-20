/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:40:29 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/19 11:12:04 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ARRAY_HPP__
# define __ARRAY_HPP__
# include <string>
# include <iostream>
# include <iomanip>
# include <exception>
# define GREEN  "\e[1;32m"
# define YELLOW "\e[1;33m"
# define RED    "\e[1;31m"
# define BLUE   "\e[1;34m"
# define PINK   "\e[1;35m"
# define RESET  "\e[0m"

template<class T>
class Array
{
	private:
		unsigned int	_n;
		T				*_array;
		class IndexOutOfBounds: public std::exception
		{
			public:
				const char*	what() const throw();
		};
		void			allocate();
		void			free();
		void			copy(const Array<T>& src);
	public:
						Array();
						Array(unsigned int n);
						~Array();
						Array(const Array<T>& src);
		Array<T>&		operator=(const Array<T> &src);
		unsigned int	size() const;
		T&				operator[](unsigned int i) const;
};

template <class T>
std::ostream&		operator<<(std::ostream& os, Array<T> obj);
#include "Array.tpp"

#endif
