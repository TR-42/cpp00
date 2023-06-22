/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 21:20:16 by kfujita           #+#    #+#             */
/*   Updated: 2023/06/23 00:22:16 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char *argv[])
{
	size_t	i;

	i = 0;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (++i < (size_t)argc)
	{
		std::string str = std::string(argv[i]);
		for (std::string::iterator it = str.begin(); it != str.end(); it++)
		{
			if (islower(*it))
				*it = std::toupper(*it);
		}
		std::cout << str;
	}
	std::cout << std::endl;
}
