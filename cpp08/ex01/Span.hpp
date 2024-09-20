/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 15:31:53 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/20 09:34:49 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SPAN_HPP__
# define __SPAN_HPP__
# include <string>
# include <iostream>
# include <iomanip>
# include <vector>
# include <exception>
# include <algorithm>
# define GREEN  "\e[1;32m"
# define YELLOW "\e[1;33m"
# define RED    "\e[1;31m"
# define BLUE   "\e[1;34m"
# define PINK   "\e[1;35m"
# define RESET  "\e[0m"

typedef	std::vector<int>::const_iterator CONST_ITER;
class Span
{
	private:
		unsigned long		_n;
		std::vector<int>	_v;
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
		void				addRange(CONST_ITER begin, CONST_ITER end);
		void				print(void) const;
		int					shortestSpan() const;
		int					longestSpan() const;
		int					anyDuplicate() const;
};

#endif