/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:03:44 by jeada-si          #+#    #+#             */
/*   Updated: 2024/10/07 08:41:43 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

static void	initTm(struct tm* date)
{
	date->tm_sec = 0;
	date->tm_min = 0;
	date->tm_hour = 0;
	date->tm_mday = 0;
	date->tm_mon = 0;
	date->tm_year = 0;
	date->tm_wday = 0;
	date->tm_yday = 0;
	date->tm_isdst = 0;
}

static struct tm	parseDate(std::string str)
{
	struct tm	date;
	
	initTm(&date);
	str.append(" 12:00:00");
	strptime(str.data(), "%Y-%m-%d %H:%M:%S", &date);
	return date;
}

static int			isValidDate(std::string str)
{
	time_t		now = time(0);
	time_t		date_t;
	struct tm	date;
	char		buffer[90];

	initTm(&date);
	date = parseDate(str);
	strptime(str.data(), "%Y-%m-%d %H:%M:%S", &date);
	date_t = mktime(&date);
	strftime(buffer, sizeof(buffer), "%Y-%m-%d", &date);
	if (str.compare(buffer))
		return false;
	if (date_t > now)
		return false;
	return true;
}

static int			isValidFloat(std::string str)
{
	unsigned int i = (str[0] == '+' || str[0] == '-');
	
	if (!str.size())
		return false;
	while (i < str.size())
	{	
		if (!isdigit(str[i]))
			break ;
		i++;
	}
	if (str[i] && str[i] != '.')
		return false;
	while (++i < str.size())
		if (!isdigit(str[i]))
			return false;
	return true;
}

static int			isValidLine(std::string str)
{
	std::string	pattern = "dddd-dd-dd | ";

	if (str.size() < pattern.size())
		return false;
	for (unsigned int i = 0; i < pattern.size(); i++)
	{
		if (pattern[i] == 'd')
		{
			if (!isdigit(str[i]))
			return false;
		}
		else if (str[i] != pattern[i])
			return false;
	}
	return isValidFloat(str.substr(pattern.size(), std::string::npos));
}

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(std::ifstream &in)
{
	std::string	line;
	
	std::getline(in, line);
	while (!in.eof())
	{
		struct tm			date_tm;
		time_t				date_t;
		float				value;

		initTm(&date_tm);
		std::getline(in, line, ',');
		if (!line.size())
			continue ;
		date_tm = parseDate(line);
		date_t = mktime(&date_tm);
		std::getline(in, line);
		value = std::atof(line.data());
		_prices[date_t] = value;
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	_prices = src._prices;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &src)
{
	_prices = src._prices;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

float	BitcoinExchange::lastPrice(time_t date) const
{
	MAP::const_iterator	lower = this->_prices.lower_bound(date);

	if (_prices.empty() || date < _prices.begin()->first)
		return -1;
	if (lower->first == date)
		return lower->second;
	lower--;
	return lower->second;
}

static void	error(std::string str)
{
	std::cout << RED "Error: " << str << RESET <<std::endl;
}

void	BitcoinExchange::compute(std::ifstream & in) const
{
	std::string	line;
	struct tm	date_tm;
	time_t		date;
	float		value;
	float		last;
	
	std::getline(in, line);
	if (line.compare("date | value"))
	{
		error("Wrong header");
		return ;
	}
	while (!in.eof())
	{
		std::getline(in, line);
		if (!line.size())
			continue ;
		std::cout << BLUE << std::left << std::setw(10);
		std::cout << line.substr(0, 10) << RESET " => ";
		if (!isValidLine(line))
		{
			error("bad input");
			continue;
		}
		if (!isValidDate(line.substr(0, 10)))
		{
			error("bad date");
			continue;
		}
		date_tm = parseDate(line.substr(0, 10));
		date = mktime(&date_tm);
		value = std::atof(line.substr(13, std::string::npos).data());
		if (value < 0)
		{
			error("not a positive number");
			continue;
		}
		if (value > 1000)
		{
			error("value higher than 1000");
			continue;
		}
		last = lastPrice(date);
		if (last == -1)
		{
			error("no history for that date");
			continue;
		}
		std::cout << value << " = ";
		std::cout << GREEN << last * value << RESET "\n";
	}
}
