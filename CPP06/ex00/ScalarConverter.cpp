/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:22:30 by jquil             #+#    #+#             */
/*   Updated: 2024/05/28 13:29:13 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
	//std::cout << "Default constructor called" << std::endl;
};

ScalarConverter::ScalarConverter(const ScalarConverter & y)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = y;
};

ScalarConverter&	ScalarConverter::operator=(ScalarConverter const & rhs)
{
	std::cout << "Assignment operator called for ScalarConverter" << std::endl;
	(void)rhs;
	if (this != &rhs)
	{
	}
	return *this;
}

void ScalarConverter::convert(char *str)
{
	my_convert(str);
}

ScalarConverter::~ScalarConverter(void)
{
	//std::cout << "Default destructor called" << std::endl;
};
