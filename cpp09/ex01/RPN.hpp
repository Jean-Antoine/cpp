/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:22:45 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/25 15:09:13 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RPN_HPP__
# define __RPN_HPP__
# include <string>
# include <iostream>
# include <iomanip>
# include <stack>
# include <exception>
# define GREEN  "\e[1;32m"
# define YELLOW "\e[1;33m"
# define RED    "\e[1;31m"
# define BLUE   "\e[1;34m"
# define PINK   "\e[1;35m"
# define RESET  "\e[0m"

class RPN
{
	private:
		std::stack<char>		_s;
		class InputError: public std::exception
		{
			const char*	what() const throw();
		};
	public:
								RPN();
								RPN(std::string str);
								RPN(const RPN &src);
								~RPN();
		float					compute() const;
		float					recursive(std::stack<char>& stack) const;
		RPN&					operator=(const RPN &src);
};

#endif