/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:26:17 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/17 12:18:25 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCALARCONVERTER_HPP__
# define __SCALARCONVERTER_HPP__
# include <string>
# include <iostream>
# include <iomanip>
# include "FromCharacter.hpp"
# include "FromInt.hpp"
# include "FromFloat.hpp"
# include "FromDouble.hpp"

class ScalarConverter
{
	private:
							ScalarConverter();
							ScalarConverter(const ScalarConverter &src);
							~ScalarConverter();
		ScalarConverter&	operator=(const ScalarConverter &src);
	public:
		static void			convert(std::string s);
};

#endif