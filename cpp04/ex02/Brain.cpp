/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:19:49 by jeada-si          #+#    #+#             */
/*   Updated: 2024/08/29 12:23:06 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>
#include "Animal.hpp"

Brain::Brain()
{
	if(VERBOSE)
		std::cout << BLUE "[Brain ] Default constructor called" RESET << std::endl;
}

Brain::Brain(const Brain &src)
{
	for (int i = 0; i < 100; i++)
		this->_idea[i] = src._idea[0];
	if(VERBOSE)
		std::cout << BLUE "[Brain ] Copy constructor called" RESET << std::endl;	
}


Brain& Brain::operator=(const Brain &src)
{
	for (int i = 0; i < 100; i++)
		this->_idea[i] = src._idea[0];
	if(VERBOSE)
		std::cout << BLUE "[Brain ] Assignment operator called" RESET << std::endl;
	return *this;
}


Brain::~Brain()
{
	if(VERBOSE)
		std::cout << BLUE "[Brain ] Destructor called" RESET << std::endl;
}

void	Brain::setIdea(unsigned int i, std::string idea)
{
	if (i > 100)
		return;
	this->_idea[i] = idea;
}

void	Brain::getIdea(unsigned int i) const
{
	if (i > 100)
	{
		std::cout << "A brain can t hold that many ideas\n.";
		return ;
	}
	std::cout << "Idea no." << i << ": " << this->_idea[i] << std::endl;
}
