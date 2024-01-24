/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 10:13:46 by phudyka           #+#    #+#             */
/*   Updated: 2024/01/22 11:55:51 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Default Robotomic Parent", 72, 45)
{
	this->_target = "Default";
	std::cout << "Robotomy Request" << *this << "has been constructed as default" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomic Parent", 72, 45)
{
	this->_target = target;
	std::cout << "Robotomy Request" << *this << "has been constructed" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& ref) : AForm(ref.getName(), ref.getGradeToSign(), ref.getGradeToExec())
{
	this->_target = ref.getTarget();
	std::cout << "Robotomy Request" << *this << "has been copied" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& ref)
{
	this->_target = ref.getTarget();
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Robotomy Request" << *this << "has been destroyed" << std::endl;
}

std::string	RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

const char	*RobotomyRequestForm::FailureException::what() const throw()
{
	return ("Robotomy Failure !");
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	int	success;

    if (!this->getSignature())
        throw (AForm::UnsignedFormException());
    else if (executor.getGrade() > this->getGradeToExec()) {
        throw (AForm::GradeTooLowException());
    }
	success = std::rand() % 2;
    if (success)
        std::cout << "* Drill noises * " << _target << " has been robotomized successfully" << std::endl;
	else
        std::cout << "* Drill noises * Robotomy failed for " << _target << std::endl;
}