/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FromCharacter.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 08:48:09 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/17 10:32:15 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FROMCHARACTER_HPP__
# define __FROMCHARACTER_HPP__
# include <string>
# include <iostream>
# include <iomanip>
# define GREEN  "\e[1;32m"
# define YELLOW "\e[1;33m"
# define RED    "\e[1;31m"
# define BLUE   "\e[1;34m"
# define PINK   "\e[1;35m"
# define RESET  "\e[0m"
# include "From.hpp"

class FromCharacter: public From
{
	protected:
		int						isIt() const;
	public:
								FromCharacter();
								FromCharacter(std::string s);
								FromCharacter(const FromCharacter &src);
								~FromCharacter();
		FromCharacter&	operator=(const FromCharacter &src);
		int						print() const;
		
};

#endif