/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:06:33 by jquil             #+#    #+#             */
/*   Updated: 2024/02/15 16:01:25 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	//std::cout << "Default constructor called" << std::endl;
};

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), target("default")
{
	//std::cout << "Default constructor called" << std::endl;
};

PresidentialPardonForm::PresidentialPardonForm(const std::string target): AForm("PresidentialPardonForm", 25, 5), target(target)
{
	//std::cout << "Specific name constructor called" << std::endl;
};

// PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm & y): AForm("PresidentialPardonForm", 25, 5), target(y.getTarget())
// {
// 	//std::cout << "Copy constructor called" << std::endl;
// 	*this = y;
// }

std::string PresidentialPardonForm::getTarget(void)const
{
	return (this->target);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor)const
{
	std::cout << executor.getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
