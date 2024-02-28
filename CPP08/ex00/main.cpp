/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:36:02 by jquil             #+#    #+#             */
/*   Updated: 2024/02/23 14:30:09 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Easy.hpp"

const char *NoOccurence::what() const throw()
{
	return ("No occurence founded in list");
}

template <typename T>
int easy_find(T temp, int nb)
{
	for (size_t x = 0; x < temp.size(); x++)
		if (temp[x] == nb)
			return (x);
	throw NoOccurence();
}

int main(void)
{
	std::vector<int> nb_lst;
	nb_lst.push_back(1);
	nb_lst.push_back(25);
	nb_lst.push_back(10);
	nb_lst.push_back(52);
	nb_lst.push_back(98);
	nb_lst.push_back(85);
	try
	{
		std::cout << "Data is at rank : " << easy_find(nb_lst, 96) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "Data is at rank : " << easy_find(nb_lst, 98) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
