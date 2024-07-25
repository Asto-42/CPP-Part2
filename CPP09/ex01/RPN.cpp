/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:58:06 by jquil             #+#    #+#             */
/*   Updated: 2024/07/25 13:01:33 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

std::stack<int>& Rpn::getObjS()
{
	return (this->objS);
}

Rpn::Rpn()
{
	std::cout << "Default constructor called for RPN" << std::endl;
}

Rpn::~Rpn()
{
	std::cout << "Default deconstructor called for RPN" << std::endl;
}

Rpn::Rpn(Rpn const& instance)
{
	std::cout << "Copy constructor called for RPN" << std::endl;
	this->objS = instance.objS;
}

Rpn&	Rpn::operator=(Rpn const& instance)
{
	std::cout << "Operator called for RPN" << std::endl;
	if (this != &instance)
	{
		for (size_t i = 0; i < objS.size(); i++)
			this->objS.pop();
		this->objS = instance.objS;
	}
	return (*this);
}
