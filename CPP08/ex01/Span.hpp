/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:12:45 by jquil             #+#    #+#             */
/*   Updated: 2024/02/23 16:34:31 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <ios>
#include <algorithm>
#include <vector>
#include <math.h>
#include <time.h>
#include <string.h>
#include <limits.h>
#include <cctype>
#include <cstdlib>
#include <stdint.h>
#include <vector>

class Span
{
	private :

	unsigned int size;
	std::vector<int> array;

	public :

	Span();
	Span(unsigned int n);
	Span & operator=(const Span &rhs);
	int & operator[](unsigned int memb);

	unsigned int getSize(void);
	void AddNumber(int nb);
	unsigned int shortestSpan();
	unsigned int longestSpan();

	class MembOutOfRangeException:public std::exception
	{
		public :

		virtual const char *what() const throw();
	};
};
#endif
