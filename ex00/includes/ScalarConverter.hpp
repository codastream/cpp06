/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <fpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 00:19:26 by fpetit            #+#    #+#             */
/*   Updated: 2025/08/27 14:37:25 by fpetit           ###   ########.fr       */
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
#include <iomanip>
#include <cstdlib>
#include <cerrno>

#include "util.hpp"

enum Type {CHAR, INT, FLOAT, DOUBLE, EMPTY, UNKNOWN};
class ScalarConverter {
	public:
		static void	convert(std::string& s);
	
	private:
		virtual ~ScalarConverter();
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);

		static bool _is_nanf(float f);
		static bool _is_nand(double d);
		static bool _is_inff(float f);
		static bool _is_inf(double d);

		template <typename T>
		static double _toDouble(T t);

		template <typename T>
		static float _toFloat(T t);

		template <typename T>
		static int _toInt(T t);

		template <typename T>
		static char _toChar(T t);

		template <typename T>
		static void	_toAll(T t, Type from);

		template <typename T>
		static bool _isPrint(T t);
};

#include "ScalarConverter.tpp"

#endif