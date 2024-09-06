/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:51:04 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/05 14:38:07 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BUREAUCRAT_HPP__
# define __BUREAUCRAT_HPP__
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

class Bureaucrat
{
	private:
		std::string const	_name;
		int					_grade;
		class GradeTooHighException: public std::exception
		{
			const char*		what(void) const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
			const char*	what(void) const throw();
		};
		void				setGrade(int grade);
	public:
		//Constructors
							Bureaucrat();
							Bureaucrat(std::string const name, int const grade);
							Bureaucrat(const Bureaucrat &src);
							~Bureaucrat();
		Bureaucrat&			operator=(const Bureaucrat &src);
		//Accessors
		std::string			getName(void) const;
		int					getGrade(void) const;
		//Incr/Decr Methods
		void				incrGrade(void);
		void				decrGrade(void);
};

std::ostream&	operator<<(std::ostream& os, Bureaucrat& i);

#endif