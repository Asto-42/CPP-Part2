/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:39:22 by jquil             #+#    #+#             */
/*   Updated: 2024/06/11 13:39:31 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template <typename T>
int easy_find(T temp, int nb)
{
	for (size_t x = 0; x < temp.size(); x++)
		if (temp[x] == nb)
			return (x);
	throw NoOccurence();
}
