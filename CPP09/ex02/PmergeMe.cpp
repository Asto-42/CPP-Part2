/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:58:06 by jquil             #+#    #+#             */
/*   Updated: 2024/03/19 12:54:35 by jquil            ###   ########.fr       */
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

int	find_min(int *array, size_t size)
{
	int min = INT_MAX;
	for (size_t x = 0; x <= size - 1; x++)
	{
		if (min > array[x])
			min = array[x];
	}
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

int	*redefine_array(int *array, int min, size_t size)
{
	int *new_array = new int[size];
	int y = 0;
	for (size_t x = 0; x <= size; x++)
	{
		if (array[x] != min)
			new_array[y++] = array[x];
	}
	delete array;
	return (new_array);
}

void	PmergeMe::start_binary_search(void)
{
	int cursor = this->n_s / 2;
	while (this->n_c > 0)
	{
		int x = 0;
		// std::cout << cursor << std::endl;
		if (this->S_list[cursor] < this->C_list[x] && this->S_list[cursor + 1] > this->C_list[x])
		{
			this->S_list.insert(this->S_list.begin() + cursor, this->C_list[x]);
			this->C_list.erase(this->C_list.begin() + x);
			cursor = this->n_s / 2;
			// std::cout << "PUSH" << std::endl;
		}
		else if (this->S_list[cursor] > this->C_list[x] && this->S_list[cursor - 1] < this->C_list[x])
		{
			this->S_list.insert(this->S_list.begin() + cursor, this->C_list[x]);
			this->C_list.erase(this->C_list.begin() + x);
			cursor = this->n_s / 2;
			// std::cout << "PUSH" << std::endl;
		}
		if (C_list[x] == 85 && cursor == 9)
			break;
		else if (this->S_list[cursor] > this->C_list[x])
		{
			cursor = cursor / 2;
		}
		else if (this->S_list[cursor] < this->C_list[x])
		{
			cursor = cursor + cursor / 2;
			if (cursor > (int)this->n_s)
			{
				cursor = this->n_s;
				this->S_list.push_back(this->C_list[x]);
				this->C_list.erase(this->C_list.begin() + x);
			}
		}
		update_vector_size();
		// std::cout << "cursor = " << cursor << std::endl;
		// std::cout << "S_list[cursor] = " << this->S_list[cursor] << "	C_list[x] = " << C_list[x] << "	S_list[cursor - 1] = " << this->S_list[cursor - 1] << std::endl;
	}
	print_vectors();
}

void	PmergeMe::SplitX(void)
{
	int array_size = this->n_c / 2;
	int *array = new int[array_size];
	array = define_array();
	for (size_t y = 0; y <= this->C_list.size(); y++)
	{
		int min = find_min(array, array_size);
		push_back_min(min);
		array_size--;
		update_vector_size();
		if (array_size == 0)
			break;
		array = redefine_array(array, min, array_size);
	}
	print_vectors();
//	start_binary_search();
}

PmergeMe::~PmergeMe(void)
{
	//std::cout << "Default destructor called" << std::endl;
}
