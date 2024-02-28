/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_convert.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:52:33 by jquil             #+#    #+#             */
/*   Updated: 2024/02/20 19:54:40 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool IsChar(std::string const &str)
{

	if (str.size() == 1 && isprint(str[0]) && !isdigit(str[0]))
		return (1);
	return (0);
}

bool IsInt(std::string const &str)
{
	int y = 0;
	if ((str[0] == '-') || (str[0] == '+'))
		y++;
	for (size_t x = y; x < str.size(); x++)
	{
		if (!isdigit(str[x]))
			return (0);
	}
	return (1);
}

bool IsFloat(std::string const &str)
{
	bool decimal = 0;
	int y = 0;
	if ((str[0] == '-') || (str[0] == '+'))
		y++;
	for (size_t x = y; x < str.size(); x++)
	{
		if (str[x] == '.')
		{
			if (decimal == 1)
				return (0);
			decimal = 1;
		}
		else if ((str[x] == 'f' || str[x] == 'F') && decimal == 1 && !str[x + 1])
			return (1);
		else if (!isdigit(str[x]))
			return (0);
	}
	return (0);
}

bool IsDouble(std::string const &str)
{
	bool decimal = 0;
	int y = 0;
	if ((str[0] == '-') || (str[0] == '+'))
		y++;
	for (size_t x = y; x < str.size(); x++)
	{
		if (str[x] == '.')
		{
			if (decimal == 1)
				return (0);
			decimal = 1;
		}
		else if (!isdigit(str[x]))
			return (0);
		else if (x == str.size() - 1 && decimal == 1)
			return (1);
	}
	return (0);
}

unsigned int getType(std::string const &str)
{
	bool	(*Check[4])(std::string const &) = {IsChar, IsInt, IsFloat, IsDouble};
	unsigned int res[4] = {CHAR, INT, FLOAT, DOUBLE};
	for (int x = 0; x < 4; x++)
	{
		if (Check[x](str) == 1)
			return (res[x]);
	}
	return (ERROR);
}

void print_data(char c_val, int i_val, float f_val, double d_val)
{
	if (c_val >= 21 && c_val < 127)
		std::cout << "Char value is " << c_val << std::endl;
	else if ((c_val >= 0 && c_val <= 32) || c_val == 127)
		std::cout << "Char value is unprintable" << std::endl;
	else
		std::cout << "Char value is unprintable." << std::endl;
	std::cout << "Int value is " << i_val << std::endl;
	std::cout << "Float value is " << f_val << ".0f" << std::endl;
	std::cout << "Double value is " << d_val << ".0" << std::endl;
}

void ConvertFromDouble(std::string const &str)
{
	double d_val = atof(str.c_str());
	float f_val = static_cast<float>(d_val);
	char c_val = static_cast<char>(d_val);
	int i_val = static_cast<int>(d_val);
	print_data(c_val, i_val, f_val, d_val);
}

void ConvertFromFloat(std::string const &str)
{
	float f_val = atof(str.c_str());
	char c_val = static_cast<char>(f_val);
	int i_val = static_cast<int>(f_val);
	double d_val = static_cast<double>(f_val);
	print_data(c_val, i_val, f_val, d_val);
}

void ConvertFromChar(std::string const &str)
{
	char c_val = str[0];
	int i_val = static_cast<int>(c_val);
	float f_val = static_cast<float>(c_val);
	double d_val = static_cast<double>(c_val);
	print_data(c_val, i_val, f_val, d_val);
}

void ConvertFromInt(std::string const &str)
{
	int i_val = atoi(str.c_str());
	char c_val = static_cast<char>(i_val);
	float f_val = static_cast<float>(i_val);
	double d_val = static_cast<double>(i_val);
	print_data(c_val, i_val, f_val, d_val);
}

void my_convert(std::string const &str)
{
	unsigned int type = getType(str);
	switch (type)
	{
		case 0 :
			std::cout << "bad input" << std::endl;
			return ;
		case 1 :
			ConvertFromChar(str);
			break ;
		case 2 :
			ConvertFromInt(str);
			break ;
		case 3 :
			ConvertFromFloat(str);
			break ;
		case 4 :
			ConvertFromDouble(str);
			break ;
	}
}
