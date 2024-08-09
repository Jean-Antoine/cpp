/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:20:36 by jeada-si          #+#    #+#             */
/*   Updated: 2024/08/09 11:23:06 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DOG_H__
# define __DOG_H__
# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal
{
	private:
		Brain*	_brain;
	public:
		Dog();
		Dog(const Dog &src);
		Dog& operator=(const Dog &src);
		~Dog();
		virtual void	makeSound(void) const;
		void			setIdea(unsigned int i, std::string idea) const;
		void			getIdea(unsigned int i) const;
};

#endif
