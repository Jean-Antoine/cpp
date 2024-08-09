/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 13:58:28 by jeada-si          #+#    #+#             */
/*   Updated: 2024/08/09 15:42:36 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CHARACTER_HPP__
# define __CHARACTER_HPP__
# include <string>
# include <iostream>
# include <iomanip>
# define GREEN  "\e[1;32m"
# define YELLOW "\e[1;33m"
# define RED    "\e[1;31m"
# define BLUE   "\e[1;34m"
# define PINK   "\e[1;35m"
# define RESET  "\e[0m"
# include "ICharacter.hpp"

class Character: public ICharacter
{
	protected:
		std::string				_name;
		AMateria*				_inventory[4];
	private:
		void					setInventoryNull(void);
		void					copyInventory(const Character &src);
		void					purgeInventory(void);
	public:
								Character();
								Character(std::string name);
								Character(const Character &src);
		Character&				operator=(const Character &src);
								~Character();
		std::string const &		getName() const;
		void					equip(AMateria* m);
		void					unequip(int idx);
		void					use(int idx, Character& target);
};

#endif