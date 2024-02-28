/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:42:40 by jquil             #+#    #+#             */
/*   Updated: 2024/02/20 15:11:22 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Intern::Intern(void)
{
	std::cout << "Default intern constructor called" << std::endl;
};

Intern::~Intern(void)
{
	std::cout << "Default intern destructor called" << std::endl;
};

static AForm *makePresident(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

static AForm *makeRobot(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm *makeShrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::makeForm(const std::string name, const std::string target)
{
	AForm *(*new_form[])(const std::string target) = {&makePresident, &makeRobot, &makeShrubbery};
	std::string forms[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
	for (int x = 0; x < 3; x++)
	{
		if (name == forms[x])
		{
			std::cout << "Intern create the new form " << name << "with " << target << "as target." << std::endl;
			return (new_form[x](target));
		}
	}
	std::cout << "Form name dont match the library" << std::endl;
	return (NULL);
}
