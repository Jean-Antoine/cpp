/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 13:56:04 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/03 15:19:13 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

void	nextScope(std::string title)
{
	std::cout << RED << std::setfill('-') << std::setw(70);
	std::cout << title << RESET << std::endl;
}

void	instruction(std::string title)
{
	std::cout << PINK << std::setfill('-') << std::setw(50);
	std::cout << title << RESET << std::endl;
}

int	main()
{
	nextScope("MATERIAS");
	{
		AMateria*	i = new	Ice();
		AMateria*	c = new	Cure();
		AMateria*	clone = c->clone();
		Character	unknown;
		
		i->use(unknown);
		c->use(unknown);
		clone->use(unknown);
		*i = *c;
		i->use(unknown);
		delete i;
		delete c;
		delete clone;
	}
		
	nextScope("CHARACTER");
	{
		Character	bob("bob");
		Character	vickos("vickos");

		bob.equip(new Ice());
		bob.equip(new Ice());
		bob.equip(new Cure());
		bob.equip(new Cure());
		bob.equip(new Cure());
		bob.equip(new Cure());
		{
			instruction("Deep copy");
			Character	copy = Character(bob);
		}
		bob.use(2, vickos);
		bob.equip(new Cure());
		bob.unequip(0);
		bob.unequip(0);
		vickos.equip(new Cure());
		vickos.equip(new Cure());
		instruction("Assignement");
		vickos = bob;
		vickos.unequip(0);
		bob.use(1, vickos);
		bob.use(1, vickos);
		vickos.use(1, bob);
		vickos.use(1, bob);
	}
	
	nextScope("SOURCE");
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Cure());
		src->learnMateria(new Cure());
		src->learnMateria(new Cure());
		{
			instruction("Deep copy");
			MateriaSource copy = MateriaSource(*((MateriaSource*) src));
			MateriaSource assign = *((MateriaSource*) src);
		}
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		instruction("No problem using the original after copy destruction");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
	}
}
