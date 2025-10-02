/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:52:49 by rraumain          #+#    #+#             */
/*   Updated: 2025/10/02 17:41:39 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int	main()
{
	try
	{
		Intern someRandomIntern;
		AForm* rrf;
		Bureaucrat ceo("ceo", 1);
		
		std::string names[4] = {
			"shrubbery creation",
        	"robotomy request",
        	"presidential pardon",
			"weird form"
		};
		
		for (int i = 0; i < 4; i++)
		{
			rrf = someRandomIntern.makeForm(names[i], "Bender");
			std::cout << *rrf << "\n";
			ceo.signForm(*rrf);
			ceo.executeForm(*rrf);
			delete rrf;
			std::cout << std::endl;
		}
	}
	catch(const std::exception	&e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return (0);
}
