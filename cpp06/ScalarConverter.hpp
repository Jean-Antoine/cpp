/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:26:17 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/06 10:52:01 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCALARCONVERTER_HPP__
# define __SCALARCONVERTER_HPP__
# include <string>
# include <iostream>
# include <iomanip>
# define GREEN  "\e[1;32m"
# define YELLOW "\e[1;33m"
# define RED    "\e[1;31m"
# define BLUE   "\e[1;34m"
# define PINK   "\e[1;35m"
# define RESET  "\e[0m"

class ScalarConverter
{
	private:
		bool				isCharacter(std::string s);
							ScalarConverter();
							ScalarConverter(const ScalarConverter &src);
							~ScalarConverter();
		ScalarConverter&	operator=(const ScalarConverter &src);
	public:
		static void			convert(std::string s);
};

#endif