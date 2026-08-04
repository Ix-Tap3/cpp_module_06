/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcaplat </var/spool/mail/pcaplat>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 12:14:38 by pcaplat           #+#    #+#             */
/*   Updated: 2026/08/04 19:49:49 by pcaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "includes/Base.hpp"

int	main( void )
{
	Base	*ptr;
	Base	*ref;

	std::srand(std::time((time_t *){0}));
	for (int i = 0; i < 10; i++)
	{
		ptr = generate();
		ref = generate();
		std::cout << "ptr type: " << std::endl;
		identify(ptr);
		std::cout << "ref type: " << std::endl;
		identify(*ref);
		delete ptr;
		delete ref;
		std::cout << std::endl;
	}
}
