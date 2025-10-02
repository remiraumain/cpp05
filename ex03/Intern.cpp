/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:08:16 by rraumain          #+#    #+#             */
/*   Updated: 2025/10/02 17:46:06 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern()
{
    std::cout << "Intern constructed\n";
}

Intern::Intern(const Intern &copy)
{
    (void)copy;
    std::cout << "Intern copy-constructed\n";
}

Intern	&Intern::operator=(const Intern &copy)
{
    (void)copy;
    std::cout << "Intern copy-assigned\n";
	return (*this);
}

Intern::~Intern()
{
    std::cout << "Intern destructed\n";
}

AForm   *Intern::makeForm(std::string name, std::string target)
{
    int i = 0;

    std::string forms[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    while (i < 3 && name != forms[i])
        i++;
        
    switch (i)
    {
    case 0:
        return (new ShrubberyCreationForm(target));
        break;

    case 1:
        return (new RobotomyRequestForm(target));
        break;

    case 2:
        return (new PresidentialPardonForm(target));
        break;
    
    default:
        throw std::runtime_error("Intern: Unknown form name");
        break;
    }
}