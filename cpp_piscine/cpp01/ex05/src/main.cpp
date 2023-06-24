/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 12:18:11 by gpimenta          #+#    #+#             */
/*   Updated: 2023/06/24 12:48:46 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

void	harl_intro(void)
{
	std::cout << "Please, enter one of the following commands: DEBUG | INFO | WARNING | ERROR" << std::endl;
}

int	main()
{
	std::string	input;
	Harl		obj;

	while (1)
	{
		harl_intro();
		std::getline(std::cin, input);
		if (!input.compare("DEBUG") || !input.compare("INFO") || !input.compare("WARNING") || !input.compare("ERROR"))
			obj.complain(input);
		else
		{
			std::cout << "Invalid input ❌" << std::endl;
			harl_intro();
		}
	}
}
