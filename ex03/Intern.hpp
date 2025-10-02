/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:34:25 by rraumain          #+#    #+#             */
/*   Updated: 2025/10/02 15:07:58 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "AForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern &copy);
		Intern	&operator=(const Intern &copy);
		~Intern();
		AForm	*makeForm(std::string name, std::string target);
};

#endif