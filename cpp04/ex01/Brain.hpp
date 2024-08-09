/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:19:20 by jeada-si          #+#    #+#             */
/*   Updated: 2024/08/08 17:53:55 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BRAIN_H__
# define __BRAIN_H__
# include <string>
# include <iostream>

class Brain
{
	private:
		std::string		_idea[100];
	public:
		Brain();
		Brain(const Brain &src);
		Brain& operator=(const Brain &src);
		~Brain();
		void	setIdea(unsigned int i, std::string idea);
		void	getIdea(unsigned int i) const;
};

#endif