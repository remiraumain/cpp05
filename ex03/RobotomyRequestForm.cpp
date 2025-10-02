/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 18:25:02 by rraumain          #+#    #+#             */
/*   Updated: 2025/09/30 20:08:59 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 25, 5), _target("Default")
{
	std::cout << "RobotomyRequestForm constructed\n";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm constructed\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) 
	: AForm(copy), _target(copy._target)
{
	std::cout << "RobotomyRequestForm copy-constructed\n";
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	if (this != &copy)
	{
		AForm::operator=(copy);
		_target = copy._target;
	}
	std::cout << "RobotomyRequestForm copy-assigned\n";
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructed\n";
}

void RobotomyRequestForm::action() const
{
	std::srand(std::time(0));
	int	isSuccess = std::rand() % 2;

	if (isSuccess)
	{
		std::cout << "*BZZZZZZ*\n" << "*SKRRRRRR*\n"
		<< _target << " has been robotomized successfull\n"; 
	}
	else 
		throw(std::logic_error("RobotomyRequestForm: unfortunately the hodes were not by your side"));
}
