/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:00:01 by jeada-si          #+#    #+#             */
/*   Updated: 2024/09/18 09:24:26 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <cstdlib>
#include <ctime>

Base*	generate(void)
{
	Base*	out;
	int		random;	
	
	random = std::rand() % 3;
	switch (random)
	{
	case 0:
		out = new A();
		break;
	case 1:
		out = new B();
		break;
	case 2:
		out = new C();
		break;
	default:
		out = NULL;
		break;
	}
	return out;
}

void	identify(Base* p)
{
	std::cout << "Ptr identify: ";
	if (dynamic_cast<A*>(p))
		std::cout << "A";
	if (dynamic_cast<B*>(p))
		std::cout << "B";
	if (dynamic_cast<C*>(p))
		std::cout << "C";
	std::cout << std::endl;
}

void	identify(Base& p)
{
	A	a;
	B	b;
	C	c;
	
	std::cout << "Ref identify: ";
	try
	{
		a = dynamic_cast<A&>(p);
		std::cout << "A";
	}
	catch(const std::exception& e){}

	try
	{
		b = dynamic_cast<B&>(p);
		std::cout << "B";
	}
	catch(const std::exception& e){}
	
	try
	{
		c = dynamic_cast<C&>(p);
		std::cout << "C";
	}
	catch(const std::exception& e){}
	std::cout << std::endl;
}

int main()
{
	std::srand(std::time(NULL));
	for (int i = 0; i < 10; i++)
	{
		Base	*p = generate();
		Base	&ref = *p;
		identify(p);
		identify(ref);
		delete p;
	}
}