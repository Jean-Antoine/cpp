/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 15:31:53 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/26 16:20:43 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SPAN_HPP__
# define __SPAN_HPP__
# include <string>
# include <iostream>
# include <iomanip>
# include <set>
# include <exception>
# include <algorithm>
# include <vector>
# define GREEN  "\e[1;32m"
# define YELLOW "\e[1;33m"
# define RED    "\e[1;31m"
# define BLUE   "\e[1;34m"
# define PINK   "\e[1;35m"
# define RESET  "\e[0m"

typedef std::multiset<int>::const_iterator CONST_ITER;

class Span
{
	private:
		unsigned long		_n;
		std::multiset<int>	_mlts;
		class SpanFull: public std::exception
		{
			char const*	what() const throw();
		};
		class NotEnoughElements: public std::exception
		{
			char const*	what() const throw();
		};
		class NotEnoughSpaceLeft: public std::exception
		{
			char const*	what() const throw();
		};
		void				checkSpan() const;
	public:
							Span();
							Span(unsigned long n);
							Span(const Span &src);
							~Span();
		Span&				operator=(const Span &src);
		void				addNumber(int i);
		template<typename T>
		void				addNumber(T begin, T end);
		void				print(void) const;
		unsigned int		shortestSpan() const;
		unsigned int		longestSpan() const;
		int					anyDuplicate() const;
};

template<typename T>
void	Span::addNumber(T begin, T end)
{
	if ((unsigned int) std::distance(begin, end) > (_n - _mlts.size()))
		throw(Span::NotEnoughSpaceLeft());
	_mlts.insert(begin, end);
}

#endif