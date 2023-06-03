/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 16:44:13 by gpimenta          #+#    #+#             */
/*   Updated: 2023/05/29 14:06:13 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Just to make sure that everybody is awake, write a program that behaves as follows:
$>./megaphone "shhhhh... I think the students are asleep..."
SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
$>./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
$>./megaphone
* LOUD AND UNBEARABLE FEEDBACK NOISE *
$>
*/

#include <iostream>
#include <string> /*class str*/
#include <ctype.h> /*toupper*/

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int j = 1; j < ac; j++)
	{
		std::string str (av[j]);
		for (int i = 0; i < str.size(); i++)
			std::cout << (char)toupper(str[i]);
		if (j + 1 != ac)
			std::cout << " ";
	}
	std::cout << std::endl;
}
