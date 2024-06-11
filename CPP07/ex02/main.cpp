/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:36:02 by jquil             #+#    #+#             */
/*   Updated: 2024/06/11 13:17:10 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

#define MAX_VAL 750
int main(int, char**)
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
		//std::cout << numbers[i] << std::endl;
	}
	delete [] mirror;
	return 0;
}
// int main(void)
// {
// 	srand(time(0));

// 	std::cout << "		Test 1---------------------------------------" << std::endl;
// 	Array<int> A(20);
// 	std::cout << "A.size = " << A.size() << std::endl;
// 	for (unsigned int x = 0; x < A.size(); x++)
// 		A[x] = rand();
// 	try
// 	{
// 		std::cout << A[21] << std::endl;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// 	for (unsigned int x = 0; x < A.size(); x++)
// 	{
// 		std::cout << "Before" << std::endl;
// 		std::cout << "A[" << x << "] = " << A[x] << std::endl;
// 	}
// 	std::cout << "\n\n		Test 2---------------------------------------" << std::endl;
// 	std::cout << "A[0] = " << A[0] << "	A[1] = " << A[1] << std::endl;
// 	A[0] = A[1];
// 	std::cout << "A[0] = " << A[0] << "	A[1] = " << A[1] << std::endl;

// 	std::cout << "\n\n		Test 3---------------------------------------" << std::endl;
// 	Array<int> B(20);
// 	B = A;
// 	for (unsigned int x = 0; x < A.size(); x++)
// 		std::cout << "A[" << x << "] = " << A[x] << "	B[" << x << "] = " << B[x] << std::endl;

// 	// Test Exception
// 	// for (unsigned int x = 0; x <= A.size() + 3; x++)
// 	// 	std::cout << "A[" << x << "] = " << A[x] << std::endl;
// 	return (0);
// }
