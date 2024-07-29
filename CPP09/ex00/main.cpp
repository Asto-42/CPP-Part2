/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:41:53 by jquil             #+#    #+#             */
/*   Updated: 2024/07/25 12:57:31 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Need input file" << std::endl;
		return (0);
	}
	try
	{
		Bitcoin bitcoin("data.csv");
		bitcoin.parseDataBase();
		std::cout << "Data base is valid" << std::endl;
		std::cout << "\nStart searching bitcoin value\n" << std::endl;
		bitcoin.init(argv[1]);

	}
	catch(const std::exception e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
