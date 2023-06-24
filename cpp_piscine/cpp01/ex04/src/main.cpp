/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpimenta <gpimenta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 14:57:41 by gpimenta          #+#    #+#             */
/*   Updated: 2023/06/24 14:47:34 by gpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Please, insert 3 arguments: filename, s1 and s2" << std::endl;
		return (1);
	}
	std::ifstream ifs(av[1]);
	if (!ifs.is_open())
	{
		std::cout << "Invalid infile" << std::endl;
		return (1);
	}
	std::string text;
	std::getline(ifs, text, '\0');
	std::string s1(av[2]);
	std::string s2(av[3]);
	std::size_t found = text.find(s1.c_str());
	while (found != std::string::npos)
	{
		text.erase(found, s1.length());
		text.insert(found, s2);
		found = text.find(s1.c_str());
		if (found == 0)
			break ;
	}
	std::string filename(av[1]);
	filename.append(".replace");
	std::ofstream ofs(filename.c_str());
	ofs << text;
	ofs.close();
	ifs.close();
}
