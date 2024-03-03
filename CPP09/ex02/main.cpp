/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquil <jquil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:41:53 by jquil             #+#    #+#             */
/*   Updated: 2024/03/01 18:25:59 by jquil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

//1 - Group les elem de X par paires (n/2) avec un element solo si %2!=0
//2 - determiner le max de chaque paires (soit n/2 comparaison)
//3 - trier recursivement les n\2 plus grands elements de chaque paire creant ainsi
//    une liste S, S contient n\2 elements dans l'ordre croissant
//4 - inserer au debut de S l'element qui a ete apparie au premier
//    et au plus petit element de S
//5 - inserer le reste des (n/2 -1) elements de X dans S, un a la fois, avec un ordre
//    d'insertion specialement choisi -> recherche dichotomique
//    recherche dichotomique -> sur un tableau de n, regarder si l'element
//    est sup ou inf a la valeur en n/2, si egal, benef,
//    sinon recommencer dans la moitie du tableau pertinente

void calcul_max_comp(int nb)
{
	int max_comp;

	max_comp = (nb * log2(nb)) - (1.415 * (nb));
	std::cout << "For " << nb << " integers, the max comp is " << max_comp << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Invalid arguments" << std::endl;
		return (0);
	}
	PmergeMe data((unsigned int)argc - 1, argv);
	calcul_max_comp(argc - 1);
	data.start_sort();
	return (0);
}
