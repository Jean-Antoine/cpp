/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:20:53 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/17 14:29:03 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DATA_HPP__
# define __DATA_HPP__
# include <string>
# include <iostream>
# include <iomanip>
# define GREEN  "\e[1;32m"
# define YELLOW "\e[1;33m"
# define RED    "\e[1;31m"
# define BLUE   "\e[1;34m"
# define PINK   "\e[1;35m"
# define RESET  "\e[0m"

class Data
{
	private:
		std::string		_name;
		unsigned int	_age;
		float			_height;
	public:
						Data();
						Data(std::string name, unsigned int age, float height);
						Data(const Data &src);
						~Data();
		Data&			operator=(const Data &src);
		std::string		getName() const;
		unsigned int	getAge() const;
		float			getHeight() const;
};

std::ostream&	operator<<(std::ostream& os, Data& data);

#endif