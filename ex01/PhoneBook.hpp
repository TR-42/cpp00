/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 22:44:04 by kfujita           #+#    #+#             */
/*   Updated: 2023/06/20 00:38:18 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Contact.hpp"

class PhoneBook
{
public:
	static const int CONTACT_LIST_LENGTH = 8;

private:
	Contact _contactList[CONTACT_LIST_LENGTH];
	int _nextIndex;

public:
	PhoneBook();

	void add(const Contact &contact);
	void printDetail() const;
	bool printOne(int index) const;
};
