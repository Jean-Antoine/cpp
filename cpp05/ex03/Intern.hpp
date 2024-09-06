/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 12:52:10 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/05 13:09:14 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __INTERN_HPP__
# define __INTERN_HPP__
# include <string>
# include <iostream>
# include <iomanip>
# define GREEN  "\e[1;32m"
# define YELLOW "\e[1;33m"
# define RED    "\e[1;31m"
# define BLUE   "\e[1;34m"
# define PINK   "\e[1;35m"
# define RESET  "\e[0m"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
	private:
		class FormDoesNotExistsException: public std::exception
		{
			const char*	what(void) const throw();
		};
	public:
				Intern();
				Intern(const Intern &src);
				~Intern();
		Intern&	operator=(const Intern &src);
		AForm*	makePresidentialPardonForm(std::string target);
		AForm*	makeRobotomyRequestForm(std::string target);
		AForm*	makeShrubberyCreationForm(std::string target);
		AForm*	makeForm(std::string formName, std::string target);
};

#endif