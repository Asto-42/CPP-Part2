/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:44:58 by jquil             #+#    #+#             */
/*   Updated: 2024/02/15 16:31:44 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

std::ostream & operator<<(std::ostream & os, Bureaucrat const & rhs)
{
	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << "." << std::endl;
	return (os);
}

std::ostream & operator<<(std::ostream & os, AForm const & rhs)
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
	std::srand(time(0));
	Bureaucrat jean("Jean", 50);
	Bureaucrat max("Max", 1);

	PresidentialPardonForm PRF("PRF");
	operator<<(std::cout , PRF);

	RobotomyRequestForm RRF("RRF");
	operator<<(std::cout, RRF);

	ShrubberyCreationForm SCF("SCF");
	operator<<(std::cout, SCF);
	std::cout << std::endl;


	std::cout << "\n		//// Bureaucrat exec form part \\\\\n" << std::endl;
	jean.executeForm(PRF);
	max.executeForm(PRF);
	PRF.beSigned(jean);
	PRF.beSigned(max);
	jean.executeForm(PRF);
	max.executeForm(PRF);
	std::cout << "\n" << std::endl;
	jean.executeForm(RRF);
	max.executeForm(RRF);
	RRF.beSigned(jean);
	RRF.beSigned(max);
	jean.executeForm(RRF);
	max.executeForm(RRF);
	std::cout << "\n" << std::endl;
	jean.executeForm(SCF);
	max.executeForm(SCF);
	SCF.beSigned(jean);
	SCF.beSigned(max);
	jean.executeForm(SCF);
	max.executeForm(SCF);

// 	std::cout << "		//// Form exec part \\\\" << std::endl;
// 	PRF.execute(jean);
// 	PRF.execute(max);
// 	PRF.beSigned(jean);
// 	PRF.beSigned(max);
// 	PRF.execute(jean);
// 	PRF.execute(max);
// 	std::cout << std::endl;

// 	RRF.execute(jean);
// 	RRF.beSigned(jean);
// 	RRF.beSigned(max);
// 	RRF.execute(jean);
// 	RRF.execute(max);
// 	std::cout << std::endl;


// 	SCF.execute(jean);
// 	SCF.beSigned(jean);
// 	SCF.beSigned(max);
// 	SCF.execute(jean);
// 	SCF.execute(max);
}
