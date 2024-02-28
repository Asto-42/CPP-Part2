/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:12:17 by jquil             #+#    #+#             */
/*   Updated: 2024/02/15 16:02:16 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	//std::cout << "Default constructor called" << std::endl;
};

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), target("default")
{
	//std::cout << "Default constructor called" << std::endl;
};

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target): AForm("ShrubberyCreationForm", 145, 137), target(target)
{
	//std::cout << "Specific name constructor called" << std::endl;
};

// ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm & y): AForm("ShrubberyCreationForm", 145, 137), target(y.getTarget())
// {
// 	//std::cout << "Copy constructor called" << std::endl;
// 	*this = y;
// }

std::string ShrubberyCreationForm::getTarget(void)const
{
	return (this->target);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor)const
{
	std::ofstream outfile (this->getTarget().append("shrubbery").c_str());
	outfile <<
	"         v" << std::endl <<
	"        >X<" << std::endl <<
	"         A" << std::endl <<
	"        d$b" << std::endl <<
	"      .d\\$$b." << std::endl <<
	"    .d$i$$\\$$b." << std::endl <<
	"       d$$@b" << std::endl <<
	"      d\\$$$ib" << std::endl <<
	"    .d$$$\\$$$b" << std::endl <<
	"  .d$$@$$$$\\$$ib." << std::endl <<
	"      d$$i$$b" << std::endl <<
	"     d\\$$$$@$b" << std::endl <<
	"  .d$@$$\\$$$$$@b." << std::endl <<
	".d$$$$i$$$\\$$$$$$b." << std::endl <<
	"        ###" << std::endl <<
	"        ###" << std::endl <<
	"        ###" << std::endl <<
	std::endl;
	outfile.close();
	std::cout << "Shrubbery has been planted in " << this->getTarget() << "shrubbery by " << executor.getName() << "." << std::endl;
}
