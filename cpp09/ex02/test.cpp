/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 10:06:57 by jeada-si          #+#    #+#             */
/*   Updated: 2024/10/03 09:18:45 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include <algorithm>
typedef std::vector<int>	VEC;
typedef VEC::iterator		ITER;
typedef VEC::const_iterator	CONST_ITER;

int	main(void)
{
	std::vector<std::pair<int, int>> vec;
	
	vec.push_back(std::make_pair(1, 9));
	vec.push_back(std::make_pair(7, 7));
	vec.push_back(std::make_pair(6, 5));
	vec.push_back(std::make_pair(9, 9));
	vec.push_back(std::make_pair(1, 4));
	vec.push_back(std::make_pair(3, 8));

	for (unsigned int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i].first << ", " << vec[i].second << std::endl;
	}

	std::sort(vec.begin(), vec.end());
}
