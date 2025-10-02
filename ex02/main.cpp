/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:52:49 by rraumain          #+#    #+#             */
/*   Updated: 2025/10/02 10:49:04 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>

int	main()
{
	try
	{
		Bureaucrat	a("Jacky", 45);
		RobotomyRequestForm f1("test");
		
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
