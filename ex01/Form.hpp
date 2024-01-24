/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:00:00 by phudyka           #+#    #+#             */
/*   Updated: 2024/01/24 16:17:43 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form
{
	private:
		const std::string	_name;
		const int	_to_sign;
		const int	_to_exec;
		bool		_signed;

	public:
		Form();
		Form(std::string name, int sign, int exec);
		Form(Form const &ref);
		Form &operator=(Form const &ref);
		~Form();

		int		getGradeToSign(void) const;
		int		getGradeToExec(void) const;
		bool	getSignature(void) const;
		void	setSignature(const bool _new);
		void	beSigned(Bureaucrat &ref);
		const std::string	getName(void) const;

		class Exception : public std::exception
		{
			public:
					virtual const char *what() const throw();
		};

		class GradeTooLowException : public Form::Exception
		{
			public:
					virtual const char *what() const throw();
		};

		class GradeTooHighException : public Form::Exception
		{
			public:
					virtual const char *what() const throw();
		};

};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif