/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:22:17 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/18 15:37:18 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <iomanip>

void	ft_string_print(std::string s)
{
	std::cout << "string is " << s << std::endl;
}

void	ft_int_print(int i)
{
	std::cout << "int is " << i << std::endl;
}

int	main(void)
{
	std::string	array_s[4] = {"test1", "test2", "test3", "test4"};
	int			array_i[4] = {1, 2, 3, 4};

	iter(array_s, 4, ft_string_print);
	iter(array_i, 4, ft_int_print);
}