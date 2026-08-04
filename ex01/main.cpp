/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcaplat </var/spool/mail/pcaplat>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 12:00:27 by pcaplat           #+#    #+#             */
/*   Updated: 2026/08/04 12:06:48 by pcaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int	main( void )
{
	Data		data;
	Data		*d;
	uintptr_t	ptr;

	data.id = 1;
	data.name = "Bob";

	ptr = Serializer::serialize(&data);
	d = Serializer::deserialize(ptr);
	
	std::cout << "data adress: " << &data << std::endl;
	std::cout << "serialized ptr: " << ptr << std::endl;
	std::cout << "deserialized ptr: " << d << std::endl;
}
