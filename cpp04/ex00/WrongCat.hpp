/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:18:44 by jeada-si          #+#    #+#             */
/*   Updated: 2024/08/08 16:59:04 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WRONGCAT_H__
# define __WRONGCAT_H__
# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{	
	public:
					WrongCat();
					WrongCat(const WrongCat &src);
					~WrongCat();
		WrongCat&	operator=(const WrongCat &src);
		void		makeSound(void) const;
};

#endif