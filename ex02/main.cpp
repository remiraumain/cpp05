/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:52:49 by rraumain          #+#    #+#             */
/*   Updated: 2025/09/30 20:03:21 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int	main()
{
	try
	{
		Bureaucrat	a("Jacky", 101);
		ShrubberyCreationForm f1("test");
		
		std::cout << f1 << std::endl;
		a.signForm(f1);
		std::cout << f1 << std::endl;
		a.executeForm(f1);
	}
	catch(const std::exception	&e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return (0);
}
