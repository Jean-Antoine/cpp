/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:03:22 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/04 15:48:05 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FORM_HPP_
# define __FORM_HPP_
# include <string>
# include <iostream>
# include <iomanip>
# include <exception>
# define GREEN  "\e[1;32m"
# define YELLOW "\e[1;33m"
# define RED    "\e[1;31m"
# define BLUE   "\e[1;34m"
# define PINK   "\e[1;35m"
# define RESET  "\e[0m"
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const	_name;
		bool				_signed;
		int const			_gradeSign;
		int const			_gradeExec;
		class GradeTooHighException: public std::exception
		{
			const char*	what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			const char*	what() const throw();
		};
		void				checkGrade(int grade) const;
	public:
	//Constructors
							Form();
							Form(std::string name, int gradeSign, int gradeExec);
							Form(const Form &src);
							~Form();
		Form&				operator=(const Form &src);
	//Signing method
		void				beSigned(const Bureaucrat &bureaucrat);
	//Getters
		bool				isSigned(void) const;
		std::string			getName(void) const;
		int					getGradeExec(void) const;
		int					getGradeSign(void) const;
};

std::ostream&	operator<<(std::ostream &os, Form &form);

#endif