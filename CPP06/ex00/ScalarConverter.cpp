/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:22:30 by jquil             #+#    #+#             */
/*   Updated: 2024/02/20 17:48:55 by jquil            ###   ########.fr       */
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

void ScalarConverter::convert(char *str)
{
	my_convert(str);
}

ScalarConverter::~ScalarConverter(void)
{
	//std::cout << "Default destructor called" << std::endl;
};
