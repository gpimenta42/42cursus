/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 12:46:54 by gpimenta          #+#    #+#             */
/*   Updated: 2023/06/24 13:07:49 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int	main()
{
	std::string	input;

	while (input.empty())
	{
		std::cout << "Enter [Stack] Zombie name: ";
		std::getline(std::cin, input);
	}
	//----------stack----------
	randomChump(input);
	input.clear();

	while (input.empty())
	{
		std::cout << "Enter [Heap] Zombie name: ";
		std::getline(std::cin, input);
	}
	//----------heap-----------
	Zombie	*newZ = newZombie(input);
	newZ->announce();
	delete newZ;
}
