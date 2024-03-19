/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:58:06 by jquil             #+#    #+#             */
/*   Updated: 2024/03/01 11:53:06 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void)
{
	return ;
};

void RPN::operate_stack(char *str)
{
	std::string			date;
	char *token = std::strtok(str, " ");
	while (token != NULL)
	{
		if (std::isdigit(token[0]) != 0)
			this->_operator.push(atoi(token));
		else if (this->_operator.top() && (token[0] == '+'|| token[0] == '-' || token[0] == '/' || token[0] == '*'))
			this->execute_operator(token[0]);
		else
		{
			std::cout << "expression invalid, too much operator" << std::endl;
			std::cout << "Actual result = " << this->_operator.top();
			std::cout << "Remaining operator : ";
			while (token != NULL)
			{
				std::cout << token[0] << " ";
				token = std::strtok(NULL, " ");
			}
			std::cout << std::endl;
			return ;
		}
		token = std::strtok(NULL, " ");
	}
	std::cout << "Reverse polish expression result = "<< this->_operator.top() << std::endl;
}

void	RPN::execute_operator(char c)
{
	int x = this->_operator.top();
	this->_operator.pop();
	int y = this->_operator.top();
	this->_operator.pop();
	if (c == '+')
		this->_operator.push(y + x);
	else if (c == '-')
		this->_operator.push(y - x);
	else if (c == '*')
		this->_operator.push(y * x);
	else
	{
		if (x != 0)
			this->_operator.push(y / x);
		else
			std::cout << "Division by 0" << std::endl;
	}
}

RPN::~RPN(void)
{
	//std::cout << "Default destructor called" << std::endl;
}
