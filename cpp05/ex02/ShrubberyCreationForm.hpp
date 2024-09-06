/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:01:16 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/05 14:56:20 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SHRUBBERYCREATIONFORM_HPP__
# define __SHRUBBERYCREATIONFORM_HPP__
# include "AForm.hpp"
# include <string>
# include <iostream>
# include <iomanip>
# define GREEN  "\e[1;32m"
# define YELLOW "\e[1;33m"
# define RED    "\e[1;31m"
# define BLUE   "\e[1;34m"
# define PINK   "\e[1;35m"
# define RESET  "\e[0m"

class ShrubberyCreationForm: public AForm
{
	private:
		class FileWrittingException: public std::exception
		{
			const char*	what(void) const throw();
		};
	public:
								ShrubberyCreationForm();
								ShrubberyCreationForm(std::string const target);
								ShrubberyCreationForm(const ShrubberyCreationForm &src);
								~ShrubberyCreationForm();
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm &src);
		void					executeSpecific(void) const;
};

#endif