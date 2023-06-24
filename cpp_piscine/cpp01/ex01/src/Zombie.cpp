/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 12:21:31 by gpimenta          #+#    #+#             */
/*   Updated: 2023/06/24 15:16:06 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie::Zombie(void) {
	std::cout << "A zombie was created" << std::endl;
}

Zombie::~Zombie(void) {
	std::cout << this->_zombieName << ": Destructor called" << std::endl;
}

void	Zombie::announce(void) {
	std::cout << this->_zombieName << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name) {
	this->_zombieName = name;
}
