/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:58:06 by jquil             #+#    #+#             */
/*   Updated: 2024/03/20 16:07:36 by jquil            ###   ########.fr       */
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
		std::cout << std::endl;
	}
}

template <typename T>
void	SplitX2(T &lst)
{
	T main;
	T tmp;
	for (size_t x = 0; x < lst.size(); x+= 2)
	{
		nb_comp++;
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
			nb_comp++;
			if (main[x].pair == tmp[0].value)
			{
				tmp.insert(tmp.begin(), main[x]);
				main.erase(main.begin() + x);
				break ;
			}
		}
		while (main.size() > 0)
		{
			size_t y = 0;
			while (y < main.size())
			{
				for (size_t x = 0; x < tmp.size(); x++)
				{
					if (tmp[x].value == main[y].pair)
					{
						size_t x2 = 0;
						while (x2 + 1 < x)
						{
							nb_comp++;
							if (tmp[(x+x2)/2].value < main[y].value)
								x2 = (x + x2) / 2;
							else if (tmp[(x+x2)/2].value > main[y].value)
								x = (x + x2) / 2;
						}
						if (x2 != 0)
							tmp.insert(tmp.begin() + x2 + 1, main[y]);
						else
							tmp.insert(tmp.begin(), main[y]);
						main.erase(main.begin() + y);
						break ;
					}
				}
				y++;
			}
		}
		lst = tmp;
	}
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
			nb_comp++;
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
		SplitX2(tmp);
	}
	while (main.size() > 0)
	{
		size_t y = 0;
		while (y < main.size())
		{
			for (size_t x = 0; x < tmp.size(); x++)
			{
				if (tmp[x].value == main[y].pair)
				{
					size_t x2 = 0;
					while (x2 + 1 < x)
					{
						nb_comp++;
						if (tmp[(x+x2)/2].value < main[y].value)
							x2 = (x + x2) / 2;
						else if (tmp[(x+x2)/2].value > main[y].value)
							x = (x + x2) / 2;
					}
					if (x2 == 0 && x == 1)
						tmp.insert(tmp.begin() + 1, main[y]);
					else if (x2 != 0)
						tmp.insert(tmp.begin() + x2 + 1, main[y]);
					else
						tmp.insert(tmp.begin(), main[y]);
					main.erase(main.begin() + y);
					break ;
				}
			}
			y++;
		}
	}
	lst = tmp;
	print_vector(lst, lst.size(), "lst");
	std::cout << "Nb comp = " << nb_comp << std::endl;
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
};

PmergeMe::~PmergeMe(void)
{
	//std::cout << "Default destructor called" << std::endl;
}
