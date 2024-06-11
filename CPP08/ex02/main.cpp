/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:36:02 by jquil             #+#    #+#             */
/*   Updated: 2024/05/28 15:14:53 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Mutant.hpp"

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "mstack top = " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "mstack size = " << mstack.size() + 1 << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	std::cout << "\n";
	for (MutantStack<int>::iterator iter = mstack.begin(); iter != mstack.end(); ++iter)
	{
		std::cout << *iter << "\n";
	}
	std::cout << "\n\nInit begin and end :\n";
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	std::cout << "mstack begin = " << *it << "\n" << std::endl;
	++it;
	std::cout << "it = " << *it << "\n";
	--it;
	std::cout << "\nIncr begin:\n";
	std::cout << "mstack begin = " << *it << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return (0);
}
