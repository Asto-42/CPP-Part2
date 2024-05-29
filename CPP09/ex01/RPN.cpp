/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:58:06 by jquil             #+#    #+#             */
/*   Updated: 2024/05/29 11:39:59 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void)
{
	return ;
};

void	RPN::invalid_expression(char *token)
{
	std::cout << "expression invalid, too much operator" << std::endl;
	if (this->_operator.size() > 0)
		std::cout << "Actual result = " << this->_operator.top();
	while (token != NULL)
	{
		std::cout << "Remaining operator : ";
		std::cout << token[0] << " ";
		token = std::strtok(NULL, " ");
	}
	std::cout << std::endl;
	return ;
}

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
			this->invalid_expression(token);
			return ;
		}
		token = std::strtok(NULL, " ");
	}
	if (this->_operator.size() != 0)
		std::cout << "Reverse polish expression result = "<< this->_operator.top() << std::endl;
	else
		this->invalid_expression(token);

}

void	RPN::execute_operator(char c)
{
	int x = this->_operator.top();
	this->_operator.pop();
	if (this->_operator.size() > 1)
	{
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
}

RPN::~RPN(void)
{
	//std::cout << "Default destructor called" << std::endl;
}
