/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 12:54:37 by rraumain          #+#    #+#             */
/*   Updated: 2025/10/02 17:49:07 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &b)
{
	return (os << b.getName() << ", bureaucrat grade " << b.getGrade());
}

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	std::cout << "Bureaucrat constructed\n";
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
	std::cout << "Bureaucrat constructed\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : 
	_name(copy._name),
	_grade(copy._grade)
{
	std::cout << "Bureaucrat copy-constructed\n";
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &copy)
{
	if (this != &copy)
	{
		_grade = copy._grade;
	}
	std::cout << "Bureaucrat copy-assigned\n";
	return (*this);
}

Bureaucrat::~Bureaucrat() 
{
	std::cout << "Bureaucrat destructed\n";
}

const std::string	&Bureaucrat::getName() const
{
	return (_name);
}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

void	Bureaucrat::increment()
{
	if (_grade <= 1)
		throw(GradeTooHighException());
	_grade--;
}

void	Bureaucrat::decrement()
{
	if (_grade >= 150)
		throw(GradeTooLowException());
	_grade++;
}

void	Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << "\n";
	}
	catch(const std::exception	&e)
	{
		std::cout << _name << " couldn’t sign " << form.getName() 
		<< " because " << e.what() << "\n";
	}
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat: grade too high");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat: grade too low");
}
