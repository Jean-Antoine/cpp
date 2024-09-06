/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:03:22 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/04 15:48:05 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __AForm_HPP_
# define __AForm_HPP_
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

class AForm
{
	private:
		std::string const	_name;
		bool				_signed;
		int const			_gradeSign;
		int const			_gradeExec;
		std::string const	_target;
		void				checkGrade(int grade) const;		
	public:
	//Constructors
							AForm();
							AForm(std::string name, std::string target,
								int gradeSign, int gradeExec);
							AForm(const AForm &src);
		virtual				~AForm();
		AForm&				operator=(const AForm &src);
	//Methods
		void				beSigned(const Bureaucrat &bureaucrat);
		void				execute(const Bureaucrat &executor) const;
		virtual void		executeSpecific(void) const = 0;
	//Getters
		bool				isSigned(void) const;
		std::string			getName(void) const;
		std::string			getTarget(void) const;
		int					getGradeExec(void) const;
		int					getGradeSign(void) const;
	//Setters
		void				setSigned(bool value);
	protected:
		class GradeTooHighException: public std::exception
		{
			const char*	what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			const char*	what() const throw();
		};
		class FormNotSignedException: public std::exception
		{
			const char* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream &os, AForm &AForm);

#endif