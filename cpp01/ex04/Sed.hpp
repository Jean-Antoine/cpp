/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:03:12 by jeada-si          #+#    #+#             */
/*   Updated: 2024/08/01 17:04:42 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SED_H__
# define __SED_H__
# include <iostream>
# include <fstream>
# include <string>

class Sed
{
	private:
		std::string		_s1;
		std::string		_s2;
		std::ifstream	_in;
		std::ofstream	_out;		
	public:
		Sed(std::string filename, std::string s1, std::string s2);
		~Sed();
		int			replace(void);
};

#endif