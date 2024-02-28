/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:36:02 by jquil             #+#    #+#             */
/*   Updated: 2024/02/21 14:34:40 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

static void identify(Base *ptr)
{
	if (dynamic_cast<A *>(ptr))
		std::cout << "A is the identified type" << std::endl;
	else if (dynamic_cast<B *>(ptr))
		std::cout << "B is the identified type" << std::endl;
	else if (dynamic_cast<C *>(ptr))
		std::cout << "C is the identified type" << std::endl;
	else if (ptr == NULL)
		std::cout << "Base is NULL" << std::endl;
	else
		std::cout << "ptr is unknown" << std::endl;
}

	static int x = 0;
	static std::string cl[] = {"A", "B", "C"};;

static void identify(Base &ptr)
{
	while (x < 3)
	{
		void *foo = NULL;
		Base &bse = (Base &)foo;
		try
		{
			if (x == 0)
				bse = dynamic_cast<A &>(ptr);
			else if (x == 1)
				bse = dynamic_cast<B &>(ptr);
			else if (x == 2)
				bse = dynamic_cast<C &>(ptr);
			else
				std::cout << "ptr is unknow" << std::endl;
		}
		catch (std::exception &e)
		{
			x++;
			identify(ptr);
			return;
		}
		std::cout << cl[x] << " is the identified type" << std::endl;
		x = 0;
		break;
	}
}

Base *generate(void)
{
	int x = rand();
	if (x % 4 == 0)
		return (new A());
	else if (x % 3 == 0)
		return (new B());
	else
		return (new C());
	return (NULL);
}

int main(void)
{
	std::srand(time(0));
	std::cout << "		------------------------Part 1------------------------" << std::endl;
	for (int x = 0; x <= 10; x++)
	{
		std::cout << "Call N." << x << std::endl;
		identify(generate());
		std::cout << "\n" << std::endl;
	}
	std::cout << "		------------------------Part 2------------------------" << std::endl;
	for (int x = 0; x <= 10; x++)
	{
		std::cout << "Call N." << x << std::endl;
		identify(*generate());
		std::cout << "\n" << std::endl;
	}
	std::cout << "		------------------------Part 3------------------------" << std::endl;
	identify(NULL);
	return (0);
}
