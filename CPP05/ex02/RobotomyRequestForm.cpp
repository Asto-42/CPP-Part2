/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:11:32 by jquil             #+#    #+#             */
/*   Updated: 2024/02/15 16:01:59 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	//std::cout << "Default constructor called" << std::endl;
};

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), target("default")
{
	//std::cout << "Default constructor called" << std::endl;
};

RobotomyRequestForm::RobotomyRequestForm(const std::string target): AForm("RobotomyRequestForm", 72, 45), target(target)
{
	//std::cout << "Specific name constructor called" << std::endl;
};

// RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm & y): AForm("RobotomyRequestForm", 72, 45), target(y.getTarget())
// {
// 	//std::cout << "Copy constructor called" << std::endl;
// 	*this = y;
// }

std::string RobotomyRequestForm::getTarget(void)const
{
	return (this->target);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor)const
{
	int x = rand();
	std::cout << "Driiiing Driing" << std::endl;
	if (x % 2 == 0)
		std::cout << this->target << " has been robotomized successfully by " << executor.getName() << std::endl;
	else
		std::cout << "The robotomy of " << this->target << " failed (autor : " << executor.getName() << ")." << std::endl;
}
