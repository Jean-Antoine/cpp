/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:26:24 by jeada-si          #+#    #+#             */
/*   Updated: 2024/08/09 13:47:03 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	Animal* array[10];

	for (int i = 0; i < 5; i++)
		array[i] = new Dog;
	for (int i = 5; i < 10; i++)
		array[i] = new Cat;
	for (int i = 0; i < 10; i++)
		delete array[i];

	Dog dog = Dog();
	dog.setIdea(0, "Let's get drunk !");
	Dog copy = Dog(); copy = dog;
	// Dog copy = Dog(dog);
	std::cout << YELLOW ">> Same idea after copying :";
	std::cout << RESET << std::endl;
	dog.getIdea(0);
	copy.getIdea(0);
	copy.setIdea(0, "NO !");
	std::cout << YELLOW ">> Changing one doesnt change ";
	std::cout << "the other i.e. deep copy" RESET << std::endl;
	dog.getIdea(0);
	copy.getIdea(0);
	return 0;
}
