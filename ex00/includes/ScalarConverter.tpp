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
void	ScalarConverter::_toAll(T t, Type from)
{
	if ((from == FLOAT && ScalarConverter::_is_inff(t)) || (from == DOUBLE && ScalarConverter::_is_inf(t)))
		std::cerr << RED << "char\t-> cant convert to char" << NC << std::endl;
	else if ((from == FLOAT || from == DOUBLE || from == INT) && ((from == FLOAT && ScalarConverter::_is_nanf(t)) || (from == DOUBLE && ScalarConverter::_is_nand(t)) || !std::isprint(t)))
		std::cerr << RED << "char\t-> cant convert to char" << NC << std::endl;
	else if (from == CHAR && !std::isprint(t))
		std::cerr << RED << "char\t-> only printable characters should be passed as argument" << NC << std::endl;
	else
		std::cout << BLUE << "char\t-> " << _toChar(t) << NC << std::endl;
	
	std::cout << BLUE << "int\t-> " << _toInt(t) << NC << std::endl;
	std::cout << BLUE << "float\t-> " << _toFloat(t) << NC << std::endl;
	std::cout << BLUE << "double\t-> " << _toDouble(t) << NC << std::endl;
}
