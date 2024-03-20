/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:53:15 by jquil             #+#    #+#             */
/*   Updated: 2024/03/20 15:02:50 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <ios>
#include <algorithm>
#include <vector>
#include <math.h>
#include <cmath>
#include <time.h>
#include <string.h>
#include <limits.h>
#include <cctype>
#include <cstdlib>
#include <stdint.h>
#include <vector>
#include <map>
#include <sstream>
#include <ctime>
#include <stack>
#include <cstring>

static unsigned int nb_comp = 0;

typedef struct s_pair
{
	int value;
	int pair;
}			t_pair;

template <typename T>
void	SplitX(T &lst);

class PmergeMe
{
	private :

	std::vector<t_pair> C_list;
	size_t n_c;
	//PmergeMe & operator=(const PmergeMe &rhs);
	PmergeMe(PmergeMe &rhs);

	public :

	PmergeMe();
	PmergeMe(unsigned int n, char **argv);
	~PmergeMe();

};
#endif
