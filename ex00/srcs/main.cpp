/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <fpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:21:53 by fpetit            #+#    #+#             */
/*   Updated: 2025/08/26 10:37:39 by fpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "util.hpp"

static void	doTests(std::string testCategory, std::string literals[], std::string names[], int size)
{
	printcol(PURPLEBACK, testCategory);
	for (int i = 0; i < size; i++)
	{
		printcol(YELLOWBACK, names[i]);
		ScalarConverter::convert(literals[i]);
	}
}

int	main(void)
{
	{
		std::string literals[] = {"a"};
		std::string	briefs[] = {"standard - 'a'"};
		doTests("FROM CHAR", literals, briefs, 1);
	}
	{
		std::string literals[] = {"42", "-42", "0"};
		std::string	briefs[] = {"standard '42'", "negative '-42'", "zero - '0'"};
		doTests("FROM INTEGER", literals, briefs, 3);
	}
	{
		std::string literals[] = {"42f", "-42.01f", "nanf", "-inff", "+inff"};
		std::string	briefs[] = {"standard '42f'", "negative with decimal '-42.01f'", "nanf", "-inff", "+inff"};
		doTests("FROM FLOAT", literals, briefs, 5);
	}
	{
		std::string literals[] = {"42.", "-42.01", "nan", "-inf", "+inf"};
		std::string	briefs[] = {"standard '42'", "negative with decimal '-42.01'", "nan", "-inf", "+inf"};
		doTests("FROM DOUBLE", literals, briefs, 5);
	}
	{
		std::string literals[] = {""};
		std::string	briefs[] = {"empty"};
		doTests("SPECIAL CASES", literals, briefs, 1);
	}
}
