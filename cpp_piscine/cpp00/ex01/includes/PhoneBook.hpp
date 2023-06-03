/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:11:46 by gpimenta          #+#    #+#             */
/*   Updated: 2023/05/29 18:30:30 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <cstddef> /*size_t*/
# include <iomanip> /*setw*/
#include <stdlib.h> /*atoi*/

class PhoneBook {
public:
	PhoneBook();
	void	addContact(void);
	void	searchContact(void);

private:
	int		_count;
	Contact _contact[8];
};

#endif
