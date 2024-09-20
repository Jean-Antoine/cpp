/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:26:33 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/20 11:55:11 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MUTANTSTACK_HPP__
# define __MUTANTSTACK_HPP__ 
# include <string>
# include <iostream>
# include <iomanip>
# include <stack>
# define GREEN  "\e[1;32m"
# define YELLOW "\e[1;33m"
# define RED    "\e[1;31m"
# define BLUE   "\e[1;34m"
# define PINK   "\e[1;35m"
# define RESET  "\e[0m"

template <class T>
class MutantStack: public std::stack<T>
{	
	public:
	    typedef typename std::stack<T>::container_type::iterator		iterator;
        typedef typename std::stack<T>::container_type::const_iterator	const_iterator;
						MutantStack();
						MutantStack(const MutantStack &src);
						~MutantStack();
		MutantStack&	operator=(const MutantStack &src);
		iterator		begin();
		iterator		end();
		const_iterator	cbegin();
		const_iterator	cend();
};
# include "MutantStack.tpp"

#endif