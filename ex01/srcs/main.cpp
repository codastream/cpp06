/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetit <fpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:21:53 by fpetit            #+#    #+#             */
/*   Updated: 2025/08/02 16:03:36 by fpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "utils.hpp"

int	main(void)
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
	Data *desD = Serializer::deserialize(raw);
	std::cout << BLUE << \
	"@ " << &desD << std::endl << \
	"id : " << desD->id << std::endl << \
	"description : " << desD->description << NC << std::endl;
}
