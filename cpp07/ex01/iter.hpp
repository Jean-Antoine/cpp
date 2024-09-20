/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:42:37 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/20 13:40:02 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ITER_HPP__
# define __ITER_HPP__
# include <iomanip>
# include <iostream>

template<typename T>
void	iter(T* array, unsigned int n, void (*f)(T&))
{
	for (unsigned int i = 0; i < n; i++)
		f(array[i]);
}

#endif