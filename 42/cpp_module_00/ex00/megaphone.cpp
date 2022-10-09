/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:15:11 by ochoumou          #+#    #+#             */
/*   Updated: 2022/10/09 10:59:03 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>


int main(int argc, char **argv)
{
	std::string arg;

	if (argc > 1)
	{
		for (int i = 1; i < argc; i++)
		{
			arg = argv[i];
			for (int j = 0; j < arg.length(); j++)
				std::cout << (char)std::toupper(argv[i][j]);
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}