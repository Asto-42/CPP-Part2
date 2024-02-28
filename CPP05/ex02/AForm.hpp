/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:24:53 by jquil             #+#    #+#             */
/*   Updated: 2024/02/15 16:25:01 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

class AForm
{
	protected:

	const std::string name;
	bool sign;
	const int sign_grade;
	const int exec_grade;
	AForm();
	AForm(const std::string n);
	AForm(const std::string n, int si_gr);
	AForm(const std::string n, int si_gr, int ex_gr);
	AForm(const AForm & y);

	public:


	virtual std::string getName(void)const;
	virtual bool getSignStatus(void)const;
	virtual int getSignGrade(void)const;
	virtual int getExecGrade(void)const;
	virtual void beSigned(Bureaucrat &rhs);
	virtual void execute(Bureaucrat const &executor)const;

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

	virtual ~AForm();
};
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#endif
