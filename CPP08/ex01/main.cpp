/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:36:02 by jquil             #+#    #+#             */
/*   Updated: 2024/05/28 16:56:43 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void)
{
	try
	{
		srand(time(0));
		size_t size = 20000;
		std::vector<int> vect;
		int y;
		Span A = Span(size);
		for (unsigned int x = 0; x < A.getSize(); x++)
		{
			y = rand();
			if (y < 0)
				y = -y;
			vect.push_back(y);
		}
		A.AddMultipleNumber(vect);
		int shortest = A.shortestSpan();
		int longest = A.longestSpan();
		std::cout << "A shortest span is = " << shortest << std::endl;
		std::cout << "A longest span is = " << longest << std::endl;
		A.compare_value(longest);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
