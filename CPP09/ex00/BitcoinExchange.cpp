/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:41:42 by jquil             #+#    #+#             */
/*   Updated: 2024/05/28 17:35:46 by jquil            ###   ########.fr       */
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
bool parseSecondMemberInput(float value)
{
	if (value >= 0 && value <= 1000)
		return (1);
	else if (value < 0)
		std::cout << "Error: not a positive number." << std::endl;
	else
		std::cout << "Error: too large a number." << std::endl;
	return (0);
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

std::string Bitcoin::findCloserDate(std::string date)
{
	std::cout << date << std::endl;
	int date_1 = atoi(date.c_str());
	date.erase(0, date.find("-") + 1);
	int date_2 = atoi(date.c_str());
	date.erase(0, date.find("-") + 1);
	int date_3 = atoi(date.c_str());

	if (date_3 != 1)
		date_3--;
	while (date_1 > 2008)
	{
		while (date_2 > 0)
		{
			while (date_3 > 0)
			{
				for (std::map<std::string, float>::iterator it = ((this->getMapBegin())); it != ((this->getMapEnd())); ++it)
				{
					std::string cmp = it->first;
					int cmp_1 = atoi(cmp.c_str());
					cmp.erase(0, cmp.find("-") + 1);
					int cmp_2 = atoi(cmp.c_str());
					cmp.erase(0, cmp.find("-") + 1);
					int cmp_3 = atoi(cmp.c_str());
					if (cmp_1 == date_1 && cmp_2 == date_2 && cmp_3 == date_3)
						return (it->first);
				}
				date_3--;
			}
			date_2--;
			if (date_2 != 0)
			{
				if (date_1 % 4 == 0 && date_2 == 2)
					date_3 = 29;
				else if (date_2 == 2)
					date_3 = 28;
				else if (date_2 <= 7 && date_2 % 2 == 0)
					date_3 = 30;
				else
					date_3 = 31;
			}
		}
		date_3 = 31;
		date_2 = 12;
		date_1--;
	}
	return (NULL);
}

void	Bitcoin::FindOccurence(std::string date, float value)
{
	std::string date_2;
	for (std::map<std::string, float>::iterator it = ((this->getMapBegin())); it != ((this->getMapEnd())); ++it)
	{
		if (date == it->first)
		{
			std::cout << "value of " << value << " bitcoin at " << it->first << " = " << value * it->second << "." << std::endl;
			return ;
		}
		else
		{
			date_2 = findCloserDate(date);
			std::cout << "Bitcoin value at " << date << " is not in the database" << std::endl;
			std::cout << "Bitcoin value at the closer date we have : " << date_2 << " = " << this->map[date_2] * value << "\n" << std::endl;
			return ;
		}
	}
}

void	Bitcoin::init(std::string str)
{
	time_t now = time(0);
	tm* ltm = localtime(&now);
	std::fstream infile("cmp.txt");
	infile.open(str.c_str(), std::ios::in);
	if (!infile)
		throw Bitcoin::InvalidFile();
	std::ifstream DataBase(str.c_str());
	if (!DataBase.is_open())
		throw Bitcoin::InvalidFile();
	std::string buffer;
	while (std::getline(DataBase, buffer))
	{
		std::stringstream	streamBuf(buffer);
		std::string			date;
		float				value;
		if (std::getline(streamBuf, date, '|') && streamBuf >> value)
		{
			date.erase(date.find(' '));
			if (parseFirstMember(date, 1900 + ltm->tm_year, 1 + ltm->tm_mon, ltm->tm_mday) == 0)
				std::cout << "Invalid date" << std::endl;
			if (parseSecondMemberInput(value) == 1)
			{
				FindOccurence(date, value);
			}
		}
		else
			std::cout << "Bad input -> " << buffer  << "." << std::endl;
	}
	DataBase.close();
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
