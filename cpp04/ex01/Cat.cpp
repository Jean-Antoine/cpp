/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:20:16 by jeada-si          #+#    #+#             */
/*   Updated: 2024/08/09 13:48:02 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat()
{
	_brain = new Brain;
	_type = "Cat";
	std::cout << BLUE "[Cat   ] Default constructor called" RESET << std::endl;
}

Cat::Cat(const Cat &src)
{
	_brain = new Brain(*(src._brain));
	_type = src._type;
	std::cout << BLUE "[Cat   ] Copy constructor called" RESET << std::endl;
}

Cat& Cat::operator=(const Cat &src)
{
	*(_brain) = *(src._brain);
	_type = src._type;
	std::cout << BLUE "[Cat   ] Assignment operator called" RESET << std::endl;
	return *this;
}

Cat::~Cat()
{
	if (_brain)
		delete _brain;
	std::cout << BLUE "[Cat   ] Destructor called" RESET << std::endl;
}

void		Cat::makeSound(void) const
{
	std::cout << "Meow !" << std::endl;
}

void		Cat::setIdea(unsigned int i, std::string idea) const
{
	this->_brain->setIdea(i, idea);
};

void		Cat::getIdea(unsigned int i) const
{
	this->_brain->getIdea(i);
};