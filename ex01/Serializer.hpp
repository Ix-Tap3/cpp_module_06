/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcaplat </var/spool/mail/pcaplat>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 11:22:36 by pcaplat           #+#    #+#             */
/*   Updated: 2026/08/04 12:08:08 by pcaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <stdint.h>
# include "data.h"

class Serializer
{
private:
	Serializer	( void );
	Serializer	( Serializer const & );
	~Serializer	( void );

	Serializer	&operator=	( Serializer const & );

public:
	static uintptr_t	serialize( Data * );
	static Data			*deserialize( uintptr_t );
};
