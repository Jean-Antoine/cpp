/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:02:51 by jeada-si          #+#    #+#             */
/*   Updated: 2024/08/08 14:56:33 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FRAGTRAP_H__
# define __FRAGTRAP_H__
# include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
	private:
		void	constructorLog(std::string log);
	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(const FragTrap &src);
		FragTrap& operator=(const FragTrap &src);
		~FragTrap(void);
		void		highFiveGuys(void);
};

#endif