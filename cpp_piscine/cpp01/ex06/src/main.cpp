/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 12:18:11 by gpimenta          #+#    #+#             */
/*   Updated: 2023/06/24 12:58:32 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

int	main(int ac, char **av)
{
	std::string	input;
	Harl		obj;

	if (ac != 2)
	{
		std::cout << "Please insert one of the following arguments after the program name: DEBUG | INFO | WARNING | ERROR" << std::endl;
		exit (1);
	}
	input = av[1];
	obj.complain(input);
}
