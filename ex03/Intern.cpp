/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 10:03:07 by phudyka           #+#    #+#             */
/*   Updated: 2024/01/24 14:44:39 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "An Intern has been constructed" << std::endl;
}

Intern::Intern(const Intern &src)
{
    (void)src;
    std::cout << "An Intern has been constructed from copy" << std::endl;
}

Intern &Intern::operator=(const Intern &src)
{
    (void)src;
    std::cout << "They are the same Interns" << std::endl;
    return (*this);
}

Intern::~Intern()
{
    std::cout << "An Intern has been destroyed" << std::endl;
}

static AForm *newRobo(std::string target)
{
    return (new RobotomyRequestForm(target));
}

static AForm *newShrub(std::string target)
{
    return (new ShrubberyCreationForm(target));
}

static AForm *newPresident(std::string target)
{
    return (new PresidentialPardonForm(target));
}

const char *Intern::Exception::what() const throw()
{
    return ("Unknown Form's Exception");
}

AForm *Intern::makeForm(std::string formName, std::string formTarget)
{
    AForm *ret = NULL;
    AForm *(*tab[3])(std::string target) = {newRobo, newShrub, newPresident};
    std::string msg[3] = {"Robotomic Request", "Shrubbery Request", "Presidential Request"};

    for (int i = 0; i < 3; i++)
    {
        if (formName == msg[i])
        {
            ret = tab[i](formTarget);
            break;
        }
    }
    if (ret)
    {
        std::cout << "Intern creates " << *ret << std::endl;
    }
    else
    {
        std::cout << "Unknown form name: " << formName << std::endl;
        throw Intern::Exception();
    }
    return (ret);
}
