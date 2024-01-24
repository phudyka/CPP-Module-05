/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:00:03 by phudyka           #+#    #+#             */
/*   Updated: 2024/01/24 16:18:41 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default"), _to_sign(150), _to_exec(150), _signed(0)
{
	std::cout << "Default " << *this << " has been constructed" << std::endl;
}

Form::Form(std::string name, int sign, int exec) : _name(name), _to_sign(sign), _to_exec(exec), _signed(0)
{
	if (_to_sign > 150 || _to_exec > 150)
		throw (Form::GradeTooLowException());
	else if (_to_sign < 1 || _to_exec < 1)
		throw (Form::GradeTooHighException());
	else
		std::cout << *this << " has been constructed" << std::endl;
}

Form::Form(Form const &ref) : _name(ref.getName()), _to_sign(ref.getGradeToSign()), _to_exec(ref.getGradeToExec()), _signed(ref.getSignature()) 
{
	std::cout << *this << " has been copied" << std::endl;
}

Form &Form::operator=(Form const &ref)
{
	this->_signed = ref.getSignature();
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, const Form &form)
{
	out << "Form " << form.getName() << " at grade to sign " << form.getGradeToSign() << " and grade to execute "
		<< form.getGradeToExec() << " with signature equal to " << form.getSignature() << std::endl;
	return (out);
}

Form::~Form()
{
	std::cout << *this << " has been destroyed" << std::endl;
}

const std::string	Form::getName(void) const
{
	return (this->_name);
}

int	Form::getGradeToSign(void) const
{
	return (this->_to_sign);
}

int	Form::getGradeToExec(void) const
{
	return (this->_to_exec);
}

bool	Form::getSignature(void) const
{
	return (this->_signed);
}

void	Form::setSignature(const bool _new)
{
	this->_signed = _new;
	std::cout << *this << " signed value has been set to " << _new << std::endl;
}

const char	*Form::Exception::what() const throw()
{
	return ("FormException");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

void	Form::beSigned(Bureaucrat &ref)
{
	int	grade;

	grade = ref.getGrade();
	if (grade > _to_sign)
	{
		throw (Form::GradeTooLowException());
		return ;
	}
	_signed = true;
	std::cout << *this << " has been signed by " << ref.getName() << " graded " << ref.getGrade() << std::endl;
}