/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 09:49:13 by rraumain          #+#    #+#             */
/*   Updated: 2025/10/02 14:31:46 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iomanip>
#include <iostream>

std::ostream	&operator<<(std::ostream &os, const AForm &f)
{
	os << std::right << "|" 
	<< std::setw(10) << "Name" << "|"
	<< std::setw(10) << "Signed" << "|"
	<< std::setw(10) << "Sign Grade" << "|"
	<< std::setw(10) << "Sign Exec" << "|"
	<< std::endl;

	std::string name = f.getName();
	if (name.length() > 10)
		name = name.substr(0, 9) + ".";
	
	os << std::right << "|" 
	<< std::setw(10) << name << "|"
	<< std::setw(10) << f.getSigned() << "|"
	<< std::setw(10) << f.getSignGrade() << "|"
	<< std::setw(10) << f.getExecGrade() << "|";
	
	return (os);
}

AForm::AForm() : _name("Default"), _signGrade(150), _execGrade(150) {};

AForm::AForm(const std::string &name, const int signGrade, const int execGrade) :
	_name(name),
	_signed(false),
	_signGrade(signGrade),
	_execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
	std::cout << "AForm constructed\n";
}

AForm::AForm(const AForm &copy) :
	_name(copy._name),
	_signed(copy._signed),
	_signGrade(copy._signGrade),
	_execGrade(copy._execGrade)
{
	std::cout << "AForm copy-constructed\n";
}

AForm	&AForm::operator=(const AForm &copy)
{
	if (this != &copy)
	{
		_signed = copy._signed;
	}
	std::cout << "AForm copy-assigned\n";
	return (*this);
}

AForm::~AForm() 
{
	std::cout << "AForm destructed\n";
}

const std::string	&AForm::getName() const
{
	return (_name);
}

bool	AForm::getSigned() const
{
	return (_signed);
}

int	AForm::getSignGrade() const
{
	return (_signGrade);
}

int	AForm::getExecGrade() const
{
	return (_execGrade);
}

void	AForm::beSigned(const Bureaucrat &b)
{
	if (_signed)
		throw(std::logic_error("Form: already signed"));
	if (_signGrade < b.getGrade())
		throw(GradeTooLowException());
	_signed = true;
}

void	AForm::execute(const Bureaucrat &executor) const
{
	if (!_signed)
		throw(std::logic_error("Form: not signed"));
	if ( _execGrade < executor.getGrade())
		throw(GradeTooLowException());
	action();
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("AForm: grade too high");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("AForm: grade too low");
}
