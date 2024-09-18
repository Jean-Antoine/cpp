/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:28:15 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/17 14:53:19 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"

int	main(void)
{
	Data*		t1 = new Data("JA", 30, 1.77);
	uintptr_t	raw;
	Data*		ptr;

	std::cout << *t1;
	raw = Serializer::serialize(t1);
	ptr = Serializer::deserialize(raw);
	std::cout << *ptr;
	delete t1;
}
