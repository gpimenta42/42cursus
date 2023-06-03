/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:01:01 by gpimenta          #+#    #+#             */
/*   Updated: 2023/05/31 14:55:49 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"

void	Contact::setFirstName(std::string str) {
	this->_first_name = str;
}

void	Contact::setLastName(std::string str) {
	this->_last_name = str;
}

void	Contact::setNickname(std::string str) {
	this->_nickname = str;
}

void	Contact::setPhoneNumber(std::string str) {
	this->_phone_number = str;
}

void	Contact::setDarkestSecret(std::string str) {
	this->_darkest_secret = str;
}

std::string	Contact::getFirstName(void) const {
	return this->_first_name;
}

std::string	Contact::getLastName(void) const {
	return this->_last_name;
}

std::string	Contact::getNickname(void) const {
	return this->_nickname;
}

std::string	Contact::getPhoneNumber(void) const {
	return this->_phone_number;
}

std::string	Contact::getDarkestSecret(void) const {
	return this->_darkest_secret;
}

