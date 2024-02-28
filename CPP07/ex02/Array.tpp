/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:18:54 by jquil             #+#    #+#             */
/*   Updated: 2024/02/23 14:57:57 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->len = 0;
	this->array = NULL;
};

template <typename T>
Array<T>::Array(unsigned int n)
{
	std::cout << "Specific size constructor called" << std::endl;
	this->len = n;
	this->array = new T[n];
};

template <typename T>
Array<T> & Array<T>::operator=(const Array &ref)
{
	for(unsigned int i = 0; i < this->len; i++)
	{
		if (ref.array[i])
			this->array[i] = ref.array[i];
	}
	return (*this);
};

template <typename T>
T & Array<T>::operator[](unsigned int memb)
{

	if (memb > this->size())
		throw Array<T>::MembOutOfRangeException();
	return (this->array[memb]);
};

template <typename T>
const char *Array<T>::MembOutOfRangeException::what() const throw()
{
	return ("Asked array is out of range");
}

template <typename T>
unsigned int Array<T>::size(void)
{
	return (this->len);
};

template <typename T>
Array<T>::Array(const Array & y)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = y;
};

template <typename T>
Array<T>::~Array(void)
{
	//std::cout << "Default destructor called" << std::endl;
	delete[] array;
};
