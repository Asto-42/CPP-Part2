/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:36:02 by jquil             #+#    #+#             */
/*   Updated: 2024/02/28 14:11:22 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void)
{
	try
	{
		srand(time(0));
		int y;
		Span A = Span(10000);
		for (unsigned int x = 0; x < A.getSize(); x++)
		{
			y = rand();
			if (y < 0)
				y = -y;
			A.AddNumber(y);
		}
		for (unsigned int x = 0; x < A.getSize(); x++)
		{
			std::cout << A[x] << std::endl;
		}
		unsigned int min_1 = A[0];
		unsigned int min_2 = A[1];
		int	min_span = INT_MAX;
		int max_span = 0;
		for (unsigned int y = 0; y < A.getSize(); y++)
		{
			for (unsigned int x = 1; x < A.getSize(); x++)
			{
				if ((A[y] - A[x] > 0) && ((unsigned int)(A[y] - A[x]) < min_1 - min_2))
				{
					min_1 = A[y];
					min_2 = A[x];
					x = 0;
				}
				if (A[x] < min_span)
					min_span = A[x];
				if (A[x] > max_span)
					max_span = A[x];
			}
		}
		std::cout << "Min is = " << min_1 - min_2 << std::endl;
		std::cout << "Max is = " << max_span - min_span << "\n" << std::endl;
		std::cout << "A shortest span is = " << A.shortestSpan() << std::endl;
		std::cout << "A longest span is = " << A.longestSpan() << std::endl;
		std::cout << "\nDiff of long = " << (max_span - min_span) - (A.longestSpan()) << std::endl;
		std::cout << "Diff of short = " << (min_1 - min_2) - (A.shortestSpan()) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
