/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:03:25 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/27 13:25:55 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BITCOINEXCHANGE_HPP__
# define __BITCOINEXCHANGE_HPP__
# include <string>
# include <iostream>
# include <iomanip>
# include <map>
# include <fstream>
# include <cstdlib>
# define GREEN  "\e[1;32m"
# define YELLOW "\e[1;33m"
# define RED    "\e[1;31m"
# define BLUE   "\e[1;34m"
# define PINK   "\e[1;35m"
# define RESET  "\e[0m"

typedef std::map<time_t, float> MAP;

class BitcoinExchange
{
	private:
		MAP					_prices;
							BitcoinExchange();
	public:		
							BitcoinExchange(std::ifstream &in);
							BitcoinExchange(const BitcoinExchange &src);
							~BitcoinExchange();
		BitcoinExchange&	operator=(const BitcoinExchange &src);
		float				lastPrice(time_t date) const;
		void				compute(std::ifstream &in) const;
};

#endif