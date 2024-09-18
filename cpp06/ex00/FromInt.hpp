/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FromInt.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 10:08:18 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/17 10:56:22 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FROMINT_HPP__
# define __FROMINT_HPP__
# include <string>
# include <iostream>
# include <iomanip>
# include "From.hpp"

class FromInt: public From
{
	protected:
		int					isIt() const;
	public:
							FromInt();
							FromInt(std::string s);
							FromInt(const FromInt &src);
							~FromInt();
		FromInt&	operator=(const FromInt &src);
		int					print() const;
};

#endif