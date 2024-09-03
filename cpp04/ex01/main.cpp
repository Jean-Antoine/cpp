/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:26:24 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/03 14:55:05 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include <iostream>
#include <iomanip>

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

int main()
{
	nextScope("ARRAY");
	{
		Animal* array[10];
		instruction("1ST HALF ARE DOGS");
		for (int i = 0; i < 5; i++)
			array[i] = new Dog;
		instruction("1ST HALF ARE CATS");
		for (int i = 5; i < 10; i++)
			array[i] = new Cat;
		instruction("DELETING");
		for (int i = 0; i < 10; i++)
			delete array[i];
	}
	nextScope("DEEP COPY");
	{
		Dog dog = Dog();
		{
			instruction("Creating a copy creates a new brain i.e. deep copy");
			Dog tmp = dog;
		}
		dog.setIdea(0, "Let's get drunk !");
		// Dog copy = Dog(); copy = dog;
		instruction("Modifying brain after copy");
		Dog copy = Dog(dog);		
		std::cout << YELLOW ">> Same idea after copying";
		std::cout << RESET << std::endl;
		dog.getIdea(0);
		copy.getIdea(0);
		std::cout << YELLOW ">> Changing one doesnt change ";
		std::cout << "the other i.e. deep copy" RESET << std::endl;
		copy.setIdea(0, "NO !");		
		dog.getIdea(0);
		copy.getIdea(0);
	}
	return 0;
}
