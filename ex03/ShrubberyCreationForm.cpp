/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 10:13:48 by phudyka           #+#    #+#             */
/*   Updated: 2024/01/24 09:47:14 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Default Shrub Parent", 25, 5)
{
	this->_target = "Default";
	std::cout << "Shrubbery Creation" << *this << "has been constructed as default" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrub Parent", 25, 137)
{
	this->_target = target;
	std::cout << "Shrubbery Creation" << *this << "has been constructed" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& ref) : AForm(ref.getName(), ref.getGradeToSign(), ref.getGradeToExec())
{
	this->_target = ref.getTarget();
	std::cout << "Shrubbery Creation" << *this << "has been copied" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& ref)
{
	this->_target = ref.getTarget();
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Shrubbery Creation" << *this << "has been destroyed" << std::endl;
}

std::string	ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::string tree =
"        # #### ####          \n"
"   ###\\/#|### |/####        \n"
"   ##\\/#/ \\||/##/_/##/_#   \n"
" ####  \\/###|/ \\/ # ###    \n"
"##_\\_#\\_\\## | #/###_/_####\n"
"## #### # \\ #| /  #### ##/##\n"
"  __#_--###`  |{,###---###-~ \n"
"                \\ }{        \n"
"                 }}{         \n"
"                 }}{         \n"
"                 {{}         \n"
"             -=-~{ .-^- _    \n"
"                 `}          \n"
"                  {          \n";

	if (!this->getSignature())
		throw (AForm::UnsignedFormException());
	else if ((executor.getGrade() > this->getGradeToExec()))
		throw (AForm::GradeTooLowException());
	else
	{
		std::ofstream	ofs(this->_target.c_str());
		if (!ofs.is_open())
		{
			std::cout << "Output file failed to open" << std::endl;
			return ;
		}
		ofs << tree;
	}
}