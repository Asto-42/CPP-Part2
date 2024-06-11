/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:45:48 by jquil             #+#    #+#             */
/*   Updated: 2024/05/28 16:53:05 by jquil            ###   ########.fr       */
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

Span::Span(const Span & y)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = y;
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

void Span::AddMultipleNumber(std::vector<int> vctr)
{
	if (this->array.size() + vctr.size() > this->getSize())
		throw Span::CantAddNumberException();
	this->array.insert(this->array.end(), vctr.begin(), vctr.end());
}

void Span::AddNumber(int nb)
{
	if (this->array.size() == this->getSize())
		throw Span::CantAddNumberException();
	else
		this->array.push_back(nb);
}

const char *Span::CantAddNumberException::what() const throw()
{
	return ("Cant add data in array after init");
}

const char *Span::NoSpanException::what() const throw()
{
	return ("Array only contains one data");
}

int Span::shortestSpan(void)
{
	if (this->array.size() < 2)
		throw Span::NoSpanException();
	sort(this->array.begin(), this->array.end());
	unsigned int min_1 = this->array[0];
	unsigned int min_2 = this->array[1];
	for (unsigned int x = 0; x < this->array.size() - 1; x++)
	{
		if (((unsigned int)(this->array[x + 1] - this->array[x]) < min_1 - min_2))
		{
			min_1 = this->array[x + 1];
			min_2 = this->array[x];
		}
	}
	return (min_1 - min_2);
}


int Span::longestSpan(void)
{
	if (this->array.size() < 2)
		throw Span::NoSpanException();
	sort(this->array.begin(), this->array.end());
	int min = *this->array.begin();
	int max = *this->array.rbegin();
	return (max - min);
}

void	Span::compare_value(int longest)
{
	int long_cmp;

	//LONG PART
	int min = INT_MAX;
	int max = 0;
	for (std::vector<int>::iterator it = this->array.begin(); it != this->array.end(); ++it)
	{
		if (*it < min)
			min = *it;
		if (*it > max)
			max = *it;
	}
	long_cmp = max - min;

	std::cout << "\nManual calcul :\n\n";
	std::cout << "Longest Span = " << long_cmp << "\n";

	std::cout << "Longest diff = " << longest - long_cmp << "\n";
}
