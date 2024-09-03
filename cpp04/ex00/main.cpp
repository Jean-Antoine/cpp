/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:26:24 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/03 15:10:33 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();	
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << PINK "Animal pointer to a Cat: " RESET;
	i->makeSound();
	std::cout << PINK "Animal pointer to a Dog: " RESET;
	j->makeSound();
	std::cout << PINK "Animal pointer to an Animal: " RESET;
	meta->makeSound();
	delete meta;
	delete i;
	delete j;

	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();
	const WrongCat*	wrongCatRight = new WrongCat();
	std::cout << wrongMeta->getType() << " " << std::endl;
	std::cout << wrongCat->getType() << " " << std::endl;
	std::cout << PINK "WrongAnimal pointer to a WrongAnimal: " RESET;
	wrongMeta->makeSound();
	std::cout << PINK "WrongAnimal pointer to a WrongCat: " RESET;
	wrongCat->makeSound();
	std::cout << PINK "WrongCat pointer to a WrongCat: " RESET;
	wrongCatRight->makeSound();
	delete wrongCat;
	delete wrongMeta;
	delete wrongCatRight;
	return 0;
}
