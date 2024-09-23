/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:22:17 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/23 09:55:11 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <iomanip>

// void	ft_string_print(std::string& s)
// {
// 	std::cout << "string is " << s << std::endl;
// }

// void	ft_int_print(int& i)
// {
// 	std::cout << "int is " << i << std::endl;
// }

// int	main(void)
// {
// 	std::string	array_s[4] = {"test1", "test2", "test3", "test4"};
// 	int			array_i[4] = {1, 2, 3, 4};

// 	iter(array_s, 4, ft_string_print);
// 	iter(array_i, 4, ft_int_print);
// }

class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

template< typename T >
void print( T& x )
{
  std::cout << x << std::endl;
  return;
}

int main() {
  int tab[] = { 0, 1, 2, 3, 4 };
  Awesome tab2[5];

  iter( tab, 5, print<const int> );
  iter( tab2, 5, print<Awesome> );

  return 0;
}
