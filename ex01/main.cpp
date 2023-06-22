/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 22:48:06 by kfujita           #+#    #+#             */
/*   Updated: 2023/06/23 00:18:55 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "PhoneBook.hpp"

#define STR(v) #v

#define CMD_ADD "ADD"
#define CMD_SEARCH "SEARCH"
#define CMD_EXIT "EXIT"

#define SET_STR(v) \
	while (v.length() == 0) {\
		std::cout << #v " > ";\
		std::cin >> v;\
		if (std::cin.eof())\
			exit(1);\
		if (v.length() == 0)\
			std::cout << "ERR! Empty field is not allowed," << std::endl;\
	}\

static void do_add(PhoneBook& pb)
{
	std::string
		firstName,
		lastName,
		nickname,
		phoneNumber,
		darkestSecret
	;

	SET_STR(firstName);
	SET_STR(lastName);
	SET_STR(nickname);
	SET_STR(phoneNumber);
	SET_STR(darkestSecret);

	Contact c(
		firstName,
		lastName,
		nickname,
		phoneNumber,
		darkestSecret
	);
	pb.add(c);
	std::cout << "Contact successfully added!" << std::endl << c.toString() << std::endl;
}

static bool isNumericStr(const std::string& s)
{
	if (s.empty())
		return (false);
	const char *c = s.c_str();

	while (*c != '\0')
	{
		if (!std::isdigit(*c))
			return (false);
		c++;
	}

	return (true);
}

static void do_search(const PhoneBook& pb)
{
	pb.printDetail();

	if (pb.isEmpty())
	{
		std::cout << "PhoneBook is empty" << std::endl;
		return;
	}

	std::string index;
	int indexNum;

	SET_STR(index);

	if (!isNumericStr(index))
	{
		std::cerr << "ERR! Input was non-numeric str" << std::endl;
		return;
	}
	indexNum = std::atoi(index.c_str());
	if (pb.printOne(indexNum))
		return;
	else
		std::cout << "ERR! Invalid Input" << std::endl;
}

static bool loop(PhoneBook& pb)
{
	std::cout << "(" CMD_ADD "|" CMD_SEARCH "|" CMD_EXIT ") > ";
	std::string input;
	std::cin >> input;

	if (input.compare(CMD_ADD) == 0)
		do_add(pb);
	else if (input.compare(CMD_SEARCH) == 0)
		do_search(pb);
	else if (input.compare(CMD_EXIT) == 0 || std::cin.eof())
	{
		std::cout << "Good Bye!" << std::endl;
		return (false);
	}
	else
		std::cout << "Please try again!" << std::endl;

	return (true);
}

int main(void)
{
	PhoneBook book;

	while (loop(book));
	return (0);
}
