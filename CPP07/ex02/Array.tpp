/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:18:54 by jquil             #+#    #+#             */
/*   Updated: 2024/06/11 13:16:51 by jquil            ###   ########.fr       */
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
	if (!this->array)
		throw std::exception();
};

template<typename T>
Array<T> &Array<T>::operator=(Array<T> const &rhs)
{
	if (this != &rhs)
	{
		if (this->array)
			delete this->array;
		this->len = rhs.len;
		if (this->len == 0)
			this->array = NULL;
		else
		{
			this->array = new T[this->len];
			if (!this->array)
				throw std::exception();
			for (unsigned int i = 0; i < this->len; i++)
				this->array[i] = rhs.array[i];
		}
	}
	std::cout << "Assignment Operator called: Array" << std::endl;
	return (*this);
}

template <typename T>
T & Array<T>::operator[](unsigned int memb)
{

	if (memb >= this->size())
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
Array<T>::Array(const Array & rhs)
{
	//std::cout << "Copy constructor called" << std::endl;
	this->len = rhs.len;
	if (this->len == 0)
	{
		this->array = NULL;
		return ;
	}
	else
	{
		this->array = new T[this->len];
		if (!this->array)
			throw std::exception();
		for (unsigned int i = 0; i < this->len; i++)
			this->array[i] = rhs.array[i];
	}
};

template <typename T>
Array<T>::~Array(void)
{
	//std::cout << "Default destructor called" << std::endl;
	delete[] array;
};
