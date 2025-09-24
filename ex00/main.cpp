/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:52:49 by rraumain          #+#    #+#             */
/*   Updated: 2025/09/24 18:59:55 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int	main()
{
	try
	{
		Bureaucrat	a("Bob", 100);
		// Bureaucrat	b("Jacky", 1);
		// Bureaucrat	c("Michel", 150);
		// Bureaucrat	d("Tom", 151);

		std::cout << a << "\n";
		// std::cout << b << "\n";
		// std::cout << c << "\n";
		// std::cout << d << "\n";

		a.increment();
		// b.increment();
		// c.decrement();
		// d.increment();

		std::cout << a << "\n";
		// std::cout << b << "\n";
		// std::cout << c << "\n";
		// std::cout << d << "\n";
	}
	catch(const std::exception	&e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return (0);
}
