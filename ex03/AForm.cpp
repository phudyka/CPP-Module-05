/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:37:00 by phudyka           #+#    #+#             */
/*   Updated: 2024/01/24 16:20:09 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Default"), _to_sign(150), _to_exec(150), _signed(0)
{
	std::cout << "Default " << *this << " has been constructed" << std::endl;
}

AForm::AForm(std::string name, int sign, int exec) : _name(name), _to_sign(sign), _to_exec(exec), _signed(0)
{
	if (_to_sign > 150 || _to_exec > 150)
		throw (AForm::GradeTooLowException());
	else if (_to_sign < 1 || _to_exec < 1)
		throw (AForm::GradeTooHighException());
	else
		std::cout << *this << " has been constructed" << std::endl;
}

AForm::AForm(AForm const &ref) : _name(ref.getName()), _to_sign(ref.getGradeToSign()), _to_exec(ref.getGradeToExec()), _signed(ref.getSignature()) 
{
	std::cout << *this << " has been copied" << std::endl;
}

AForm &AForm::operator=(AForm const &ref)
{
	this->_signed = ref.getSignature();
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, const AForm &AForm)
{
	out << "AForm " << AForm.getName() << " at grade to sign " << AForm.getGradeToSign() << " and grade to execute "
		<< AForm.getGradeToExec() << " with signature equal to " << AForm.getSignature() << std::endl;
	return (out);
}

AForm::~AForm()
{
	std::cout << *this << " has been destroyed" << std::endl;
}

const std::string	AForm::getName(void) const
{
	return (this->_name);
}

int	AForm::getGradeToSign(void) const
{
	return (this->_to_sign);
}

int	AForm::getGradeToExec(void) const
{
	return (this->_to_exec);
}

bool	AForm::getSignature(void) const
{
	return (this->_signed);
}

void	AForm::setSignature(const bool _new)
{
	this->_signed = _new;
	std::cout << *this << " signed value has been set to " << _new << std::endl;
}

const char	*AForm::Exception::what() const throw()
{
	return ("AFormException");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char	*AForm::UnsignedFormException::what() const throw()
{
	return ("Cannot execute when unsigned");
}

void	AForm::beSigned(Bureaucrat &ref)
{
	int	grade;

	grade = ref.getGrade();
	if (grade > _to_sign)
	{
		throw (AForm::GradeTooLowException());
		return ;
	}
	_signed = true;
	std::cout << *this << " has been signed by " << ref.getName() << " graded " << ref.getGrade() << std::endl;
}