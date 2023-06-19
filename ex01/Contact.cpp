/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 22:44:10 by kfujita           #+#    #+#             */
/*   Updated: 2023/06/20 00:49:17 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>

#include "Contact.hpp"

Contact::Contact() {}

Contact::Contact(const Contact &src) :
	_firstName(src._firstName),
	_lastName(src._lastName),
	_nickname(src._nickname),
	_phoneNumber(src._phoneNumber),
	_darkestSecret(src._darkestSecret)
{
}

Contact::Contact(
	const std::string firstName,
	const std::string lastName,
	const std::string nickname,
	const std::string phoneNumber,
	const std::string darkestSecret
) :
	_firstName(firstName),
	_lastName(lastName),
	_nickname(nickname),
	_phoneNumber(phoneNumber),
	_darkestSecret(darkestSecret)
{
}

std::string Contact::toString() const
{
	return
		"    First Name: " + this->_firstName + "\n"
		"     Last Name: " + this->_lastName + "\n"
		"      Nickname: " + this->_nickname + "\n"
		"  Phone Number: " + this->_phoneNumber + "\n"
		"Darkest Secret: " + this->_darkestSecret + "\n";
}

std::ostream &Contact::setToStream(std::ostream &os) const
{
	os << '|'
		<< std::setw(10) << this->_firstName.substr(0, 10) << '|'
		<< std::setw(10) << this->_lastName.substr(0, 10) << '|'
		<< std::setw(10) << this->_nickname.substr(0, 10) << '|';
	return os;
}

Contact &Contact::operator=(const Contact &from)
{
	this->_firstName = from._firstName;
	this->_lastName = from._lastName;
	this->_nickname = from._nickname;
	this->_phoneNumber = from._phoneNumber;
	this->_darkestSecret = from._darkestSecret;
	return *this;
}

std::ostream &operator<<(std::ostream &os, const Contact v)
{
	return (v.setToStream(os));
}
