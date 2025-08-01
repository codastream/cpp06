/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <fpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 00:19:26 by fpetit            #+#    #+#             */
/*   Updated: 2025/08/01 15:07:09 by fpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <cctype>
#include <climits>
#include <limits>

enum Type {CHAR, INT, FLOAT, DOUBLE, EMPTY, UNKNOWN};
class ScalarConverter {
	public:
		static void	convert(std::string& s);
	
	private:
		virtual ~ScalarConverter();
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);

		static Type		_guessType(std::string& s);
		static char		_toChar(Type from, std::string& s);
		static int		_toInt(Type from, std::string& s);
		static float	_toFloat(Type from, std::string& s);
		static double	_toDouble(Type fro, std::string& s);
};

#endif