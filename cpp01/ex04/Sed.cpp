/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 11:57:53 by jeada-si          #+#    #+#             */
/*   Updated: 2024/08/01 17:23:20 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"
#include <unistd.h>

Sed::Sed(std::string filename, std::string s1, std::string s2): _s1(s1), _s2(s2)
{
	std::string	outfile;
	
	_in.open(filename.data());
	if (!_in)
		std::cout << "Input file opening failed." << std::endl;
	outfile.append(filename).append(".replace");
	_out.open(outfile.data());
	if (!_out)
		std::cout << "Output file opening failed." << std::endl;
	if (!_s1.size())
		std::cout << "s1 cannot be empty." << std::endl;
}

Sed::~Sed()
{
}

int	Sed::replace()
{
	std::streambuf	*inBuffer = _in.rdbuf();
	std::streamsize	size = _s1.size();
	char			s[size + 1];

	if (!_in || !_out || !size)
		return 1;
	s[size] = 0;
	while(inBuffer->in_avail() > size)
	{
		inBuffer->sgetn(s, size);
		if (!_s1.compare(s))
			_out << _s2;
		else
		{
			inBuffer->pubseekoff(-size, std::ios_base::cur);		
			_out << (char) inBuffer->sbumpc();
		}
	}
	while (inBuffer->in_avail())
		_out << (char) inBuffer->sbumpc();
	return 0;
}
