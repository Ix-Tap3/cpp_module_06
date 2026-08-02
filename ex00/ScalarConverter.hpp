/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcaplat <pcaplat@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 14:22:42 by pcaplat           #+#    #+#             */
/*   Updated: 2026/08/02 16:53:55 by pcaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <string>

class ScalarConverter
{
private:
	typedef enum	e_types
	{
		T_CHAR,
		T_INT,
		T_FLOAT,
		T_DOUBLE
	}	t_types;

	

	ScalarConverter		( void );
	ScalarConverter		( ScalarConverter const & );
	~ScalarConverter	( void );

	ScalarConverter	&operator=	( ScalarConverter const & );

public:
	static void	convert( std::string const & );
};
