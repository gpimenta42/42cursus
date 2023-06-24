/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 19:40:48 by gpimenta          #+#    #+#             */
/*   Updated: 2023/06/24 14:18:42 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"
#include "../includes/HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{}

void	HumanB::attack(void) {
	std::cout << this->_name;
	if (this->_weapon)
		std::cout << " attacks with their " << this->_weapon->getType() << std::endl;
	else
		std::cout << " doesn't have a weapon" << std::endl;
}

/*this has to be a reference otherwise heap use after free*/

void	HumanB::setWeapon(Weapon &weapon) {
	this->_weapon = &weapon;
}
