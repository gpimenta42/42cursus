/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 17:30:10 by gpimenta          #+#    #+#             */
/*   Updated: 2023/06/03 17:42:40 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int	main()
{
	std::string	input;
	Zombie		*arr;
	int			n;

	while (input.empty() || input.find_first_not_of("0123456789") != std::string::npos)
	{
		std::cout << "Enter the number of zombies: ";
		std::getline(std::cin, input);
	}
	n = atoi(input.c_str());
	input.clear();
	while (input.empty())
	{
		std::cout << "Enter zombie names: ";
		std::getline(std::cin, input);
	}

	arr = zombieHorde(n, input);
	for (int i = 0; i < n; i++)
		arr[i].announce();
	delete [] arr;
}
