/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:12:45 by jquil             #+#    #+#             */
/*   Updated: 2024/02/22 17:21:02 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

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

template <typename T>
class Array
{
	private :

	unsigned int len;
	T	*array;

	public :

	Array();
	Array(unsigned int n);
	Array(const Array & y);
	Array<T> & operator=( const Array &rhs);
	T & operator[](unsigned int memb);
	~Array();

	unsigned int size(void);

	class MembOutOfRangeException:public std::exception
	{
		public :

		virtual const char *what() const throw();
	};
};

#include "Array.tpp"

#endif
