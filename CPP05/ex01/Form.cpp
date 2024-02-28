/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:25:00 by jquil             #+#    #+#             */
/*   Updated: 2024/02/14 17:40:16 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form(void): name("(empty)"), sign_grade(1), exec_grade(1)
{
	//std::cout << "Default constructor called" << std::endl;
	this->sign = 0;
};
Form::Form(const std::string n): name(n), sign_grade(1), exec_grade(1)
{
	//std::cout << "Specific name constructor called" << std::endl;
	this->sign = 0;
};

Form::Form(const std::string n, int si_gr): name(n), sign_grade(si_gr), exec_grade(1)
{
	//std::cout << "Specific name, signature status and signature grade constructor called" << std::endl;
	this->sign = 0;
	if (si_gr < 1)
		throw Form::GradeTooLowException();
	if (si_gr > 150)
		throw Form::GradeTooHighException();
};

Form::Form(const std::string n, int si_gr, int ex_gr): name(n), sign_grade(si_gr), exec_grade(ex_gr)
{
	//std::cout << "Specific name, signature status, signature grade and execution grade constructor called" << std::endl;
	this->sign = 0;
	try
	{
		if (si_gr < 1)
			throw Form::GradeTooLowException();
		else if (si_gr > 150)
			throw Form::GradeTooHighException();
	}
	catch(const Form::GradeTooHighException & e)
	{
		std::cerr << e.what() << std::endl;
		si_gr = 1;
		std::cout << "Signature grade set at 1 by default" << std::endl;
	}
	catch(const Form::GradeTooLowException & e)
	{
		std::cerr << e.what() << std::endl;
		si_gr = 1;
		std::cout << "Signature grade set at 1 by default" << std::endl;
	}
	try
	{
		if (ex_gr < 1)
			throw Form::GradeTooLowException();
		else if (ex_gr > 150)
			throw Form::GradeTooHighException();
	}
	catch(const Form::GradeTooHighException & e)
	{
		std::cerr << e.what() << std::endl;
		ex_gr = 1;
		std::cout << "Execution grade set at 1 by default" << std::endl;
	}
	catch(const Form::GradeTooLowException & e)
	{
		std::cerr << e.what() << std::endl;
		ex_gr = 1;
		std::cout << "Execution grade set at 1 by default" << std::endl;
	}
};

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grades cant be superior to 150\n");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grades cant be inferior to 1\n");
}

Form::Form(const Form & y): name(y.name), sign_grade(y.sign_grade), exec_grade(y.exec_grade)
{
	//std::cout << "Copy constructor called" << std::endl;
	this->sign = y.sign;
}

std::string Form::getName(void)const
{
	return (this->name);
}

bool Form::getSignStatus(void)const
{
	return (this->sign);
}
 int Form::getSignGrade(void)const
{
	return (this->sign_grade);
}
 int Form::getExecGrade(void)const
{
	return (this->exec_grade);
}

void Form::beSigned(Bureaucrat &rhs)
{
	if ((this->exec_grade > 150 || this->exec_grade < 1) || (this->sign_grade > 150 || this->sign_grade < 1))
	{
		std::cout << "Invalid form" << std::endl;
		return ;
	}
	if (rhs.getGrade() > this->getSignGrade())
	{
		std::cout << "The bureaucrat " << rhs.getName() << " can't sign the form " << this->name << " because his grade is too low." << std::endl;
		return ;
	}
	if (this->sign != 1)
	{
		this->sign = 1;
		std::cout << "The bureaucrat " << rhs.getName() << " has signed the form " << this->name << "." << std::endl;
	}
}

Form::~Form(void)
{
	//std::cout << "Default constructor called" << std::endl;
};
