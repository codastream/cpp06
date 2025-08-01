/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <fpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 21:36:35 by fpetit            #+#    #+#             */
/*   Updated: 2025/08/01 15:16:46 by fpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "util.hpp"

/************************************************************
*				🥚 CONSTRUCTORS & DESTRUCTOR				*
************************************************************/

ScalarConverter::ScalarConverter(void)
{
	if (DEBUG)
		printcol(BLUE, "ScalarConverter Default constructor called - but should not");
}

ScalarConverter::ScalarConverter(const ScalarConverter& inst)
{
	if (DEBUG)
		printcol(BLUE, "ScalarConverter copy constructor called - but should not");
	*this = inst;
}

ScalarConverter::~ScalarConverter(void) 
{
	if (DEBUG)
		printcol(BLUE, "ScalarConverter destructor called - but should not");
}

/************************************************************
*				➕ OPERATORS									*
************************************************************/

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& inst) 
{
	if (DEBUG)
		printcol(BLUE, "ScalarConverter operator = overload called - but should not");
	if (this == &inst)
		return (*this);
	return (*this);
}

/*************************************************************
*		        🛠️ FUNCTIONS								*
*************************************************************/

static bool	_isPrintChar(std::string& s)
{
	return s.length() == 1 && std::isprint(s.c_str()[0]);
}

static double stoD(std::string& s)
{
	std::stringstream	ss;
	double				d;

	ss << s;
	ss >> d;
	return d;
}

static bool	_isInt(std::string& s)
{
	std::string::iterator it = s.begin();

	long	res = 0;
	bool	isNeg = false;

	if (s == "0")
		return (true);
	if (s[0] == '-' || s[0] == '+')
	{
		if (s[0] == '-')
			isNeg = true;
		it++;
	}
	if (it == s.end())
		return (false);
	if (s.length() > 11)
		return (false);
	for (; it != s.end(); it++)
	{
		if (!std::isdigit(*it))
			return (false);
		res *= 10;
		res += *it - '0';
	}
	if (res > INT_MAX || res < INT_MIN)
		return (false);
	return (true);
}

static	bool	_isFloat(std::string& s)
{
	std::string::iterator it = s.begin();
	double d;

	if (s == "nanf" || s == "+inff" || s == "-inff" || s == "0f" || s == "0.f" || s == "0.0f")
		return (true);
	if (s[0] == '-' || s[0] == '+')
		it++;
	if (it == s.end())
		return (false);
	for (; it != s.end() - 1; it++)
	{
		if (!std::isdigit(*it) && *it != '.')
			return (false);
	}
	if ((*s.end()) != 'f')
		return (false);
	d = stoD(s);
	std::cout << "double value is"<< d << std::endl;
	if (d < __FLT_MAX__ && d > __FLT_MIN__)
		return (true);
	return (false);
}

static bool	_isDouble(std::string& s)
{
	std::string::iterator it = s.begin();

	if (s == "nan" || s == "+inf" || s == "-inf" || s == "0.0" || s == "0.")
		return (true);
	if (s[0] == '-' || s[0] == '+')
		it++;
	if (it == s.end())
		return (false);
	if (s.find('.', 0) == std::string::npos)
		return (false);
	for (; it != s.end(); it++)
	{
		if (!std::isdigit(*it) && *it != '.')
			return (false);
	}
	return (true);
}

Type		ScalarConverter::_guessType(std::string& s)
{
	if (s == "")
		return (EMPTY);

	if (_isPrintChar(s))
		return (CHAR);
	else if (_isInt(s))
		return (INT);
	else if (_isFloat(s))
		return (FLOAT);
	else if (_isDouble(s))
		return (DOUBLE);
	else
		return (UNKNOWN);
		
}

static char		_toChar(Type from, std::string& s)
{
	char c = s.c_str()[0];
	if (c <= 31 || c > 127)
	{
		std::cerr << RED << "only printable characters should be passed" << NC << std::endl;
		return c;
	}
	switch (from)
	{
		case CHAR:
			return c;
		case INT:
			return c;
		case FLOAT:
			std::cerr << RED << "cant convert float -> char" << NC;
			return '\0';
		case DOUBLE:
			std::cerr << RED << "cant convert double -> char" << NC;
			return '\0';
		default:
			return c;
	}
}

static int		_toInt(Type from, std::string& s)
{
	switch (from)
	{
		case CHAR:
			return static_cast<int>(s.c_str()[0]);
			break ;
		case INT:
		case FLOAT:
		case DOUBLE:
			return static_cast<int>(stoD(s));
			break ;
		default:
			return (-1);
	}
}

static float	_toFloat(Type from, std::string& s)
{
	switch (from)
	{
		case CHAR:
			return static_cast<float>(s.c_str()[0]);
			break ;
		case INT:
			return static_cast<float>(stoD(s));
			break ;
		case FLOAT:
			return static_cast<float>(stoD(s));
			break ;
		case DOUBLE:
			return static_cast<float>(stoD(s));
			break ;
		default:
			return (-1);
	}
}

static double	_toDouble(Type from, std::string& s)
{
	switch (from)
	{
		case CHAR:
			return static_cast<double>(s.c_str()[0]);
			break ;
		case INT:
			return static_cast<double>(stoD(s));
			break ;
		case FLOAT:
			return static_cast<double>(stoD(s));
			break ;
		case DOUBLE:
			return static_cast<double>(stoD(s));
			break ;
		default:
			return (-1);
	}
}
static void	tryConvertToAll(Type from, std::string& s)
{
	if (from == CHAR || from == INT || from == FLOAT || from == DOUBLE)
	{
		std::cout << CCHAR << "CHAR\t" << _toChar(from, s) << NC << std::endl;
		std::cout << CINT << "INT\t" << _toInt(from, s) << NC << std::endl;
		std::cout << CFLOAT << "FLOAT\t" << _toFloat(from, s) << NC << std::endl;
		std::cout << CDOUBLE << "DOUBLE\t" << _toDouble(from, s) << NC << std::endl;
	}
	else
		std::cerr << "type could not be detected" << std::endl;
}


void	ScalarConverter::convert(std::string& s)
{
	Type t = ScalarConverter::_guessType(s);
	tryConvertToAll(t, s);
}

/*************************************************************
*		    👁️‍ GETTERS and SETTERS				 			*
*************************************************************/
