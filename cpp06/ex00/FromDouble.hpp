/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FromDouble.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:55:48 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/17 12:17:33 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FROMDOUBLE_HPP
# define __FROMDOUBLE_HPP
# include <string>
# include <iostream>
# include <iomanip>
# include "From.hpp"

class FromDouble: public From
{
	protected:
		int			isIt() const;
	public:
					FromDouble();
					FromDouble(std::string s);
					FromDouble(const FromDouble &src);
					~FromDouble();
		FromDouble&	operator=(const FromDouble &src);
		int			print() const;
};

#endif