/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:50:36 by jquil             #+#    #+#             */
/*   Updated: 2024/07/25 13:01:48 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <iostream>
# include <string>
# include <limits>

class Rpn
{
	private:
		std::stack<int> objS;


	public:
		std::stack<int>& getObjS();
		Rpn();
		~Rpn();
		Rpn(Rpn const& instance);
		Rpn&	operator=(Rpn const& instance);

};

#endif
