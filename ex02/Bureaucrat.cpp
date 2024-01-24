/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:51:48 by phudyka           #+#    #+#             */
/*   Updated: 2024/01/24 09:45:28 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _grade(150), _name("Default")
{
	std::cout << "Default Bureaucrat has been constructed" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade > 150)
		throw (Bureaucrat::GradeTooHighException());
	else if (grade < 1)
		throw (Bureaucrat::GradeTooLowException());
	else
	{
		this->_grade = grade;
		std::cout << _name << " graded " << _grade << " has been constructed" << std::endl;
	}
}

Bureaucrat::Bureaucrat(Bureaucrat const &ref) : _name(ref.getName() + "_copy")
{
	this->_grade = ref.getGrade();
	std::cout << _name << " graded " << _grade << " has been copied" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &ref)
{
	this->_grade = ref.getGrade();
	return (*this);
}

const std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::setGrade(const int _new)
{
	this->_grade = _new;
	std::cout << this->_grade << " has been set to " << _new << " grade" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << " is at grade " << bureaucrat.getGrade();
	return (out);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << _name << " graded " << _grade << " has been destroyed" << std::endl;
}

void	Bureaucrat::incrementGrade(void)
{
	std::cout << _name << " graded " << " is ranking up by one" << std::endl;
	if (this->_grade - 1 < 1)
		throw (Bureaucrat::GradeTooHighException());
	else
		this->_grade--;
}

void	Bureaucrat::decrementGrade(void)
{
	std::cout << _name << " graded " << " is ranking down by one" << std::endl;
	if (this->_grade + 1 > 150)
		throw (Bureaucrat::GradeTooHighException());
	else
		this->_grade++;
}

const char	*Bureaucrat::Exception::what() const throw()
{
	return ("Exception");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade cannot go below 1");
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade cannot go above 150");
}

void	Bureaucrat::signForm(AForm &ref)
{
	try
	{
		ref.signing(*this);
		std::cout << this->_name << " graded " << this->_grade << " has signed " << ref << std::endl;
	}
	catch (AForm::Exception &except)
	{
		std::cout << this->_name << " graded " << this->_grade << " could not signed " << ref << " because of " << except.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const &ref)
{
	try
	{
		ref.execute(*this);
		std::cout << this->_grade << " has been executed " << ref << std::endl;
	}
	catch(AForm::Exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}