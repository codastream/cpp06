/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <fpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:21:53 by fpetit            #+#    #+#             */
/*   Updated: 2025/08/26 20:02:30 by fpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "utils.hpp"
#include <cassert>

void basicTest()
{
	printcol(PURPLEBACK, "serializing");
	Data d = {
		88,
		"youpi"
	};
	std::cout << BLUE << \
	"@ " << &d << std::endl << \
	"id : " << d.id << std::endl << \
	"description : " << d.description << NC << std::endl;
	uintptr_t raw = Serializer::serialize(&d);

	printcol(PURPLEBACK, "deserializing");
	Data *dd = Serializer::deserialize(raw);
	std::cout << BLUE << \
	"@ " << dd << std::endl << \
	"id : " << dd->id << std::endl << \
	"description : " << dd->description << NC << std::endl;

	assert(dd == &d);
	assert(dd->id == 88);
	assert(dd->description == "youpi");
}

void	nullTest()
{
	Data* d1 = NULL;
	uintptr_t sz = Serializer::serialize(d1);
	Data* dsz = Serializer::deserialize(sz);

	assert(dsz == NULL);
}

int	main(void)
{
	basicTest();
	nullTest();
}
