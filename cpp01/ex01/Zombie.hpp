/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:03:16 by jeada-si          #+#    #+#             */
/*   Updated: 2024/07/31 14:57:38 by jeada-si         ###   ########.fr       */
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
	Zombie();
	Zombie(std::string name);
	~Zombie();
	void		setName(std::string name);
	void		announce(void);
};

Zombie*		zombieHorde(int N, std::string name);
#endif