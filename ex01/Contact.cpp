/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 22:44:10 by kfujita           #+#    #+#             */
/*   Updated: 2023/06/19 23:14:31 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	return std::string();
}

std::string Contact::getDetail() const
{
	return std::string();
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
