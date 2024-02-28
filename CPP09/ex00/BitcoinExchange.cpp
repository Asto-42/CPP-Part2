/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:41:42 by jquil             #+#    #+#             */
/*   Updated: 2024/02/28 18:44:47 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

Bitcoin::Bitcoin(void)
{
	return ;
};

Bitcoin::Bitcoin(std::string filename)
{
	std::fstream infile("data.txt");
	infile.open(filename.c_str(), std::ios::in);
	if (!infile)
		throw Bitcoin::InvalidFile();

	this->file_name = filename;
	unsigned int x = 0;

	std::ifstream DataBase(this->file_name.c_str());
	if (!DataBase.is_open())
		throw Bitcoin::InvalidFile();
	std::string buffer;
	while (std::getline(DataBase, buffer))
	{
		x++;
		std::stringstream	streamBuf(buffer);
		std::string			date;
		float				value;
		if (std::getline(streamBuf, date, ',') && streamBuf >> value)
			this->map[date] = value;
	}
	this->size = x;
	DataBase.close();
}
bool parseFirstMember(std::string str, int year, int month, int day)
{
	int data_1 = atoi(str.c_str());
	str.erase(0, str.find("-") + 1);
	int data_2 = atoi(str.c_str());
	str.erase(0, str.find("-") + 1);
	int data_3 = atoi(str.c_str());
	if (data_1 < data_2 || data_1 < data_3)
			return (0);
	if (data_1 < 2009 || data_1 > year)
		return (0);
	if (data_1 == year && (data_2 > month && data_3 > day))
		return (0);
	if (data_2 < 1 || data_2 > 12)
		return (0);
	if (data_3 < 0 || data_3 > 31)
		return (0);
	if (data_1 % 4 == 0 && data_2 == 2 && data_3 > 29)
		return (0);
	else if (data_2 == 2 && data_3 > 28)
		return (0);
	else if (data_2 <= 7 && data_2 % 2 == 0 && data_3 >= 31)
		return (0);
	else if (data_2 > 7 && data_2 % 2 != 0 && data_3 >= 31)
		return (0);
	else if (data_3 > 31)
		return (0);
	return (1);
}
bool parseSecondMember(float bit_value)
{
	if (bit_value < 0)
		return (0);
	return (1);
}

void	Bitcoin::parseDataBase(void)
{
	time_t now = time(0); // get current dat/time with respect to system
	tm* ltm = localtime(&now);
	for (std::map<std::string, float>::iterator it = ((this->getMapBegin())); it != ((this->getMapEnd())); ++it)
	{
		if (parseFirstMember(it->first, 1900 + ltm->tm_year, 1 + ltm->tm_mon, ltm->tm_mday) == 0)
			throw Bitcoin::InvalidDate();
		if (parseSecondMember(it->second) == 0)
			throw Bitcoin::InvalidValue();
	}
}

Bitcoin::Bitcoin(Bitcoin &rhs)
{
	(void)rhs;
};

Bitcoin::~Bitcoin()
{
	return ;
};

Bitcoin &Bitcoin::operator=(Bitcoin const &rhs)
{
	(void)rhs;
	return *this;
};

std::map<std::basic_string<char>, float>::iterator	Bitcoin::getMapBegin(void)
{
	return (this->map.begin());
}

std::map<std::basic_string<char>, float>::iterator	Bitcoin::getMapEnd(void)
{
	return (this->map.end());
}

void	Bitcoin::printmap(void)
{
	for (std::map<std::string, float>::iterator it = ((this->getMapBegin())); it != ((this->getMapEnd())); ++it)
		std::cout << it->first << ", " << it->second << '\n';
}

const char *Bitcoin::InvalidDate::what() const throw()
{
	return ("Invalid date format");
}

const char *Bitcoin::InvalidValue::what() const throw()
{
	return ("Invalid Bitcoin value");
}

const char *Bitcoin::InvalidFile::what() const throw()
{
	return ("Invalid input file");
}
