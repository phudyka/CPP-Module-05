/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:20:32 by dtassel           #+#    #+#             */
/*   Updated: 2024/01/24 14:46:13 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
    std::srand(std::time(0));

    Intern intern;
    AForm *robo_form;
    AForm *shrub_form;
    AForm *president_form;
    AForm *unknown_form;

    robo_form = intern.makeForm("Robotomic Request", "robo");
    president_form = intern.makeForm("Presidential Request", "president");
    shrub_form = intern.makeForm("Shrubbery Request", "shrub");

    try
    {
        unknown_form = intern.makeForm("Unknown Form", "idk");
    }
    catch (Intern::Exception &e)
    {
        std::cout << e.what() << std::endl << std::endl;
    }

    if (robo_form)
        delete robo_form;
    if (shrub_form)
        delete shrub_form;
    if (president_form)
        delete president_form;
    if (unknown_form)
        delete unknown_form;

    return (0);
}
