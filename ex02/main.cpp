/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:51:56 by phudyka           #+#    #+#             */
/*   Updated: 2024/01/24 16:07:19 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	std::srand(std::time(0));

	Bureaucrat				bob("Bob", 1);
	Bureaucrat				bill("Bill", 142);
	ShrubberyCreationForm	shrub("shrub");
	RobotomyRequestForm		robo("robo");
	PresidentialPardonForm	president("president");
	std::cout << std::endl << std::endl;

	std::cout << "SHRUBBERY CREATION FORM:" << std::endl;
	std::cout << "----------------------------" << std::endl;

	std::cout << std::endl << "[UNSIGNED]" << std::endl;
	bob.executeForm(shrub);
	shrub.beSigned(bob);

	std::cout << std::endl << "[SIGNED]" << std::endl;
	bob.executeForm(shrub);
	std::cout << std::endl;

	std::cout << std::endl << "[GRADE TO EXE TOO LOW]" << std::endl;
	bill.executeForm(shrub);
	std::cout << std::endl << std::endl;

	std::cout << std::endl;
	std::cout << "ROBOTOMY REQUEST FORM:" << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << std::endl << "[UNSIGNED]" << std::endl;
	bob.executeForm(robo);
	robo.beSigned(bob);

	std::cout << std::endl << "[SIGNED (50% failure chance)]" << std::endl;
	bob.executeForm(robo);
	bob.executeForm(robo);
	bob.executeForm(robo);
	bob.executeForm(robo);
	bob.executeForm(robo);
	std::cout << std::endl;

	std::cout << std::endl << "[GRADE TO EXE TOO LOW]" << std::endl;
	bill.executeForm(robo);
	std::cout << std::endl << std::endl;

	std::cout << std::endl;
	std::cout << "PRESIDENTIAL PARDON FORM:" << std::endl;

	std::cout << std::endl << "[UNSIGNED]" << std::endl;
	bob.executeForm(president);
	president.beSigned(bob);

	std::cout << std::endl << "[SIGNED]" << std::endl;
	bob.executeForm(president);
	std::cout << std::endl;

	std::cout << std::endl << "[GRADE TO EXE TOO LOW]" << std::endl;
	bill.executeForm(president);
	std::cout << std::endl; 
	return (0);
}