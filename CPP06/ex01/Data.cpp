/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:06:59 by jquil             #+#    #+#             */
/*   Updated: 2024/02/20 20:10:41 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Data::Data(void)
{
	//std::cout << "Default Data constructor called" << std::endl;
};

Data::~Data( void )
{
	//std::cout << "Default Data destructor called" << std::endl;
}

Data::Data( const Data &rhs)
{
	(void)rhs;
};

Data	&Data::operator=( const Data &rhs)
{
	(void)rhs;
	return (*this);
};
