/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:49:37 by jquil             #+#    #+#             */
/*   Updated: 2024/02/15 11:40:39 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

class RobotomyRequestForm:public AForm
{
	private:

	const std::string target;
	RobotomyRequestForm();

	public:

	RobotomyRequestForm(const std::string target);
	//RobotomyRequestForm(const RobotomyRequestForm & y);

	std::string getTarget(void)const;
	void execute(Bureaucrat const &executor)const;

	virtual ~RobotomyRequestForm();
};
#endif
