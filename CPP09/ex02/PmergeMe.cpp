/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:58:06 by jquil             #+#    #+#             */
/*   Updated: 2024/03/03 15:31:44 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
	return ;
};

struct PrintNumber
{
	void operator()(const int n) const
	{
		std::cout << n << ' ';
	}
};

void	PmergeMe::print_vectors(void)
{
	if (this->C_list.empty() == 0)
	{
		std::cout << std::endl;
		std::cout << "C list =	";
		std::for_each(this->C_list.begin(), this->C_list.end(), PrintNumber());
		std::cout << "	size : " << this->n_c << std::endl;
		std::cout << std::endl;
	}
	if (this->S_list.empty() == 0)
	{
		std::cout << "S list =	";
		std::for_each(this->S_list.begin(), this->S_list.end(), PrintNumber());
		std::cout << "	size : " << this->n_s << std::endl;
	}
}

PmergeMe::PmergeMe(unsigned int size, char **argv)
{
	this->n_c = size;
	for (size_t x = 1; x <= this->n_c; x++)
		this->C_list.push_back(atoi(argv[x]));
	std::for_each(this->C_list.begin(), this->C_list.end(), PrintNumber());
	std::cout << "\n" << std::endl;
};

void	PmergeMe::start_sort(void)
{
	this->SplitX();
}

void	PmergeMe::update_vector_size(void)
{
	this->n_c = this->C_list.size();
	this->n_s = this->S_list.size();
}

void	PmergeMe::start_binary_search(void)
{
	//this->S_list.push_back(this->C_list[array[pos]]);
	//this->C_list.insert(0, this->S_list[0]);
}

int	find_min(int *array, size_t size)
{
	int min = INT_MAX;
	std::cout << "size = " <<  size << std::endl;
	for (size_t x = 0; x < size; x++)
	{
		if (min > array[x])
			min = array[x];
	}
	std::cout << min << std::endl;
	return (min);
}

void	PmergeMe::push_back_min(int min)
{
	for (size_t x = 0; x < this->n_c; x++)
	{
		if (this->C_list[x] == min)
		{
			this->S_list.push_back(this->C_list[x]);
			this->C_list.erase(this->C_list.begin() + x);
		}
	}
}

int *	PmergeMe::define_array(void)
{
	int *array = new int[this->n_c / 2];
	//int array[this->n_c / 2];
	size_t y = 0;
	for (size_t x = 0; x <= this->n_c; x += 2)
	{
		if (x >= this->n_c || x + 1 >= this->n_c)
			break;
		if (this->C_list[x] <= this->C_list[x + 1])
			array[y] = this->C_list[x];
		else
			array[y] = this->C_list[x + 1];
		y++;
	}
	return (array);
}

int	*PmergeMe::redefine_array(int *array, int min, size_t size)
{
	int *new_array = new int[this->n_c / 2 - size];
	int y = 0;
	for (size_t x = 0; x < this->n_c / 2; x++)
	{
		if (array[x] != min)
		{
			std::cout << "Array[x] = " << array[x] << "	min = " << min << std::endl;
			new_array[y++] = array[x];
		}
	}
	delete array;
	return (new_array);
}

void	PmergeMe::SplitX(void)
{
	int *array = new int[this->n_c / 2];
	array = define_array();
	//update the push method to push in croissant order
	//std::cout << "C list =	";
	//std::for_each(this->C_list.begin(), this->C_list.end(), PrintNumber());
	for (size_t x = 0; x < this->n_c / 2; x++)
	{
		std::cout << "Array[x] = " << array[x] << std::endl;
	}
	//sort array in reverse order
	for (size_t y = 0; y <= this->C_list.size(); y++)
	{
		int min = find_min(array, this->n_c / 2 - y);
		push_back_min(min);
		update_vector_size();
		array = redefine_array(array, min, this->n_c / 2 - y);
		// for (size_t x = 0; x < this->n_c / 2 - y; x++)
		// {
		// 	std::cout << "Array[x] = " << array[x] << std::endl;
		// }
	}
	print_vectors();
}

PmergeMe::~PmergeMe(void)
{
	//std::cout << "Default destructor called" << std::endl;
}
