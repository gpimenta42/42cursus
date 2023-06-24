/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 18:48:59 by gpimenta          #+#    #+#             */
/*   Updated: 2023/06/04 12:55:42 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"

Weapon::Weapon(std::string name) : _type(name) {}

std::string const&	Weapon::getType(void) const {
	return this->_type;
}


void	Weapon::setType(std::string name) {
	this->_type = name;
}
