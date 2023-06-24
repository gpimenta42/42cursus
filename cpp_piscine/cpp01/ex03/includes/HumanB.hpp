/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 19:37:33 by gpimenta          #+#    #+#             */
/*   Updated: 2023/06/24 14:18:31 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
private:
	/*it needs to be a pointer to be able to be null*/
	Weapon		*_weapon;
	std::string _name;
public:
	HumanB(std::string name);

	void	setWeapon(Weapon &weapon);
	void	attack(void);
};

#endif
