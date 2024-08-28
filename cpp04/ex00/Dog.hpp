/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:20:36 by jeada-si          #+#    #+#             */
/*   Updated: 2024/08/09 11:11:24 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DOG_H__
# define __DOG_H__
# include "Animal.hpp"

class Dog: public Animal
{
	public:
						Dog();
						Dog(const Dog &src);
						~Dog();
		Dog&			operator=(const Dog &src);
		virtual void	makeSound(void) const;
};

#endif
