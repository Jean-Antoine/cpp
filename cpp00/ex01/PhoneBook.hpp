/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeada-si <jeada-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:17:06 by jeada-si          #+#    #+#             */
/*   Updated: 2024/07/30 15:54:40 by jeada-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H
# include "Contact.hpp"
# include <iostream>
# define MAX_CONTACT 8

class PhoneBook
{
	private:
		int			i;
		Contact 	arr[MAX_CONTACT];
	public:
		PhoneBook();
		~PhoneBook();
		void add();
		void display();
		void search();
		void run();
};

#endif