/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:48:11 by jeada-si          #+#    #+#             */
/*   Updated: 2024/08/09 15:44:04 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __AMATERIA_HPP__
# define __AMATERIA_HPP__
# include "Character.hpp"
# include <string>
# include <iostream>
# include <iomanip>
# define GREEN  "\e[1;32m"
# define YELLOW "\e[1;33m"
# define RED    "\e[1;31m"
# define BLUE   "\e[1;34m"
# define PINK   "\e[1;35m"
# define RESET  "\e[0m"
# include "Character.hpp"

class Character;

class AMateria
{
	protected:
		std::string			_type;
	public:
							AMateria();
							AMateria(std::string const &type);
							AMateria(const AMateria &src);
		AMateria& 			operator=(const AMateria &src);
		virtual				~AMateria();
		virtual void		use(Character& target);
		virtual AMateria*	clone() const = 0;
		std::string const&	getType() const;
};

#endif