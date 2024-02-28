/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:36:02 by jquil             #+#    #+#             */
/*   Updated: 2024/02/20 20:34:34 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data		*data = new Data;
	uintptr_t	ptr = 0;

	data->str = "Lets test this";
	data->num = 42;
	std::cout << "Before :" << std::endl;
	std::cout << "data->str: " << data->str << std::endl;
	std::cout << "data->num: " << data->num << std::endl;
	std::cout << "data ptr: " << data << std::endl;

	std::cout << "\n\nSerialization" << std::endl;
	std::cout << "data Ptr->" << (uintptr_t)data << std::endl;
	std::cout << "Ptr before serialize->" << ptr <<std::endl;
	ptr = Serializer::serialize(data);
	std::cout << "Serialized Ptr->" << ptr << std::endl;

	std::cout << "\n\nDeserialisation" << std::endl;
	Data *data2 = new Data;
	data2 = Serializer::deserialize(ptr);
	std::cout << "After : " << std::endl;
	std::cout << "data2->str : " << data2->str << std::endl;
	std::cout << "data2->num : " << data2->num << std::endl;
	std::cout << "data2->ptr : " << data2 << std::endl;
	delete data;
	return (0);
}
