/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:49:48 by jquil             #+#    #+#             */
/*   Updated: 2024/02/15 11:40:25 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

class PresidentialPardonForm:public AForm
{
	private:

	const std::string target;
	PresidentialPardonForm();

	public:

	PresidentialPardonForm(const std::string target);
	//PresidentialPardonForm(PresidentialPardonForm & y);

	std::string getTarget(void)const;
	void execute(Bureaucrat const &executor)const;

	virtual ~PresidentialPardonForm();
};
#endif
