/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:14:37 by jeada-si          #+#    #+#             */
/*   Updated: 2024/08/08 16:48:57 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WRONGANIMAL_H__
# define __WRONGANIMAL_H__
# include <string>
# define GREEN  "\e[1;32m"
# define YELLOW "\e[1;33m"
# define RED    "\e[1;31m"
# define BLUE   "\e[1;34m"
# define PINK   "\e[1;35m"
# define RESET  "\e[0m"

class WrongAnimal
{
	protected:
		std::string		_type;
	public:
						WrongAnimal();
						WrongAnimal(const WrongAnimal &src);
		virtual			~WrongAnimal();
		WrongAnimal&	operator=(const WrongAnimal &src);
		std::string		getType(void) const;
		void			makeSound(void) const;
};

#endif