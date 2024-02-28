/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easy.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:12:45 by jquil             #+#    #+#             */
/*   Updated: 2024/02/23 12:09:12 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASY_HPP
# define EASY_HPP

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
#include <time.h>
#include <string.h>
#include <limits.h>
#include <cctype>
#include <cstdlib>
#include <stdint.h>
#include <vector>

template <typename T>
void easyfind(T temp, int nb);

class NoOccurence:public std::exception
{
		public :

		virtual const char *what() const throw();
};

#endif
