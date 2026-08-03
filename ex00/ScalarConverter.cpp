/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcaplat <pcaplat@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 14:25:57 by pcaplat           #+#    #+#             */
/*   Updated: 2026/08/03 14:51:11 by pcaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <cctype>
#include <climits>
#include <cstdlib>
#include <cfloat>
#include <cmath>
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

static bool	handleLiteral( std::string const &str )
{
	if (str == "nan" || str == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return (true);
	}
	else if (str == "inf" || str == "inff" || str == "+inf" || str == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
		return (true);
	}
	else if (str == "-inf" || str == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return (true);
	}
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

static char	getInputChar( std::string const &str )
{
	for (std::size_t i = 0; i < str.length(); i++)
		if (str[i] != '\'')
			return str[i];
	return ('0');
}

void	ScalarConverter::convert( std::string const &input )
{
	char		*endptr;

	if (input.empty())
	{
		std::cerr << "Error: Invalid empty input provided" << std::endl;
		return ;
	}
	else if (handleLiteral(input))
		return ;
	else if (isChar(input))
	{
		char	c;

		c = getInputChar(input);
		std::cout << "char: \'" << c << "\'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << std::endl;
		std::cout.unsetf(std::ios::fixed);
		std::cout << std::setprecision(6);
	}
	else if (isInt(input))
	{
		long int	number;

		number = std::strtol(input.c_str(), &endptr, 0);
		if (number >= INT_MIN && number <= INT_MAX)
		{
			if (number < 0 || number > 255)
				std::cout << "char: impossible" << std::endl;
			else if (!std::isprint(number))
				std::cout << "char: Non displayable" << std::endl;
			else
				std::cout << "char: \'" << static_cast<char>(number) << "\'" << std::endl;
			std::cout << "int: " << number << std::endl;
			std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(number) << "f" << std::endl;
			std::cout << "double: " << static_cast<double>(number) << std::endl;
			std::cout.unsetf(std::ios::fixed);
			std::cout << std::setprecision(6);
		}
		else
			std::cerr << "Error: Int overflow" << std::endl;
	}
	else if (isFloat(input))
	{
		float	f;

		f = std::strtof(input.c_str(), &endptr);
		if (f != HUGE_VALF)
		{
			if (f < 0.0f || f > 255.0f)
				std::cout << "char: impossible" << std::endl;
			else if (!std::isprint(static_cast<int>(f)))
				std::cout << "char: Non displayable" << std::endl;
			else
				std::cout << "char: \'" << static_cast<char>(f) << "\'" << std::endl;
			if (f >= INT_MIN && f <= INT_MAX)
				std::cout << "int: " << static_cast<int>(f) << std::endl;
			else
				std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
			std::cout << "double: " << static_cast<double>(f) << std::endl;
			std::cout.unsetf(std::ios::fixed);
			std::cout << std::setprecision(6);
		}
		else
			std::cerr << "Error: float overflow" << std::endl;
	}
	else if (isDouble(input))
	{
		long double	d;

		d = std::strtold(input.c_str(), &endptr);
		if (d >= DBL_MIN && d <= DBL_MAX)
		{
			if (d < 0.0 || d > 255.0)
				std::cout << "char: impossible" << std::endl;
			else if (!std::isprint(static_cast<int>(d)))
				std::cout << "char: Non displayable" << std::endl;
			else
				std::cout << "char: \'" << static_cast<char>(d) << "\'" << std::endl;
			if (d >= INT_MIN && d <= INT_MAX)
				std::cout << "int: " << static_cast<int>(d) << std::endl;
			else
				std::cout << "int: impossible" << std::endl;
			if (d >= FLT_MIN && d <= FLT_MAX)
				std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
			else
			 	std::cout << "float: impossible" << std::endl;
			std::cout << "double: " << d << std::endl;
			std::cout.unsetf(std::ios::fixed);
			std::cout << std::setprecision(6);
		}
		else
			std::cerr << "Error: double overflow" << std::endl;
	}
	else
		std::cerr << "Invalid input provided" << std::endl;
}
