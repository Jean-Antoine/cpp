/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   From.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 08:45:34 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/17 11:02:45 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __From_HPP__
# define __From_HPP__
# define GREEN  "\e[1;32m"
# define YELLOW "\e[1;33m"
# define RED    "\e[1;31m"
# define BLUE   "\e[1;34m"
# define PINK   "\e[1;35m"
# define RESET  "\e[0m"
# include <string>
# include <iostream>
# include <iomanip>
# include "limits.h"

class From
{
	protected:
		std::string		_s;
		int				_isCharOverflow;
		int				_isIntOverflow;
		int				_isFloatOverflow;
		double			_d;
		int				isDisplayable(char c) const;
		int				isNan() const;
		int				isInf() const;
		virtual int		isIt() const = 0;
	public:
						From();
						From(std::string s);
						From(const From &src);
		virtual			~From();
		From&	operator=(const From &src);
		void			printChar(char c) const;
		void			printInt(int i) const;
		void			printFloat(float f) const;
		void			printDouble(double d) const;
		virtual int		print() const = 0;
};

int	isNum(char c);
#endif
