/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:02:33 by jeada-si          #+#    #+#             */
/*   Updated: 2024/08/02 12:05:55 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <string>

Harl::Harl()
{
	complaintsLevels[0] = "DEBUG";
	complaintsLevels[1] = "INFO";
	complaintsLevels[2] = "WARNING";
	complaintsLevels[3] = "ERROR";
}

Harl::~Harl()
{
}

void	Harl::debug(void)
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese"
		"-triple-pickle-specialketchup burger. I really do!" << std::endl;
	return ;
}

void	Harl::info(void)
{
	std::cout << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. "
		"You didn’t put enough bacon in my burger! "
		"If you did, I wouldn’t be asking for more!" << std::endl;
	return ;
}

void	Harl::warning(void)
{
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. "
		"I’ve been coming for years whereas you started "
		"working here since last month." << std::endl;
	return ;
}

void	Harl::error(void)
{
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable!"
		" I want to speak to the manager now." << std::endl;
	return ;
}

void	Harl::complain(std::string level)
{
	void	(Harl::*func[])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	
	for (int i = 0; i < 4; i++)
	{
		if (level == complaintsLevels[i])
			return ((this->*func[i])());
	}
	std::cout << "[Wrong complaint level]" << std::endl;
	return ;
}
