/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 09:49:18 by rraumain          #+#    #+#             */
/*   Updated: 2025/09/30 17:00:23 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <ostream>

class Bureaucrat;

class AForm
{
	public:
		AForm(const std::string &name, const int signGrade, const int execGrade);
		AForm(const AForm &copy);
		AForm	&operator=(const AForm &copy);
		virtual ~AForm();

		const std::string	&getName() const;
		bool				getSigned() const;
		int					getSignGrade() const;
		int					getExecGrade() const;

		void	beSigned(const Bureaucrat &b);
		void	execute(const Bureaucrat &executor) const;

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

	protected:
		virtual void	action() const = 0;
		
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;
};

std::ostream	&operator<<(std::ostream &os, const AForm &f);

#endif