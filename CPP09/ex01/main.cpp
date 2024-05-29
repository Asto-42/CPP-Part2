/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:41:53 by jquil             #+#    #+#             */
/*   Updated: 2024/05/29 10:40:17 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

//"8 9 * 9 - 9 - 9 - 4 - 1 +"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Invalid argument(s)" << std::endl;
		return (0);
	}
	std::cout << "Reverse polish expression : " << argv[1] << std::endl;
	RPN lst;
	lst.operate_stack(argv[1]);
	return (0);
}
