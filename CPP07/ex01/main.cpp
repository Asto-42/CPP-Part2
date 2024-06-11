/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:36:02 by jquil             #+#    #+#             */
/*   Updated: 2024/06/11 13:20:53 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template< typename T>
void add_one(T &y)
{
	y = y + 1;
}

template< typename T>
void to_weird(T &c)
{
	int x = rand();
	c = c + x;
}

template< typename T>
void to_up(T &c)
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
	::iter(x, sizeof(x) / sizeof(int) , add_one<int>);

	// print modified array
	std::cout << "x[" << sizeof(x) / sizeof(int) << "] = {";
	for(size_t y = 0; y < sizeof(x) / sizeof(int) - 1; y++)
		std::cout << x[y] << ", ";
	std::cout << x[sizeof(x) / sizeof(int) - 1] << "}" << std::endl;

	char str[] = "Let's test this";

	// print original str
	std::cout << "str[" << sizeof(str) / sizeof(char) << "] = \"" << str << "\"" << std::endl;

	::iter(str, sizeof(str) / sizeof(char), to_up<char>);

	// print upper str
	std::cout << "str[" << sizeof(str) / sizeof(char) << "] = \"" << str << "\"" << std::endl;

	::iter(str, sizeof(str) / sizeof(char), to_weird<char>);

	//print weird str
	std::cout << "str[" << sizeof(str) / sizeof(char) << "] = \"" << str << "\"" << std::endl;

	return 0;
}
