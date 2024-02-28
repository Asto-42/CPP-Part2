/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:44:58 by jquil             #+#    #+#             */
/*   Updated: 2024/02/14 17:34:56 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

std::ostream & operator<<(std::ostream & os, Bureaucrat const & rhs)
{
	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << "." << std::endl;
	return (os);
}

std::ostream & operator<<(std::ostream & os, Form const & rhs)
{
	os << "Form " << rhs.getName();
	if (rhs.getSignStatus() == 1)
		os << " is signed ";
	else
		os << " is not signed ";
	os << ", signature grade requiered " << rhs.getSignGrade();
	os << ", execution grade requiered " << rhs.getExecGrade();
	os << "." << std::endl;
	return (os);
}

int	main(void)
{
	std::cout << "		///	Jean & C45 test part	///\n" << std::endl;
	Bureaucrat jean("Jean", 50);

	Form C45("C45", 25, 49);

	operator<<(std::cout, jean);
	operator<<(std::cout, C45);
	C45.beSigned(jean);
	operator<<(std::cout, C45);
	while (jean.getGrade() > 25)
		jean.incr_grade();
	C45.beSigned(jean);
	operator<<(std::cout, C45);

	std::cout << "\n\n		///	B29 test part	///\n" << std::endl;
	Form B29("B29", 255, 489);
	operator<<(std::cout, B29);
	B29.beSigned(jean);
	operator<<(std::cout, B29);
}
