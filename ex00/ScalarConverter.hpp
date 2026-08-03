/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcaplat <pcaplat@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 14:22:42 by pcaplat           #+#    #+#             */
/*   Updated: 2026/08/02 19:15:17 by pcaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <string>

class ScalarConverter
{
private:
	ScalarConverter		( void );
	ScalarConverter		( ScalarConverter const & );
	~ScalarConverter	( void );

	ScalarConverter	&operator=	( ScalarConverter const & );

public:
	static void	convert( std::string const & );
};
