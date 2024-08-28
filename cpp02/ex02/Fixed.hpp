/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:20:44 by jeada-si          #+#    #+#             */
/*   Updated: 2024/08/22 11:49:04 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_H__
# define __FIXED_H__
# include <iostream>
# define EPSILON
# define BLUE   "\e[1;34m"
# define RESET  "\e[0m"
class Fixed
{
	private:
		int					_rawBits;
		static const int	_fracBits = 8;
	public:
							Fixed();
							Fixed(const Fixed &src);
							Fixed(const int i);
							Fixed(const float f);
							~Fixed();
		Fixed& 				operator=(const Fixed &src);		
		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		float				toFloat(void) const;
		int					toInt(void) const;
		bool				operator>(Fixed const &obj) const;
		bool				operator<(Fixed const &obj) const;
		bool				operator<=(Fixed const &obj) const;
		bool				operator>=(Fixed const &obj) const;
		bool				operator==(Fixed const &obj) const;
		bool				operator!=(Fixed const &obj) const;
		Fixed				operator+(Fixed const &obj) const;
		Fixed				operator-(Fixed const &obj) const;
		Fixed				operator/(Fixed const &obj) const;
		Fixed				operator*(Fixed const &obj) const;
		Fixed&				operator++();
		Fixed&				operator--();
		Fixed				operator++(int);
		Fixed				operator--(int);
		static Fixed&		min(Fixed &a, Fixed &b);
		static Fixed&		max(Fixed &a, Fixed &b);
		static Fixed const&	max(Fixed const &a, Fixed const &b);
		static Fixed const&	min(Fixed const &a, Fixed const &b);
};

std::ostream& operator<<(std::ostream &out, const Fixed &obj);

#endif
