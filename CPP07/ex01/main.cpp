/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:36:02 by jquil             #+#    #+#             */
/*   Updated: 2024/02/22 15:06:17 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void add_one(int &y)
{
	y = y + 1;
}

void to_weird(char &c)
{
	int x = rand();
	c = c + x;
}

void to_up(char &c)
{
	if (c >= 97 && c <= 122)
		c = c - 32;
}

int main(void)
{
	std::srand(time(0));
	std::cout << "		Test 1" << std::endl;
	int x[] = {1 , 2 , 3 , 7};

	// print original array
	std::cout << "x[" << sizeof(x) / sizeof(int) << "] = {";
	for(size_t y = 0; y < sizeof(x) / sizeof(int) - 1; y++)
		std::cout << x[y] << ", ";
	std::cout << x[sizeof(x) / sizeof(int) - 1] << "}" << std::endl;
	::iter(x, sizeof(x) / sizeof(int) , add_one);

	// print modified array
	std::cout << "x[" << sizeof(x) / sizeof(int) << "] = {";
	for(size_t y = 0; y < sizeof(x) / sizeof(int) - 1; y++)
		std::cout << x[y] << ", ";
	std::cout << x[sizeof(x) / sizeof(int) - 1] << "}" << std::endl;

	char str[] = "Let's test this";

	// print original str
	std::cout << "str[" << sizeof(str) / sizeof(char) << "] = \"" << str << "\"" << std::endl;

	::iter(str, sizeof(str) / sizeof(char), to_up);

	// print upper str
	std::cout << "str[" << sizeof(str) / sizeof(char) << "] = \"" << str << "\"" << std::endl;

	::iter(str, sizeof(str) / sizeof(char), to_weird);

	//print weird str
	std::cout << "str[" << sizeof(str) / sizeof(char) << "] = \"" << str << "\"" << std::endl;

	return 0;
}
