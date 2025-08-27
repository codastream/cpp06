/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <fpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 21:36:35 by fpetit            #+#    #+#             */
/*   Updated: 2025/08/27 14:55:22 by fpetit           ###   ########.fr       */
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

static bool	_isInt(std::string& s, int* i)
{
	std::string::iterator it = s.begin();

	long	res = 0;
	int		negFactor = 1;

	if (s == "0")
	{
		*i = 0;
		return (true);
	}
	if (s[0] == '-' || s[0] == '+')
	{
		if (s[0] == '-')
			negFactor = -1;
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
	*i = negFactor * res;
	return (true);
}

static	bool	_isFloat(std::string& s, float* f)
{
	std::string::iterator it = s.begin();
	int	negFactor = 1;

	if (s == "+inff")
	{
		*f = std::numeric_limits<float>::infinity();
		return true;
	}
	else if (s == "-inff")
	{
		*f = -std::numeric_limits<float>::infinity();
		return true;
	}
	else if (s == "nanf")
	{
		*f = std::numeric_limits<float>::quiet_NaN();
		return true;
	}
	else if (s == "0f" || s == "0.f" || s == "0.0f")
	{
		*f = 0;
		return (true);
	}
	if (s[0] == '-' || s[0] == '+')
	{
		if (s[0] == '-')
			negFactor = -1;
		it++;
	}
	if (it == s.end())
		return (false);
	if (*s.rbegin() != 'f')
	{
		return (false);
	}
	bool hasDecimal = false;
	for (; it != s.end() - 1; it++)
	{
		if (std::isdigit(*it))
			continue;
		else if (*it == '.' && !hasDecimal)
			hasDecimal = true;
		else
			return (false);
	}

	std::string sub(s.begin(), s.end() - 1);

	char* endptr;

	errno = 0;
	double d = std::strtod(sub.c_str(), &endptr);
	if (errno == ERANGE || endptr == sub.c_str() || *endptr != '\0')
		return false;
	if (d > std::numeric_limits<float>::max() || d < -std::numeric_limits<float>::max())
		return false;
	// checking for underflow


	if (d != 0.0 && std::abs(d) < std::numeric_limits<float>::min() )
	{
		return false;
	}
	*f = negFactor * static_cast<float>(d);
	if (std::isinf(*f) && !std::isinf(d))
		return false;
	if (std::isnan(*f) && !std::isnan(d))
		return false;
	return (true);
}

static bool	_isDouble(std::string& s, double* d)
{
	std::string::iterator it = s.begin();
	int	negFactor = 1;

	if (s == "+inf")
	{
		*d = std::numeric_limits<double>::infinity();
		return true;
	}
	else if (s == "-inf")
	{
		*d = - std::numeric_limits<double>::infinity();
		return true;
	}
	else if (s == "nan")
	{
		*d = std::numeric_limits<double>::quiet_NaN();
		return true;
	}
	if (s == "0.0" || s == "0.")
	{
		*d = 0;
		return (true);
	}
	if (s[0] == '-' || s[0] == '+')
	{
		if (s[0] == '-')
			negFactor = -1;
		it++;
	}
	if (it == s.end())
		return (false);

	bool hasDecimal = false;
	for (; it != s.end(); it++)
	{
		if (std::isdigit(*it))
			continue;
		else if (*it == '.' && !hasDecimal)
			hasDecimal = true;
		else
			return (false);
	}
	double dou = std::strtod(s.c_str(), NULL);
	if (dou != 0)
	{
		*d = negFactor * dou;
		return (true);
	}
	return (false);
}

Type	_guessType(std::string& s, char* c, int* i, float* f, double* d)
{
	if (s == "")
		return (EMPTY);
	if (_isInt(s, i))
		return (INT);
	else if (_isFloat(s, f))
		return (FLOAT);
	else if (_isDouble(s, d))
		return (DOUBLE);
	else if (s.length() == 1)
	{
		*c = s.c_str()[0];
		return (CHAR);
	}
	else
		return (UNKNOWN);
}

bool ScalarConverter::_is_nanf(float f) {
	return f != f;
}

bool ScalarConverter::_is_nand(double d) {
	return d != d;
}

bool is_pos_inff(float f)
{
	return f == std::numeric_limits<float>::infinity();
}

bool is_neg_inff(float f)
{
	return f == -std::numeric_limits<float>::infinity();
}

bool is_pos_inf(double d)
{
	return d == std::numeric_limits<double>::infinity();
}

bool is_neg_inf(double d)
{
	return d == -std::numeric_limits<double>::infinity();
}

bool ScalarConverter::_is_inff(float f)
{
	return (is_neg_inf(f) || is_pos_inff(f));
}
bool ScalarConverter::_is_inf(double d)
{
	return (is_neg_inf(d) || is_pos_inf(d));
}

void	ScalarConverter::convert(std::string& s)
{
	char	c;
	int		i;
	float	f;
	double	d;

	Type t = _guessType(s, &c, &i, &f, &d);
	switch (t)
	{
		case CHAR:
			_toAll(c, CHAR);
			break ;
		case INT:
			_toAll(i, INT);
			break ;
		case FLOAT:
			_toAll(f, FLOAT);
			break ;
		case DOUBLE:
			_toAll(d, DOUBLE);
			break ;
		default:
			std::cerr << "\ttype could not be detected" << std::endl;
	}

}
