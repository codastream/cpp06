#include <cstdlib>
#include <ctime>
#include <typeinfo>
#include "utils.hpp"
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int	getRandom()
{
	int n = rand() % 3;
	return (n);
}

Base * generate()
{
	int n = getRandom();
	switch (n)
	{
		case 0: return new A();
		case 1: return new B();
		default: return new C();
	}
	return NULL;
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << GREEN << "instance of class A " << NC << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << GREEN << "instance of class B " << NC << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << GREEN << "instance of class C " << NC << std::endl;
	else
		std::cout << "unknown" << std::endl;
}

void	identify(Base& p)
{
	try {
		A& a = dynamic_cast<A&>(p);
		std::cout << "inst casted from " << &p << " @ " << &a << GREEN << " is instance of class A " << NC << std::endl;
	} catch (std::bad_cast& e) {}

	try {
		B& b = dynamic_cast<B&>(p);
		std::cout << "inst casted from " << &p << " @ " << &b << BLUE << " is instance of class B " << NC << std::endl; 
	} catch (std::bad_cast& e) {}

	try {
		C& c = dynamic_cast<C&>(p);
		std::cout << "inst casted from " << &p << " @ " << &c << YELLOW << " is instance of class C " << NC << std::endl; 
	} catch (std::bad_cast& e) {}
}

int	main()
{
	srand(time(NULL));

	printcol(PURPLEBACK, "identify A pointer");
	A a1;
	identify(&a1);
	
	printcol(PURPLEBACK, "identify pointers random");
	for (int i = 0; i < 5; i++)
	{
		Base *sub = generate();
		identify(sub);
		delete sub;
	}

	printcol(PURPLEBACK, "identify A ref");
	A a;
	identify(a);
	
	printcol(PURPLEBACK, "identify ref random");
	Base *sub2 = generate();
	Base& ref = *sub2;
	identify(ref);
	delete sub2;
}
