/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:38:19 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/05 14:55:51 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PRESIDENTIALPARDONFORM_HPP__
# define __PRESIDENTIALPARDONFORM_HPP__
# include <string>
# include <iostream>
# include <iomanip>
# define GREEN  "\e[1;32m"
# define YELLOW "\e[1;33m"
# define RED    "\e[1;31m"
# define BLUE   "\e[1;34m"
# define PINK   "\e[1;35m"
# define RESET  "\e[0m"
# include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	private:
								
	public:
								PresidentialPardonForm();
								PresidentialPardonForm(std::string target);
								PresidentialPardonForm(const PresidentialPardonForm &src);
								~PresidentialPardonForm();
		PresidentialPardonForm&	operator=(const PresidentialPardonForm &src);
		void					executeSpecific(void) const;
};

#endif