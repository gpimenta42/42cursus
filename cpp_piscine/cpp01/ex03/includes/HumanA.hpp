/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 18:53:48 by gpimenta          #+#    #+#             */
/*   Updated: 2023/06/04 13:10:59 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
private:
	/*it has to be a reference to object weapon to be able to be changed*/
	Weapon		&_weapon;
	std::string _name;
public:
	HumanA(std::string name, Weapon &weapon);

	void	attack(void);
};

#endif
