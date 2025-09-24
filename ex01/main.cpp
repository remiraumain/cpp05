/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:52:49 by rraumain          #+#    #+#             */
/*   Updated: 2025/09/24 18:55:55 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int	main()
{
	try
	{
		Bureaucrat	a("Bob", 101);
		Form f1("form_1", 100, 1);
		
		std::cout << f1 << std::endl;
		a.signForm(f1);
		std::cout << f1 << std::endl;
	}
	catch(const std::exception	&e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return (0);
}
