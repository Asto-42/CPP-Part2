/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:24:53 by jquil             #+#    #+#             */
/*   Updated: 2024/02/14 16:29:17 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

class Form
{
	private:

	const std::string name;
	bool sign;
	const int sign_grade;
	const int exec_grade;

	public:

	Form();
	Form(const std::string n);
	Form(const std::string n, int si_gr);
	Form(const std::string n, int si_gr, int ex_gr);
	Form(const Form & y);

	std::string getName(void)const;
	bool getSignStatus(void)const;
	int getSignGrade(void)const;
	int getExecGrade(void)const;

	void beSigned(Bureaucrat &rhs);

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

	~Form();
};

std::ostream & operator<<(std::ostream & os, Bureaucrat const & rhs);
#endif
