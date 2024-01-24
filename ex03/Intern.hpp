/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:03:09 by phudyka           #+#    #+#             */
/*   Updated: 2024/01/24 11:20:18 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class Intern
{
	public:
	Intern();
	Intern(const Intern& src);
	Intern& operator=(const Intern& src);
	~Intern();

	AForm *makeForm(std::string formName, std::string formTarget);
	
	class Exception : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

#endif