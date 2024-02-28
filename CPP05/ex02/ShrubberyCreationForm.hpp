/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:49:17 by jquil             #+#    #+#             */
/*   Updated: 2024/02/15 11:41:08 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

class ShrubberyCreationForm:public AForm
{
	private:

	const std::string target;
	ShrubberyCreationForm();

	public:

	ShrubberyCreationForm(const std::string target);
	//ShrubberyCreationForm(ShrubberyCreationForm & y);

	std::string getTarget(void)const;
	void execute(Bureaucrat const &executor)const;

	virtual ~ShrubberyCreationForm();
};
#endif
