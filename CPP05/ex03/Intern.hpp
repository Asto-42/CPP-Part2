/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:39:40 by jquil             #+#    #+#             */
/*   Updated: 2024/02/20 14:34:20 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

class Intern
{
	private:

	Intern();
	~Intern();
	public:

	AForm* makeForm(const std::string name, std::string target);
};
#endif
