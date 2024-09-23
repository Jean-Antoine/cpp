/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 09:50:15 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/23 08:56:24 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <time.h>
#include <cstdlib>

int	main(void)
{
	Array<int>	A(10);
	for (unsigned int i = 0; i < A.size(); i++)
		A[i] = i;
	Array<int>	A_cpy(A);
	Array<int>	B = A;
	std::cout << "A is\t\t" << A << std::endl;
	std::cout << "A_cpy is\t" << A_cpy << std::endl;
	std::cout << "B is\t\t" << B << std::endl;
	std::cout << BLUE "Modifying A" RESET << std::endl;
	for (unsigned int i = 0; i < A.size(); i++)
		A[i] = i * i;
	std::cout << "A is\t\t" << A << std::endl;
	std::cout << "A_cpy is\t" << A_cpy << std::endl;
	std::cout << "B is\t\t" << B << std::endl;
	std::cout << BLUE "Modifying B" RESET << std::endl;
	for (unsigned int i = 0; i < A.size(); i++)
		B[i] = i * 2;
	std::cout << "A is\t\t" << A << std::endl;
	std::cout << "A_cpy is\t" << A_cpy << std::endl;
	std::cout << "B is\t\t" << B << std::endl;
	std::cout << BLUE "Trying to access A[10]" << std::endl;
	try
	{
		A[10];
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}	
}

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }