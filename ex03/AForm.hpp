/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:38:00 by phudyka           #+#    #+#             */
/*   Updated: 2024/01/24 16:19:38 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
# define AForm_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class	Bureaucrat;

class AForm	
{
	private:
		const std::string	_name;
		const int	_to_sign;
		const int	_to_exec;
		bool		_signed;

	public:
		AForm();
		AForm(std::string name, int sign, int exec);
		AForm(AForm const &ref);
		AForm &operator=(AForm const &ref);
		virtual ~AForm();

		int		getGradeToSign(void) const;
		int		getGradeToExec(void) const;
		bool	getSignature(void) const;
		void	setSignature(const bool _new);
		const std::string	getName(void) const;
		void	beSigned(Bureaucrat &ref);
		virtual void	execute(Bureaucrat const &exec) const = 0;

		class Exception : public std::exception
		{
			public:
					virtual const char *what() const throw();
		};

		class GradeTooLowException : public AForm::Exception
		{
			public:
					virtual const char *what() const throw();
		};

		class GradeTooHighException : public AForm::Exception
		{
			public:
					virtual const char *what() const throw();
		};

		class UnsignedFormException : public AForm::Exception
		{
			public:
					virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const AForm &AForm);

#endif