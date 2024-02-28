/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:40:10 by jquil             #+#    #+#             */
/*   Updated: 2024/02/28 18:45:15 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_HPP
# define BITCOIN_HPP

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
#include <map>
#include <sstream>
#include <ctime>

class Bitcoin
{
	private :

	std::map<std::string, float> map;
	std::string file_name;
	unsigned int size;

	Bitcoin();
	Bitcoin & operator=(const Bitcoin &rhs);
	Bitcoin(Bitcoin &rhs);

	public :

	Bitcoin(std::string file_name);
	~Bitcoin();

	void	printmap(void);
	std::map<std::basic_string<char>, float>::iterator	getMapBegin(void);
	std::map<std::basic_string<char>, float>::iterator	getMapEnd(void);
	void	parseDataBase(void);
	//void createDataBase(void);
	/*
		void	handleInput();
		void	createDatabase();
		bool	checkDate(std::string date);
		float	getValueAtDate(std::string date);
		void	priceConversion(std::string date, float value);
	*/

	class InvalidFile:public std::exception
	{
		public :

		virtual const char *what() const throw();
	};

	class InvalidDate:public std::exception
	{
		public :

		virtual const char *what() const throw();
	};

	class InvalidValue:public std::exception
	{
		public :

		virtual const char *what() const throw();
	};
};
#endif
