/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:42:55 by jeada-si          #+#    #+#             */
/*   Updated: 2024/08/28 11:59:30 by jeada-si         ###   ########.fr       */
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
	protected:
		std::string			_name;
		unsigned int		_energyPts;
		unsigned int		_hitPts;
		unsigned int		_attackDamage;
		void				displayEnergyPts(std::string prefix);
		bool				isDead(void);
		bool				isUnable(void);
	private:
		void				constructorLog(std::string log);
	public:
							ClapTrap();
							ClapTrap(std::string name);
							ClapTrap(const ClapTrap &src);
							~ClapTrap();
		ClapTrap&			operator=(const ClapTrap &src);
		void				displayStats(void);
		void				attack(const std::string& target);
		void				takeDamage(unsigned int amount);
		void				beRepaired(unsigned int amount);
};

#endif