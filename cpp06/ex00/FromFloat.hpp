/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FromFloat.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:13:45 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/17 11:14:25 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FROMFLOAT_HPP__
# define __FROMFLOAT_HPP__
# include <string>
# include <iostream>
# include <iomanip>
#include "From.hpp"

class FromFloat: public From
{
	protected:
		int			isIt() const;
	public:
					FromFloat();
					FromFloat(std::string s);
					FromFloat(const FromFloat &src);
					~FromFloat();
		FromFloat&	operator=(const FromFloat &src);
		int			print() const;
};

#endif