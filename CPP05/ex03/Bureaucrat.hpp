/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:45:11 by jquil             #+#    #+#             */
/*   Updated: 2024/02/15 16:43:34 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <ios>
#include <algorithm>
#include <vector>
#include <math.h>
#include <time.h>

class AForm;

class Bureaucrat
{
	private:

	std::string name;
	int grade;

	public:

	Bureaucrat();
	Bureaucrat(std::string n);
	Bureaucrat(std::string n, int gr);
	Bureaucrat(const Bureaucrat & y);

	std::string getName(void)const;
	int getGrade(void)const;

	void incr_grade(void);
	void decr_grade(void);
	void executeForm(AForm const & form);

	class GradeTooHighException:public std::exception
	{
		public :

		virtual const char *what() const throw();
	};

	class GradeTooLowException:public std::exception
	{
		public :

		virtual const char *what() const throw();
	};

	class GradeLowException:public std::exception
	{
		public :
	};

	class NotSignedException:public std::exception
	{
		public :
	};

	~Bureaucrat();
};

#include "AForm.hpp"
#include "Intern.hpp"
std::ostream & operator<<(std::ostream & os, Bureaucrat const & rhs);
std::ostream & operator<<(std::ostream & os, AForm const & rhs);
#endif
