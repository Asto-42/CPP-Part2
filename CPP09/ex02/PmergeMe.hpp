/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:53:15 by jquil             #+#    #+#             */
/*   Updated: 2024/03/03 14:29:45 by jquil            ###   ########.fr       */
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

class PmergeMe
{
	private :

	std::vector<int> C_list;
	std::vector<int> S_list;
	size_t n_c;
	size_t n_s;
	//PmergeMe & operator=(const PmergeMe &rhs);
	PmergeMe(PmergeMe &rhs);

	public :

	PmergeMe();
	PmergeMe(unsigned int n, char **argv);
	~PmergeMe();

	void	start_sort(void);
	void	update_vector_size(void);
	void	print_vectors(void);
	void	SplitX(void);
	void	push_back_max(int max);
	void	start_binary_search(void);

};
#endif
