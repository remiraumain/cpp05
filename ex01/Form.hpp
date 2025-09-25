/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 15:58:42 by rraumain          #+#    #+#             */
/*   Updated: 2025/09/25 09:08:57 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <ostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form(const std::string &name, const int signGrade, const int execGrade);
		Form(const Form &copy);
		Form	&operator=(const Form &copy);
		~Form();

		const std::string	&getName() const;
		bool				getSigned() const;
		int					getSignGrade() const;
		int					getExecGrade() const;

		void	beSigned(const Bureaucrat &b);

	class GradeTooHighException : public std::exception 
	{
		public:
			const char	*what() const throw();
	};

	class GradeTooLowException : public std::exception 
	{
		public:
			const char	*what() const throw();
	};
		
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;
};

std::ostream	&operator<<(std::ostream &os, const Form &f);

#endif