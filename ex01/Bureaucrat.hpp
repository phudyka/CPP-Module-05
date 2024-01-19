/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:51:50 by phudyka           #+#    #+#             */
/*   Updated: 2024/01/18 14:53:12 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUEAUCRAT_HPP
# define BUEAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat
{
	private:
		int					_grade;
		const std::string	_name;

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const &ref);
		Bureaucrat	&operator=(Bureaucrat const &ref);
		~Bureaucrat();

	void	incrementGrade(void);
	void	decrementGrade(void);
	void	setGrade(const int _new);
	int	getGrade(void) const;
	const std::string	getName(void) const;

	class Exception : public std::exception
	{
		public:
				virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
				virtual const char *what() const throw();
	};

	class GradeTooHighException : public std::exception
	{
		public:
				virtual const char *what() const throw();
	};

};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif