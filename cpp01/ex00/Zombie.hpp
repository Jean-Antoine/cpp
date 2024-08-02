/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:03:16 by jeada-si          #+#    #+#             */
/*   Updated: 2024/07/31 12:15:53 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H
# include <string>
# include <iostream>

class Zombie
{
private:
	std::string	name;	
public:
	Zombie(std::string name);
	~Zombie();
	void		announce(void);
};

Zombie*		newZombie(std::string name);
void		randomChump(std::string name);

#endif