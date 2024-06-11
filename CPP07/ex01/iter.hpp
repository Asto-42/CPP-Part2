/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:11:09 by jquil             #+#    #+#             */
/*   Updated: 2024/06/11 13:17:40 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

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

template< typename T, typename F >
void	iter(T *array, size_t len, F f)
{
	try
	{
		if (!array || len <= 0 || !f) {
			throw std::invalid_argument("Invalid argument.");
		}
		for (size_t i = 0; i < len; i++)
			f(array[i]);
	}
	catch (const std::invalid_argument& e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
}

template< typename T >
void 	print(T &value)
{
	std::cout << value << std::endl;
};

#endif

