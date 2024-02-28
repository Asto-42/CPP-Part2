/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:03:09 by jquil             #+#    #+#             */
/*   Updated: 2024/02/20 20:11:59 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void)
{
	//std::cout << "Default constructor called" << std::endl;
};

Serializer::Serializer(const Serializer & y)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = y;
};

Serializer	&Serializer::operator=( const Serializer &rhs)
{
	(void)rhs;
	return (*this);
};

uintptr_t	Serializer::serialize( Data *data )
{
	return (reinterpret_cast<uintptr_t>(data));
}

Data	*Serializer::deserialize( uintptr_t ptr )
{
	return (reinterpret_cast<Data *>(ptr));
}

Serializer::~Serializer(void)
{
	//std::cout << "Default destructor called" << std::endl;
};
