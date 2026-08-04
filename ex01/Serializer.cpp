/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcaplat </var/spool/mail/pcaplat>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 11:40:06 by pcaplat           #+#    #+#             */
/*   Updated: 2026/08/04 12:08:39 by pcaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer	( void ) { }
Serializer::Serializer	( Serializer const &other )
{
	if (this != &other)
		*this = other;
}
Serializer::~Serializer	( void ) { }

Serializer	&Serializer::operator=	( Serializer const &other ) { (void)other; return (*this); }

uintptr_t	Serializer::serialize( Data *data ) { return reinterpret_cast<uintptr_t>(data); }
Data		*Serializer::deserialize( uintptr_t ptr ) { return reinterpret_cast<Data *>(ptr); }
