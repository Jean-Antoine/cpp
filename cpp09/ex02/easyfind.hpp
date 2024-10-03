/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:35:21 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/19 15:59:26 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __EASYFIND_HPP__
# define __EASYFIND_HPP__
# include <exception>
# include <cstdlib>
# include <algorithm>

class NotFound: public std::exception
{
	char const*	what() const throw();
};

template <typename T>
int	easyfind(T v, int i)
{
	typename T::iterator	out = std::find(v.begin(), v.end(), i);

	if (out == v.end())
		throw(NotFound());
	return std::distance(v.begin(), out);
}

#endif