/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:56:11 by jquil             #+#    #+#             */
/*   Updated: 2024/02/22 14:00:43 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAX_HPP
# define MAX_HPP

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
#include "min.hpp"
#include "swap.hpp"

template <typename T>
T max(T x, T y)
{
	return (x > y)? x: y;
}

#endif
