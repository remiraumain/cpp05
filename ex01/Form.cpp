/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 16:10:26 by rraumain          #+#    #+#             */
/*   Updated: 2025/09/30 15:30:26 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iomanip>
#include <iostream>

std::ostream	&operator<<(std::ostream &os, const Form &f)
{
	os << std::right << "|" 
	<< std::setw(10) << "Name" << "|"
	<< std::setw(10) << "Signed" << "|"
	<< std::setw(10) << "Sign Grade" << "|"
	<< std::setw(10) << "Sign Exec" << "|"
	<< std::endl;
	
	os << std::right << "|" 
	<< std::setw(10) << f.getName() << "|"
	<< std::setw(10) << f.getSigned() << "|"
	<< std::setw(10) << f.getSignGrade() << "|"
	<< std::setw(10) << f.getExecGrade() << "|";
	
	return (os);
}

Form::Form(const std::string &name, const int signGrade, const int execGrade) :
	_name(name),
	_signed(false),
	_signGrade(signGrade),
	_execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
	std::cout << "Form constructed\n";
}

Form::Form(const Form &copy) :
	_name(copy._name),
	_signed(copy._signed),
	_signGrade(copy._signGrade),
	_execGrade(copy._execGrade)
{
	std::cout << "Form copy-constructed\n";
}

Form	&Form::operator=(const Form &copy)
{
	if (this != &copy)
	{
		_signed = copy._signed;
	}
	std::cout << "Form copy-assigned\n";
	return (*this);
}

Form::~Form() 
{
	std::cout << "Form destructed\n";
}

const std::string	&Form::getName() const
{
	return (_name);
}

bool	Form::getSigned() const
{
	return (_signed);
}

int	Form::getSignGrade() const
{
	return (_signGrade);
}

int	Form::getExecGrade() const
{
	return (_execGrade);
}

void	Form::beSigned(const Bureaucrat &b)
{
	if (_signed)
		return ;
	if (_signGrade < b.getGrade())
		throw(GradeTooLowException());
	_signed = true;
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Form: grade too high");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Form: grade too low");
}
