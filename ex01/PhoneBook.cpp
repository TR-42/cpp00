/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 22:47:46 by kfujita           #+#    #+#             */
/*   Updated: 2023/06/20 00:49:49 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// - cout
// etc.
#include <iostream>

// - setw (c++98)
// ref: https://en.cppreference.com/w/cpp/io/manip/setw
#include <iomanip>

#include "PhoneBook.hpp"

static const char *DETAIL_HEADHER = "|"
	"     Index|"
	"First Name|"
	" Last Name|"
	"  Nickname|"
;

PhoneBook::PhoneBook() :
	_nextIndex(0)
{
}

void PhoneBook::add(const Contact &contact)
{
	this->_contactList[this->_nextIndex++] = Contact(contact);
	if (this->CONTACT_LIST_LENGTH <= this->_nextIndex)
		this->_nextIndex = 0;
}

void PhoneBook::printDetail() const
{
	std::cout << DETAIL_HEADHER << std::endl;
	for (int i = 0; i < this->CONTACT_LIST_LENGTH; i++)
	{
		std::cout << "|"
			<< std::setw(10) << i + 1
			<< this->_contactList[i]
			<< std::endl;
	}
}

bool PhoneBook::printOne(int index) const
{
	if (index <= 0 || this->CONTACT_LIST_LENGTH < index)
		return (false);
	std::cout << this->_contactList[index - 1].toString();
	return true;
}
