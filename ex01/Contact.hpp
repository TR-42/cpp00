/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 21:06:27 by kfujita           #+#    #+#             */
/*   Updated: 2023/06/19 23:14:37 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Contact
{
private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string _phoneNumber;
	std::string _darkestSecret;

public:
	Contact();
	Contact(const Contact &src);
	Contact(
		const std::string firstName,
		const std::string lastNane,
		const std::string nickname,
		const std::string phoneNumber,
		const std::string darkestSecret
	);

	std::string toString() const;
	std::string getDetail() const;

	Contact &operator= (const Contact &from);
};
