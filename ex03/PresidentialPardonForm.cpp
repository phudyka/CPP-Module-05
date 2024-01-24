/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 10:13:43 by phudyka           #+#    #+#             */
/*   Updated: 2024/01/22 15:13:27 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Default Presidential Parent", 25, 5)
{
	this->_target = "Default";
	std::cout << "Presidential Pardon" << *this << "has been constructed as default" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Parent", 25, 137)
{
	this->_target = target;
	std::cout << "Presidential Pardon" << *this << "has been constructed" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& ref) : AForm(ref.getName(), ref.getGradeToSign(), ref.getGradeToExec())
{
	this->_target = ref.getTarget();
	std::cout << "Presidential Pardon" << *this << "has been copied" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& ref)
{
	this->_target = ref.getTarget();
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Presidential Pardon" << *this << "has been destroyed" << std::endl;
}

std::string	PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSignature())
		throw (AForm::UnsignedFormException());
	else if (executor.getGrade() > this->getGradeToExec())
		throw (AForm::GradeTooLowException());
	else
		std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl; 
}