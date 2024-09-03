/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:23:03 by jeada-si          #+#    #+#             */
/*   Updated: 2024/08/29 12:23:06 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{	
	if(VERBOSE)
		std::cout << BLUE "[Dog   ] Default constructor called" RESET << std::endl;
	_type = "Dog";
	_brain = new Brain;
}

Dog::Dog(const Dog &src)
{
	if(VERBOSE)
		std::cout << BLUE "[Dog   ] Copy constructor called" RESET << std::endl;
	_brain = new Brain(*(src._brain));
	_type = src._type;
}

Dog& Dog::operator=(const Dog &src)
{
	if(VERBOSE)
		std::cout << BLUE "[Dog   ] Assignment operator called" RESET << std::endl;
	*(_brain) = *(src._brain);
	_type = src._type;
	return *this;
}
Dog::~Dog()
{
	if(VERBOSE)
		std::cout << BLUE "[Dog   ] Destructor called" RESET << std::endl;
	if (this->_brain)
		delete this->_brain;
}

void		Dog::makeSound(void) const
{
	std::cout << "Woof !" << std::endl;
}

void		Dog::setIdea(unsigned int i, std::string idea) const
{
	this->_brain->setIdea(i, idea);
}

void		Dog::getIdea(unsigned int i) const
{
	this->_brain->getIdea(i);
}