/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:54:53 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/18 08:55:20 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BASE_HPP__
# define __BASE_HPP__
# include <string>
# include <iostream>
# include <iomanip>

class Base
{
	public:
		virtual	~Base();
};

class A: public Base
{

};

class B: public Base
{

};

class C: public Base
{

};

#endif