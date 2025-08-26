#include "Serializer.hpp"
#include "utils.hpp"

/************************************************************
*				🥚 CONSTRUCTORS & DESTRUCTOR				*
************************************************************/

Serializer::Serializer(void) 
{
	if (DEBUG)
		printcol(BLUE, "Serializer Default constructor called");
}

Serializer::Serializer(const Serializer& inst) 
{
	if (DEBUG)
		printcol(BLUE, "Serializer copy constructor called");
	*this = inst;
}

Serializer::~Serializer(void) 
{
	if (DEBUG)
		printcol(BLUE, "Serializer destructor called");
}

/************************************************************
*				➕ OPERATORS									*
************************************************************/

Serializer& Serializer::operator=(const Serializer& inst) 
{
	if (DEBUG)
		printcol(BLUE, "Serializer operator = overload called");
	if (this == &inst)
		return (*this);
	return (*this);
}

/*************************************************************
*		        🛠️ FUNCTIONS								*
*************************************************************/

uintptr_t	Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

/*
 * @brief at compile time will be treated as a pointer to Data
 */
Data*		Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}
