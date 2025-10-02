/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:52:49 by rraumain          #+#    #+#             */
/*   Updated: 2025/10/02 13:55:30 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>



int	main()
{
	for (int i = 0; i < 4; i++)
	{
		try
		{
			Bureaucrat bureaucrats[4] = {
				Bureaucrat("Jacky (Intern)", 150),
				Bureaucrat("Michel (Just enough)", 145),
				Bureaucrat("Tom (Best employee)", 25),
				Bureaucrat("Jerry (CEO)", 1)
			};

			ShrubberyCreationForm f1("form 1");
			RobotomyRequestForm f2("form 2");
			PresidentialPardonForm f3("form 3");

			AForm	*forms[3] = { &f1, &f2, &f3 };

			std::cout << "\n-----------Signing-----------\n";
			for (int j = 0; j < 3; j++)
			{
				std::cout << *forms[j] << std::endl;
				bureaucrats[i].signForm(*forms[j]);
				std::cout << *forms[j] << "\n" << std::endl;
			}

			std::cout << "\n-----------Executing-----------\n";
			for (int j = 0; j < 3; j++)
			{
				bureaucrats[i].executeForm(*forms[j]);
			}

			std::cout << std::endl;

		}
		catch(const std::exception	&e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	
	return (0);
}
