/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:32:21 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/05 12:23:56 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	ShrubberyCreationForm	sform("GreenPeace");
	RobotomyRequestForm		rform("IRobot");
	PresidentialPardonForm	pform("Jacqueline Sauvage");
	Bureaucrat				julien("Julien", 100);
	Bureaucrat				vincent("Vincent", 45);
	Bureaucrat				president("President", 1);
	
	julien.executeForm(sform);
	julien.signForm(sform);
	julien.executeForm(sform);
	julien.signForm(rform);
	vincent.executeForm(rform);
	vincent.signForm(rform);
	vincent.executeForm(rform);
	vincent.executeForm(rform);
	vincent.executeForm(rform);
	president.signForm(pform);
	president.executeForm(pform);
}
