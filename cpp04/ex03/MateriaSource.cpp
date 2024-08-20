/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:49:04 by jeada-si          #+#    #+#             */
/*   Updated: 2024/08/20 16:33:15 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
	_idx = 0;
	std::cout << BLUE "[MateriaSource] Default constructor called" RESET << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
	this->copy(src._idx, src._source);
	std::cout << BLUE "[MateriaSource] Copy constructor called" RESET << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource &src)
{
	this->purge();
	this->copy(src._idx, src._source);
	std::cout << BLUE "[MateriaSource] Assignment operator called" RESET << std::endl;
	return *this;
}

MateriaSource::~MateriaSource()
{
	this->purge();
	std::cout << BLUE "[MateriaSource] Destructor called" RESET << std::endl;
}

void		MateriaSource::purge(void)
{
	if (!_idx)
		return ;
	for (int i = 0; i < _idx; i++)
		delete _source[i];
	_idx = 0;
}

void		MateriaSource::copy(int idx, AMateria* const source[4])
{
	_idx = idx;
	if (!idx)
		return ;
	for (int i = 0; i < idx; i++)
		_source[i] = source[i];
}

void		MateriaSource::learnMateria(AMateria* m)
{
	if (_idx >= MAX_MATERIA)
	{
		delete m;
		std::cout << RED "Source cannot learn more than ";
		std::cout << MAX_MATERIA <<" materias.";
		std::cout << RESET << std::endl;
		return ;
	}
	std::cout << PINK "Source just learnt type ";
	std::cout << m->getType() << "!";
	std::cout << RESET << std::endl;
	_source[_idx++] = m;	
}

AMateria*	MateriaSource::createMateria(std::string const& type)
{
	for (int i = 0; i < _idx; i++)
	{
		AMateria*	m = _source[i];
		if (!type.compare(m->getType()))
			return (m->clone());
	}
	std::cout << RED "Unknown type " << type << ".";
	std::cout << RESET << std::endl;
	return NULL;
}
