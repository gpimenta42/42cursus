/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 11:54:21 by gpimenta          #+#    #+#             */
/*   Updated: 2023/06/24 12:57:41 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money. You didnt put enough bacon in my burger! If you did, I wouldnt be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free. Ive been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string		arr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	typedef void	(Harl::*func_ptr)(void);

	func_ptr ptr[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	for (int i = 0; i < 4; i++)
	{
		if (level == arr[i])
		{
			switch (i)
			{
			case 0:
				(this->*ptr[i])();
				std::cout << std::endl;
				(this->*ptr[1])();
				std::cout << std::endl;
				(this->*ptr[2])();
				std::cout << std::endl;
				(this->*ptr[3])();
				break;
			case 1:
				(this->*ptr[1])();
				std::cout << std::endl;
				(this->*ptr[2])();
				std::cout << std::endl;
				(this->*ptr[3])();
				break;
			case 2:
				(this->*ptr[2])();
				std::cout << std::endl;
				(this->*ptr[3])();
				break;
			case 3:
				(this->*ptr[3])();
				break;
			default:
				break;
			}
			return ;
		}
	}
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}
