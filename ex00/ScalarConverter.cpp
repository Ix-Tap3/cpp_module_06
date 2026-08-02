/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcaplat <pcaplat@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 14:25:57 by pcaplat           #+#    #+#             */
/*   Updated: 2026/08/02 16:24:58 by pcaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter	( void ) { }
ScalarConverter::~ScalarConverter	( void ) { }
ScalarConverter::ScalarConverter	( ScalarConverter const &other )
{
	if (this != &other)
		*this = other;
}

ScalarConverter	&ScalarConverter::operator=	( ScalarConverter const &other )
{
	static_cast<void>(other);
	return (*this);
}

static bool	isChar( std::string const &str )
{
	int	quotes = 0;

	if (str[0] == '\'')
		quotes++;
	if (quotes == 0 && str.length() != 1)
		return (false);
	else if (quotes == 1 && str.length() != 3)
		return (false);
	if ((std::isprint(str[0]) && !std::isdigit(str[0])) ||
			(quotes == 1 && str[2] == '\''))
	{
		return (true);
	}
	return (false);
}

static bool	isLiteral( std::string const &str )
{
	if (str == "nan" || str == "nanf")
		return (true);
	else if (str == "inf" || str == "inff")
		return (true);
	else if (str == "+inf" || str == "-inf" || str == "+inff" || str == "-inff")
		return (true);
	return (false);
}

static bool	isFloat( std::string const &str )
{
	std::size_t	found;

	found = str.find_first_not_of("-+0123456789.f");
	if (found != std::string::npos)
		return (false);
	found = str.find_first_of(".");
	if (found != std::string::npos)
	{
		if (str[str.length() - 1] == 'f')
			return (true);
	}
	return (false);
}

static bool	isDouble( std::string const &str )
{
	std::size_t	found;

	found = str.find_first_not_of("-+0123456789.");
	if (found != std::string::npos)
		return (false);
	found = str.find_first_of(".");
	if (found != std::string::npos)
		return (true);
	return (false);
}

static bool	isInt( std::string const &str )
{
	std::size_t	found;

	found = str.find_first_not_of("-+0123456789");
	if (found != std::string::npos)
		return (false);
	return (true);
}

void	ScalarConverter::convert( std::string const &input )
{
	if (input.empty())
	{
		std::cerr << "Error: Invalid empty input provided" << std::endl;
		return ;
	}
	else if (isChar(input))
		std::cout << "input is a single char" << std::endl;
	else if (isLiteral(input))
		std::cout << "input is a litteral expression" << std::endl;
	else if (isFloat(input))
		std::cout << "input is a float" << std::endl;
	else if (isDouble(input))
		std::cout << "input is a double" << std::endl;
	else if (isInt(input))
		std::cout << "input in an Int" << std::endl;
	else
		std::cerr << "invalid input provided" << std::endl;
}
