/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:14:37 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/03 11:23:24 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ANIMAL_H__
# define __ANIMAL_H__
# include <string>
# define GREEN  "\e[1;32m"
# define YELLOW "\e[1;33m"
# define RED    "\e[1;31m"
# define BLUE   "\e[1;34m"
# define PINK   "\e[1;35m"
# define RESET  "\e[0m"
# define VERBOSE 1

class Animal
{
	protected:
		std::string		_type;
	public:
						Animal();
						Animal(const Animal &src);
		virtual			~Animal();
		Animal&			operator=(const Animal &src);
		std::string		getType(void) const;
		virtual void	makeSound(void) const;
};

#endif