/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:06:53 by jquil             #+#    #+#             */
/*   Updated: 2024/05/28 17:30:08 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

class Data
{
	private:
		Data(const Data &src);
		Data	&operator=(const Data &rhs);
	public:
		~Data();
		Data();
		std::string	str;
		int		num;
};

#endif
