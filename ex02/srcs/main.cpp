/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <fpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:21:53 by fpetit            #+#    #+#             */
/*   Updated: 2025/08/02 20:05:33 by fpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <typeinfo>
#include "utils.hpp"
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int	getRandom(void)
{
	int n = rand() % 3;
	return (n);
}

Base * generate(void)
{
	int n = getRandom();
	Base *sub = NULL;
	switch (n)
	{
		case 0:
			sub = new A();
			break ;
		case 1:
			sub = new B();
			break ;
		default:
			sub = new C();
	}
	return sub;
}

void	identify(Base* p)
{
	if (A* a = dynamic_cast<A*>(p))
	{
		std::cout << GREEN << "instance of class A " << NC << std::endl;
	}
	else if (B* b = dynamic_cast<B*>(p))
		std::cout << GREEN << "instance of class B " << NC << std::endl;
	else if (C* c = dynamic_cast<C*>(p))
		std::cout << GREEN << "instance of class C " << NC << std::endl;
}

void	identify(Base& p)
{
	try {
		A& a = dynamic_cast<A&>(p);
		std::cout << "inst casted from " << &p << " @ " << &a << GREEN << " is instance of class A " << NC << std::endl;
	} catch (std::bad_cast& e) {	
		std::cout << e.what() << std::endl;
	}

	try {
		B& b = dynamic_cast<B&>(p);
		std::cout << "inst casted from " << &p << " @ " << &b << BLUE << " is instance of class B " << NC << std::endl; 
	} catch (std::bad_cast& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		C& c = dynamic_cast<C&>(p);
		std::cout << "inst casted from " << &p << " @ " << &c << YELLOW << " is instance of class C " << NC << std::endl; 
	} catch (std::bad_cast& e) {
		std::cout << e.what() << std::endl;
	}
}

int	main(void)
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
