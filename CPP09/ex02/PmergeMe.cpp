/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:58:06 by jquil             #+#    #+#             */
/*   Updated: 2024/03/19 18:57:35 by jquil            ###   ########.fr       */
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
		std::cout << n << std::setw(5);
	}
};

struct Printpair
{
	void operator()(const int n) const
	{
		std::cout << n << std::setw(5);
	}
};

template <typename T>
void	print_vector(T &tmp, int size, std::string c)
{
	std::vector<int> lst;
	for (int x = 0; x < size; x++)
		lst.push_back(tmp[x].value);
	std::vector<int> lst2;
	for (int x = 0; x < size; x++)
		lst2.push_back(tmp[x].pair);
	if (lst.empty() == 0)
	{
		std::cout << std::endl;
		std::cout << c << " =	";
		std::for_each(lst.begin(), lst.end(), PrintNumber());
		std::cout << std::endl;
		std::cout << "	";
		std::for_each(lst2.begin(), lst2.end(), Printpair());
		//std::cout << "\n	size : " << lst.size() << std::endl;
		std::cout << std::endl;
	}
}

/*
10 32 45 65 64 76 87 335 157 158 56 445 223 844 25 85

C list =        10 45 64 87 157 56 223 25       size : 8

S list =        32 65 76 85 158 335 445 844     size : 8
10 32 45 65 64 76 87 335 157 158 56 445 223 844 25 85
10 45 64 87 157 56 223 25 // 32 65 76 335 158 445 844 85
32 76 158 85 // 32 65 76 335 445 844
65 445 // 65 335 445 844
*/

