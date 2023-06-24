/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 17:47:43 by gpimenta          #+#    #+#             */
/*   Updated: 2023/06/03 17:54:21 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *ptr = &str;
	std::string &ref = str;

	std::cout << "The memory address of the string variable is: " << &str << std::endl;
	std::cout << "The memory address held by stringPTR is: " << ptr << std::endl;
	std::cout << "The memory address held by stringREF is: " << &ref << std::endl;
	std::cout << "The value of the string variable is: " << str << std::endl;
	std::cout << "The value pointed to by stringPTR is: " << *ptr << std::endl;
 	std::cout << "The value pointed to by stringREF is: " << ref << std::endl;
}
