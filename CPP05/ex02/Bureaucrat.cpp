/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:45:20 by jquil             #+#    #+#             */
/*   Updated: 2024/02/15 16:33:28 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void)
{
	//std::cout << "Default constructor called" << std::endl;
	this->name = "(empty)";
	this->grade = 150;
};


Bureaucrat::Bureaucrat(std::string n)
{
	//std::cout << "Specific name constructor called" << std::endl;
	this->name = n;
	this->grade = 150;
};

Bureaucrat::Bureaucrat(std::string n, int gr)
{
	//std::cout << "Specific name and grade constructor called" << std::endl;
	this->name = n;
	try
	{
		if (gr > 150)
		{
			throw Bureaucrat::GradeTooHighException();
		}
		else if (gr < 1)
		{
			throw Bureaucrat::GradeTooLowException();
		}
		else
			this->grade = gr;
	}
	catch(const Bureaucrat::GradeTooHighException & e)
	{
		std::cerr << e.what() << std::endl;
		this->grade = 150;
		std::cout << "Grade set at 150 by default" << std::endl;
	}
	catch(const Bureaucrat::GradeTooLowException & e)
	{
		std::cerr << e.what() << std::endl;
		this->grade = 150;
		std::cout << "Grade set at 150 by default" << std::endl;
	}
};

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade cant be superior to 150\n");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade cant be inferior to 1\n");
}

Bureaucrat::Bureaucrat(const Bureaucrat & y)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = y;
}

std::string Bureaucrat::getName(void)const
{
	return (this->name);
}

int Bureaucrat::getGrade(void)const
{
	return (this->grade);
}

void Bureaucrat::incr_grade(void)
{
	try
	{
		if (this->grade == 1)
			throw Bureaucrat::GradeTooLowException();
		else
			this->grade--;
	}
	catch(const Bureaucrat::GradeTooLowException & e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void Bureaucrat::decr_grade(void)
{
	try
	{
		if (this->grade == 150)
			throw Bureaucrat::GradeTooHighException();
		else
			this->grade++;
	}
	catch(const Bureaucrat::GradeTooHighException & e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		if (form.getExecGrade() > this->getGrade() && form.getSignStatus() == 1)
		{
			std::cout << this->getName() << " execute the form " << form.getName() << "." << std::endl;
			form.execute(*this);
		}
		else if (form.getSignStatus() == 1)
			throw Bureaucrat::GradeLowException();
		else
			throw Bureaucrat::NotSignedException();
	}
	catch(const Bureaucrat::GradeLowException)
	{
		std::cout << this->getName() << " can't execute " << form.getName() << " because his grade is too low." << std::endl;
	}
	catch(const Bureaucrat::NotSignedException)
	{
		std::cout << form.getName() << " can't be executed because he is not signed." << std::endl;
	}

}

Bureaucrat::~Bureaucrat(void)
{
	//std::cout << "Default constructor called" << std::endl;
};

