/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:28:07 by gpimenta          #+#    #+#             */
/*   Updated: 2023/05/31 15:11:08 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

PhoneBook::PhoneBook() : _count(0)
{
}

void	PhoneBook::addContact(void)
{
	std::string	input;
	Contact		curr;

	while (input.empty())
	{
		std::cout << "Please, enter full name: ";
		std::getline(std::cin, input);
		curr.setFirstName(input);
	}
	input.clear();
	while (input.empty())
	{
		std::cout << "Please, enter last name: ";
		std::getline(std::cin, input);
		curr.setLastName(input);
	}
	input.clear();
	while (input.empty())
	{
		std::cout << "Please, enter nickname: ";
		std::getline(std::cin, input);
		curr.setNickname(input);
	}
	input.clear();
	while (input.empty() || input.find_first_not_of("0123456789") != std::string::npos)
	{
		std::cout << "Please, enter phone number (only numbers): ";
		std::getline(std::cin, input);
		curr.setPhoneNumber(input);
	}
	input.clear();
	while (input.empty())
	{
		std::cout << "Please, enter darkest secret: ";
		std::getline(std::cin, input);
		curr.setDarkestSecret(input);
	}
	input.clear();
	std::cout << "Contact added ✅" << std::endl << std::endl;
	this->_contact[this->_count % 8] = curr;
	this->_count++;
}

std::string	correct_width(std::string str)
{
	if (str.length() > 10)
	{
		std::string res = str.substr(0, 9);
		res += ".";
		return (res);
	}
	return (str);
}

void	PhoneBook::searchContact(void)
{
	if (this->_count == 0)
	{
		std::cout << "Phonebook still empty❗" << std::endl << std::endl;
		return ;
	}
	std::cout << " ___________________________________________" << std::endl;
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	int j;
	if (this->_count > 8)
		j = 8;
	else
		j = this->_count;
	for (int i = 0; i < j; i++)
	{
		std::cout << "|" << std::setw(10) << std::right << i + 1;
		std::cout << "|" << std::setw(10) << std::right << correct_width(this->_contact[i].getFirstName());
		std::cout << "|" << std::setw(10) << std::right << correct_width(this->_contact[i].getLastName());
		std::cout << "|" << std::setw(10) << std::right << correct_width(this->_contact[i].getNickname()) << "|\n";
	}
	std::cout << "---------------------------------------------" << std::endl << std::endl;
	std::string	input;
	while (input.empty() || input.find_first_not_of("0123456789") != std::string::npos
		|| atoi(input.c_str()) < 1 || atoi(input.c_str()) > j)
	{
		std::cout << "Please, enter the INDEX of the contact you want to display it's information" << std::endl;
		std::cout << "(It has to be a number between 1 and " << j << ")" << std::endl;
		std::cout << "> ";
		std::getline(std::cin, input);
	}
	std::cout << this->_contact[atoi(input.c_str()) - 1].getLastName() << "'s contact information:" << std::endl;
	std::cout << "	First Name: " << this->_contact[atoi(input.c_str()) - 1].getFirstName() << std::endl;
	std::cout << "	Last Name: " << this->_contact[atoi(input.c_str()) - 1].getLastName() << std::endl;
	std::cout << "	Nickname: " << this->_contact[atoi(input.c_str()) - 1].getNickname() << std::endl;
	std::cout << "	Phone Number: " << this->_contact[atoi(input.c_str()) - 1].getPhoneNumber() << std::endl;
	std::cout << "	Darkest Secret: " << this->_contact[atoi(input.c_str()) - 1].getDarkestSecret() << std::endl << std::endl;
}


