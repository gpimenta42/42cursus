/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 12:15:58 by gpimenta          #+#    #+#             */
/*   Updated: 2023/06/24 13:07:29 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
private:
	std::string	_zombieName;
public:
	Zombie(std::string name);
	~Zombie();

	void	announce(void);
};

Zombie*		newZombie(std::string name);

void		randomChump(std::string name);

#endif
