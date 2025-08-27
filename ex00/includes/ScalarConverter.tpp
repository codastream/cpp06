template <typename T>
double ScalarConverter::_toDouble(T t)
{
	return static_cast<double>(t);
}

template <typename T>
float ScalarConverter::_toFloat(T t)
{
	return static_cast<float>(t);
}

template <typename T>
int ScalarConverter::_toInt(T t)
{
	return static_cast<int>(t);
}

template <typename T>
char ScalarConverter::_toChar(T t)
{
	return static_cast<char>(t);	
}

template <typename T>
bool ScalarConverter::_isPrint(T t)
{
	return (t < std::numeric_limits<char>::max() && t > 32 && t < 127);
}


template <typename T>
void	ScalarConverter::_toAll(T t, Type from)
{
	if ((from == FLOAT && ScalarConverter::_is_inff(t)) || (from == DOUBLE && ScalarConverter::_is_inf(t)))
		std::cerr << RED << "char\t-> cant convert to char" << NC << std::endl;
	else if ((from == FLOAT && ScalarConverter::_is_nanf(t)) || (from == DOUBLE && ScalarConverter::_is_nand(t)))
		std::cerr << RED << "char\t-> cant convert to char" << NC << std::endl;
	else if ((from == FLOAT || from == DOUBLE || from == INT) && !ScalarConverter::_isPrint(t))
		std::cerr << RED << "char\t-> value not in printable char range" << NC << std::endl;
	else if (from == CHAR && !std::isprint(t))
		std::cerr << RED << "char\t-> only printable characters should be passed as argument" << NC << std::endl;
	else
		std::cout << BLUE << "char\t-> " << _toChar(t) << NC << std::endl;
	
	if ((from == FLOAT || from == DOUBLE) && (t > std::numeric_limits<int>::max() || t < std::numeric_limits<int>::min()))
		std::cout << YELLOW << "int\t-> not in int range" << NC << std::endl;
	else
		std::cout << BLUE << "int\t-> " << _toInt(t) << NC << std::endl;
	if ((from == DOUBLE) && (t > std::numeric_limits<float>::max() || t < -std::numeric_limits<float>::max()))
		std::cout << YELLOW << "float\t-> not in float range" << NC << std::endl;
	else if ((from == DOUBLE) && (std::abs(t) < std::numeric_limits<float>::min()))
		std::cout << YELLOW << "float\t-> too precise for float" << NC << std::endl;
	else
		std::cout << BLUE << "float\t-> " << _toFloat(t) << NC << std::endl;
	std::cout << BLUE << "double\t-> " << _toDouble(t) << NC << std::endl;
}
