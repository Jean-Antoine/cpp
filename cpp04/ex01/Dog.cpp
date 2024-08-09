/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:23:03 by jeada-si          #+#    #+#             */
/*   Updated: 2024/08/09 11:34:10 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
	_type = "Dog";
	_brain = new Brain;
	std::cout << BLUE "[Dog   ] Default constructor called" RESET << std::endl;
}

Dog::Dog(const Dog &src)
{
	_brain = new Brain(*(src._brain));
	_type = src._type;
	std::cout << BLUE "[Dog   ] Copy constructor called" RESET << std::endl;
}

Dog& Dog::operator=(const Dog &src)
{
	*(_brain) = *(src._brain);
	_type = src._type;
	std::cout << BLUE "[Dog   ] Assignment operator called" RESET << std::endl;
	return *this;
}
Dog::~Dog()
{
	if (this->_brain)
		delete this->_brain;
	std::cout << BLUE "[Dog   ] Destructor called" RESET << std::endl;
}

void		Dog::makeSound(void) const
{
	std::cout << "Woof !" << std::endl;
}

void		Dog::setIdea(unsigned int i, std::string idea) const
{
	this->_brain->setIdea(i, idea);
};

void		Dog::getIdea(unsigned int i) const
{
	this->_brain->getIdea(i);
};