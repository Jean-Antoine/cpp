/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:42:06 by jeada-si          #+#    #+#             */
/*   Updated: 2024/08/20 15:18:41 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MateriaSource_HPP__
# define __MateriaSource_HPP__
# include <string>
# include <iostream>
# include <iomanip>
# define GREEN  "\e[1;32m"
# define YELLOW "\e[1;33m"
# define RED    "\e[1;31m"
# define BLUE   "\e[1;34m"
# define PINK   "\e[1;35m"
# define RESET  "\e[0m"
# include "IMateriaSource.hpp"
# define MAX_MATERIA 4

class MateriaSource: public IMateriaSource
{
	private:
		AMateria*		_source[MAX_MATERIA];
		int				_idx;
		void			purge(void);
		void			copy(int idx, AMateria* const source[MAX_MATERIA]);
	public:
						MateriaSource();
						MateriaSource(const MateriaSource &src);
		MateriaSource&	operator=(const MateriaSource &src);
						~MateriaSource();
		void			learnMateria(AMateria*);
		AMateria*		createMateria(std::string const & type);
};

#endif