#include <ctime>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << RED "Wrong number of arguments." RESET << std::endl;
		return 1;
	}
	std::ifstream	pricesIn;
	std::ifstream	dataIn;

	pricesIn.open("./data.csv", std::fstream::in);
	dataIn.open(av[1], std::fstream::in);
	if (dataIn.bad() || dataIn.fail() || pricesIn.bad() || pricesIn.fail())
	{
		std::cerr << RED "Error: could not open file.\n" RESET;
		return 1;
	}
	BitcoinExchange	btce(pricesIn);
	btce.compute(dataIn);
	return 1;
}
