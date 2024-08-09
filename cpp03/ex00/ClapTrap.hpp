/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:42:55 by jeada-si          #+#    #+#             */
/*   Updated: 2024/08/08 11:07:34 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CLAPTRAP_H__
# define __CLAPTRAP_H__
# include <iostream>
# define GREEN	"\e[1;32m"
# define YELLOW	"\e[1;33m"
# define RED	"\e[1;31m"
# define BLUE	"\e[1;34m"
# define PINK	"\e[1;35m"
# define RESET	"\e[0m"

class ClapTrap
{
	private:
		std::string			_name;
		unsigned int		_energyPts;
		unsigned int		_hitPts;
		unsigned int		_attackDamage;
		void				constructorLog(std::string log);
		void				displayEnergyPts(std::string log);
		bool				isDead(void);
		bool				isUnable(void);
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &src);
		ClapTrap& operator=(const ClapTrap &src);
		~ClapTrap();
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif