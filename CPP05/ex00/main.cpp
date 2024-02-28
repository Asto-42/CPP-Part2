/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:44:58 by jquil             #+#    #+#             */
/*   Updated: 2024/02/14 15:19:24 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

std::ostream & operator<<(std::ostream & os, Bureaucrat const & rhs)
{
	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << "." << std::endl;
	return (os);
}

int	main(void)
{
	Bureaucrat jean("jean", 50);

	operator<<(std::cout, jean);
	jean.incr_grade();
	operator<<(std::cout, jean);
	jean.decr_grade();
	operator<<(std::cout, jean);
	for (int x = 0; x < 50; x++)
		jean.incr_grade();
	operator<<(std::cout, jean);
	jean.incr_grade();

	Bureaucrat maxime("maxime", -10);
	operator<<(std::cout, maxime);

}
