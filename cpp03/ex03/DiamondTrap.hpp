/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:47:50 by jeada-si          #+#    #+#             */
/*   Updated: 2024/08/28 12:15:23 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DIAMONDTRAP_H__
# define __DIAMONDTRAP_H__
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap
{
	private:
		std::string		_name;
		void			constructorLog(std::string log);
	public:
						DiamondTrap();
						DiamondTrap(std::string name);
						DiamondTrap(const DiamondTrap &src);
						~DiamondTrap();
		DiamondTrap&	operator=(const DiamondTrap &src);
		void			whoAmI(void);
		void			displayStats(void);
};

#endif