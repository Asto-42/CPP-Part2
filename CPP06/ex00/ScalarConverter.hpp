/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:23:42 by jquil             #+#    #+#             */
/*   Updated: 2024/05/28 13:28:12 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>
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
#include "my_convert.hpp"

class ScalarConverter
{
	private:

	ScalarConverter();
	ScalarConverter(const ScalarConverter & y);
	ScalarConverter& 	operator=(ScalarConverter const & rhs);
	~ScalarConverter();

	public:


	static void convert(char *str);

};

#endif
