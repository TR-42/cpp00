/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 22:48:06 by kfujita           #+#    #+#             */
/*   Updated: 2023/06/20 00:41:08 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook book;

	book.add(Contact("first", "last", "nickname", "phone num", "secret"));
	book.add(Contact("uh?? first!?", "long long last", "bad nickname", "phone num", "secret"));
	book.printDetail();
	std::cout << std::endl;
	for (int i = 1; i < book.CONTACT_LIST_LENGTH; i++)
		book.printOne(i);
	return (0);
}
