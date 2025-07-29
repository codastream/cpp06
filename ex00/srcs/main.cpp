/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <fpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:21:53 by fpetit            #+#    #+#             */
/*   Updated: 2025/07/29 17:37:54 by fpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"#
#include "util.hpp"

int	main(void)
{
	printcol(YELLOWBACK, "empty");
	ScalarConverter::convert("");

	printcol(YELLOWBACK, "char literal");
	ScalarConverter::convert("c");

	printcol(YELLOWBACK, "int literal");
	ScalarConverter::convert("42");
	printcol(YELLOWBACK, "int literal negative");
	ScalarConverter::convert("-42");
	printcol(YELLOWBACK, "int literal 0");
	ScalarConverter::convert("42");
	
	printcol(PURPLEBACK, "FLOAT");
	printcol(YELLOWBACK, "nanf");
	ScalarConverter::convert("nan");
	printcol(YELLOWBACK, "+inff");
	ScalarConverter::convert("+inff");
	printcol(YELLOWBACK, "-inff");
	ScalarConverter::convert("-inff");
	printcol(YELLOWBACK, "float literal");
	ScalarConverter::convert("42f");
	
	printcol(PURPLEBACK, "DOUBLE");
	printcol(YELLOWBACK, "double literal");
	ScalarConverter::convert("42.0");
	printcol(YELLOWBACK, "nan");
	ScalarConverter::convert("nan");
	printcol(YELLOWBACK, "-inf");
	ScalarConverter::convert("-inf");
	printcol(YELLOWBACK, "+inf");
	ScalarConverter::convert("+inf");
}