unsigned int jacobsthal(unsigned int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

template <typename T>
void	SplitX2(T &lst)
{
	T main;
	T tmp;
	std::cout << "			New recurs" << std::endl;
	for (size_t x = 0; x < lst.size(); x+= 2)
	{
		if (lst[x].value > lst[x + 1].value)
			std::swap(lst[x].value, lst[x + 1].value);
	}
	if (lst.size() > 2)
	{
		int y = 0;
		for (size_t x = 0; x < lst.size(); x += 2)
		{

			tmp.push_back(lst[x + 1]);
				tmp[y].pair = y;
			main.push_back(lst[x]);
			main[y].pair = lst[x + 1].value;
			y++;
		}
		SplitX2(tmp);
		for (size_t x = 0; x < main.size(); x++)
		{
			if (main[x].pair == tmp[0].value)
			{
				tmp.insert(tmp.begin(), main[x]);
				main.erase(main.begin() + x);
				break ;
			}
		}
		print_vector(main, main.size(), "main");
		print_vector(tmp, tmp.size(), "tmp");
		std::cout << "\n" << std::endl;
		std::cout << main.size() << std::endl;
		while (main.size() > 0 && main.size() < 5000)
		{
			size_t y = 0;
			while (y < main.size() && main.size() < 5000)
			{
				for (size_t x = 0; x < tmp.size(); x++)
				{
					if (tmp[x].value == main[y].pair)
					{
						//bad dicotomie, need to check -> x = max of comp
						std::cout << "Here	" << tmp[x].value << "	" << main[y].pair << std::endl;
						if (tmp[x - 1].value < main[y].value && tmp[x].value > main[y].value)
						{
							tmp.insert(tmp.begin() + x, main[y]);
							main.erase(main.begin() + y);
							break ;
						}
						x = x / 2;
						bool push = 0;
						std::cout << "start dico\n" << x << "	" << y << std::endl;
						print_vector(main, main.size(), "main");
						print_vector(tmp, tmp.size(), "tmp");
						int nb = 0;
						while (push == 0 && nb < 10)
						{
							x1 = x;
							x2 = 0;
							nb++;
							if (x == 0)
							{
								tmp.insert(tmp.begin(), main[y]);
								main.erase(main.begin() + y);
								push = 1;
							}
							if (tmp[x - 1].value < main[y].value && tmp[x].value > main[y].value)
							{
								tmp.insert(tmp.begin() + x, main[y]);
								main.erase(main.begin() + y);
								push = 1;
							}
							if (tmp[x].value > main[y].value && tmp[x + 1].value > main[y].value)
								x = x / 2;
							else
								x = x + tmp.size() / 2;
							std::cout << x << std::endl;
						}
						print_vector(tmp, tmp.size(), "tmp");
						//exit (0);
						break ;
					}
				}
				y++;
			}
		}



		// size_t main_size = main.size();
		// for (size_t x = 0; x < main_size; x++)
		// {
		// 	size_t y = 0;
		// 	size_t index = 0;
		// 	for (; jacobsthal(y) < x; y++) {}
		// 	if (y)
		// 	{
		// 		if (jacobsthal(y) >= main_size - 1)
		// 			index = main_size - (x - jacobsthal(y - 1));
		// 		else
		// 			index = jacobsthal(y) + 1 - (x - jacobsthal(y - 1));
		// 	}
		// 	binarySearchInsert(tmp, main[index]);
		// }
		// lst = tmp;
	}
	// else
	// 	exit (0);
}
template <typename T>
void	SplitX(T &lst)
{
	T main;
	T tmp;
	if (lst.size() >= 2)
	{
		int y = 0;
		for (size_t x = 0; x < lst.size(); x += 2)
		{

			if (lst[x].value > lst[x + 1].value)
				std::swap(lst[x].value, lst[x + 1].value);
			tmp.push_back(lst[x + 1]);
			if (tmp[y].pair == 0)
				tmp[y].pair = y;
			main.push_back(lst[x]);
			if (main[y].pair == 0)
				main[y].pair = lst[x + 1].value;
			y++;
		}
		print_vector(main, main.size(), "main");
		print_vector(tmp, main.size(), "tmp");
		SplitX2(tmp);
		for (size_t x = 0; x < main.size(); x++)
		{
			if (main[x].pair == tmp[0].value)
			{
				tmp.push_back(main[x]);
				main.erase(main.begin() + x);
				std::cout << "oui	" << main[x].value << std::endl;
			}
		}
		// push the paire of the min of big -> devant
		// size_t main_size = main.size();
		// for (size_t x = 0; x < main_size; x++)
		// {
		// 	size_t y = 0;
		// 	size_t index = 0;
		// 	for (; jacobsthal(y) < x; y++) {}
		// 	if (y)
		// 	{
		// 		if (jacobsthal(y) >= main_size - 1)
		// 			index = main_size - (x - jacobsthal(y - 1));
		// 		else
		// 			index = jacobsthal(y) + 1 - (x - jacobsthal(y - 1));
		// 	}
		// 	binarySearchInsert(tmp, main[index]);
		// }
		//lst = tmp;
	}
	print_vector(main, main.size(), "main");
	print_vector(tmp, main.size(), "tmp");
}

PmergeMe::PmergeMe(unsigned int size, char **argv)
{
	this->n_c = size;
	t_pair pair;
	for (size_t x = 1; x <= this->n_c; x++)
	{
		pair.value = atoi(argv[x]);
		pair.pair = 0;
		this->C_list.push_back(pair);
	}
	std::cout << "\n" << std::endl;
	SplitX(this->C_list);
	//print_vector(this->C_list, size);
};

// int	find_min(int *array, size_t size)
// {
// 	int min = INT_MAX;
// 	for (size_t x = 0; x <= size - 1; x++)
// 	{
// 		if (min > array[x])
// 			min = array[x];
// 	}
// 	return (min);
// }

// void	PmergeMe::push_back_min(int min)
// {
// 	for (size_t x = 0; x < this->n_c; x++)
// 	{
// 		if (this->C_list[x] == min)
// 		{
// 			this->S_list.push_back(this->C_list[x]);
// 			this->C_list.erase(this->C_list.begin() + x);
// 		}
// 	}
// }

// int *	PmergeMe::define_array(void)
// {
// 	int *array = new int[this->n_c / 2];
// 	size_t y = 0;
// 	for (size_t x = 0; x <= this->n_c; x += 2)
// 	{
// 		if (x >= this->n_c || x + 1 >= this->n_c)
// 			break;
// 		if (this->C_list[x] <= this->C_list[x + 1])
// 			array[y] = this->C_list[x + 1];
// 		else
// 			array[y] = this->C_list[x];
// 		y++;
// 	}
// 	return (array);
// }

// int	*redefine_array(int *array, int min, size_t size)
// {
// 	int *new_array = new int[size];
// 	int y = 0;
// 	for (size_t x = 0; x <= size; x++)
// 	{
// 		if (array[x] != min)
// 			new_array[y++] = array[x];
// 	}
// 	delete array;
// 	return (new_array);
// }

// void	PmergeMe::start_binary_search(void)
// {
// 	int cursor = this->n_s / 2;
// 	while (this->n_c > 0)
// 	{
// 		int x = 0;
// 		// std::cout << cursor << std::endl;
// 		if (this->S_list[cursor] < this->C_list[x] && this->S_list[cursor + 1] > this->C_list[x])
// 		{
// 			this->S_list.insert(this->S_list.begin() + cursor, this->C_list[x]);
// 			this->C_list.erase(this->C_list.begin() + x);
// 			cursor = this->n_s / 2;
// 			// std::cout << "PUSH" << std::endl;
// 		}
// 		else if (this->S_list[cursor] > this->C_list[x] && this->S_list[cursor - 1] < this->C_list[x])
// 		{
// 			this->S_list.insert(this->S_list.begin() + cursor, this->C_list[x]);
// 			this->C_list.erase(this->C_list.begin() + x);
// 			cursor = this->n_s / 2;
// 			// std::cout << "PUSH" << std::endl;
// 		}
// 		if (C_list[x] == 85 && cursor == 9)
// 			break;
// 		else if (this->S_list[cursor] > this->C_list[x])
// 		{
// 			cursor = cursor / 2;
// 		}
// 		else if (this->S_list[cursor] < this->C_list[x])
// 		{
// 			cursor = cursor + cursor / 2;
// 			if (cursor > (int)this->n_s)
// 			{
// 				cursor = this->n_s;
// 				this->S_list.push_back(this->C_list[x]);
// 				this->C_list.erase(this->C_list.begin() + x);
// 			}
// 		}
// 		update_vector_size();
// 		// std::cout << "cursor = " << cursor << std::endl;
// 		// std::cout << "S_list[cursor] = " << this->S_list[cursor] << "	C_list[x] = " << C_list[x] << "	S_list[cursor - 1] = " << this->S_list[cursor - 1] << std::endl;
// 	}
// 	print_vectors();
// }

PmergeMe::~PmergeMe(void)
{
	//std::cout << "Default destructor called" << std::endl;
}
