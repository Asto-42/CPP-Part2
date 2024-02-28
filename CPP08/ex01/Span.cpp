/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:45:48 by jquil             #+#    #+#             */
/*   Updated: 2024/02/28 14:06:56 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void)
{
	this->size = 0;
};

Span::Span(unsigned int n)
{
	this->size = n;
};

Span & Span::operator=(const Span &ref)
{
	for (unsigned int x = 0; x < this->size; x++)
	{
		if (ref.array[x] && x < this->size)
			this->array[x] = ref.array[x];
	}
	return (*this);
}

int & Span::operator[](unsigned int memb)
{
	if (memb > this->size - 1)
		throw Span::MembOutOfRangeException();
	return (this->array[memb]);
}

const char *Span::MembOutOfRangeException::what() const throw()
{
	return ("Asked array is out of range");
}

unsigned int Span::getSize(void)
{
	return (this->size);
}

void Span::AddNumber(int nb)
{
	this->array.push_back(nb);
}

unsigned int Span::shortestSpan(void)
{
	unsigned int min_1 = this->array[0];
	unsigned int min_2 = this->array[1];
	for (unsigned int y = 0; y < this->getSize(); y++)
	{
		for (unsigned int x = 1; x < this->getSize(); x++)
		{
			if ((this->array[y] - this->array[x] > 0) && ((unsigned int)(this->array[y] - this->array[x]) < min_1 - min_2))
			{
				min_1 = this->array[y];
				min_2 = this->array[x];
				x = 0;
			}
		}
	}
	if (min_1 > min_2)
		return (min_1 - min_2);
	return (min_2 - min_1);
}

unsigned int Span::longestSpan(void)
{
	int min_span = INT_MAX;
	int max_span = 0;
	for (unsigned int x = 0; x < this->size; x++)
	{
		if (this->array[x] < min_span)
			min_span = this->array[x];
		if (this->array[x] > max_span)
			max_span = this->array[x];
	}
	return (max_span - min_span);
}
