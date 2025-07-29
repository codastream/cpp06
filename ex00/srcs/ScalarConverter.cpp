/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <fpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 21:36:35 by fpetit            #+#    #+#             */
/*   Updated: 2025/07/29 16:14:18 by fpetit           ###   ########.fr       */
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

void	ScalarConverter::convert(const std::string& s)
{
	std::cout << CHAR << static_cast<char>(s.c_str()[0]) << NC << std::endl;
	std::cout << INT << static_cast<int>(s.c_str()) << NC << std::endl;
}

/*************************************************************
*		    👁️‍ GETTERS and SETTERS				 			*
*************************************************************/
