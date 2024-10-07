/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:22:58 by jeada-si          #+#    #+#             */
/*   Updated: 2024/10/04 13:20:21 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

RPN::RPN()
{
}

RPN::RPN(std::string str)
{
	for (unsigned int i = 0; i < str.size(); i++)
		if (i % 2 == 0)
			_s.push(str[i]);
}

RPN::RPN(const RPN &src)
{
	(void) src;
}

RPN& RPN::operator=(const RPN &src)
{
	(void) src;
	return *this;
}

RPN::~RPN()
{
}

const char*	RPN::InputError::what() const throw()
{
	return "Error";
}

float		RPN::recursive(std::stack<char>& stack) const
{		
	char	c;
	float	left;
	float	right;
	
	if (!stack.size())
		throw(RPN::InputError());
	c = stack.top();
	stack.pop();
	if (isdigit(c))
		return c - '0';
	right = recursive(stack);
	left = recursive(stack);
	switch (c)
	{
	case '+':
		return left + right;
	case '-':
		return left - right;
	case '*':
		return left * right;
	case '/':
		return left / right;	
	default: throw(RPN::InputError());
		break;
	}
}

float	RPN::compute() const
{
	float				out;
	std::stack<char>	stack = _s;
	
	out = recursive(stack);
	if (!stack.empty())
		throw(RPN::InputError());
	return out;
}
