/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcaplat </var/spool/mail/pcaplat>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 16:54:45 by pcaplat           #+#    #+#             */
/*   Updated: 2026/08/04 19:25:32 by pcaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Base
{
public:
	virtual ~Base	( void );
};

class A:	public Base { };
class B:	public Base { };
class C:	public Base { };

Base	*generate( void );
void	identify( Base * );
void	identify( Base & );
