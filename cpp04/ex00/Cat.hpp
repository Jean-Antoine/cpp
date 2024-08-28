/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:18:44 by jeada-si          #+#    #+#             */
/*   Updated: 2024/08/09 11:11:19 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CAT_H__
# define __CAT_H__
# include "Animal.hpp"

class Cat: public Animal
{
	public:
						Cat();
						Cat(const Cat &src);
						~Cat();
		Cat&			operator=(const Cat &src);
		virtual void	makeSound(void) const;
};

#endif