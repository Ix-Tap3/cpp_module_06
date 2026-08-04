/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcaplat </var/spool/mail/pcaplat>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 18:23:24 by pcaplat           #+#    #+#             */
/*   Updated: 2026/08/04 19:39:32 by pcaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <exception>
#include "../includes/Base.hpp"

Base::~Base	( void ) { }

Base	*generate( void )
{
	char	types[3] = { 'a', 'b', 'c' };
	int		idx;

	idx = std::rand() % 3;
	std::cout << "obj being created: " << types[idx] << std::endl;
	switch (types[idx])
	{
		case 'a':
			return (new A);
		case 'b':
			return (new B);
		case 'c':
			return (new C);
	}
	return (NULL);
}

void	identify( Base *p )
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else
		std::cerr << "Error: Unknown object type" << std::endl;
}

void	identify( Base &p )
{
	try
	{
		A	&ref = dynamic_cast<A&>(p);
		(void)ref;
		std::cout << "A" << std::endl;
		return ;
	} catch (std::exception &e ) { }
	try
	{
		B	&ref = dynamic_cast<B&>(p);
		(void)ref;
		std::cout << "B" << std::endl;
		return ;
	} catch (std::exception &e ) { }
	try
	{
		C	&ref = dynamic_cast<C&>(p);
		(void)ref;
		std::cout << "C" << std::endl;
		return ;
	} catch (std::exception &e ) { }
}
