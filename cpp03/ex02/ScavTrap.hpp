/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:02:51 by jeada-si          #+#    #+#             */
/*   Updated: 2024/08/28 12:08:33 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCAVTRAP_H__
# define __SCAVTRAP_H__
# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	private:
		void		constructorLog(std::string log);
	public:
					ScavTrap(void);
					ScavTrap(std::string name);
					ScavTrap(const ScavTrap &src);
					~ScavTrap(void);
		ScavTrap&	operator=(const ScavTrap &src);
		void		attack(std::string target);
		void		guardGate(void);
};

#endif