/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:36:02 by jquil             #+#    #+#             */
/*   Updated: 2024/02/23 14:24:24 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void)
{
	srand(time(0));

	std::cout << "		Test 1---------------------------------------" << std::endl;
	Array<int> A(20);
	std::cout << "A.size = " << A.size() << std::endl;
	for (unsigned int x = 0; x < A.size(); x++)
		A[x] = rand();
	try
	{
		std::cout << A[21] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	for (unsigned int x = 0; x < A.size(); x++)
	{
		std::cout << "Before" << std::endl;
		std::cout << "A[" << x << "] = " << A[x] << std::endl;
	}
	std::cout << "\n\n		Test 2---------------------------------------" << std::endl;
	std::cout << "A[0] = " << A[0] << "	A[1] = " << A[1] << std::endl;
	A[0] = A[1];
	std::cout << "A[0] = " << A[0] << "	A[1] = " << A[1] << std::endl;

	std::cout << "\n\n		Test 3---------------------------------------" << std::endl;
	Array<int> B(20);
	B = A;
	for (unsigned int x = 0; x < A.size(); x++)
		std::cout << "A[" << x << "] = " << A[x] << "	B[" << x << "] = " << B[x] << std::endl;

	// Test Exception
	// for (unsigned int x = 0; x <= A.size() + 3; x++)
	// 	std::cout << "A[" << x << "] = " << A[x] << std::endl;
	return (0);
}
