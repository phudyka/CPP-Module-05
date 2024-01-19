/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:51:56 by phudyka           #+#    #+#             */
/*   Updated: 2024/01/19 11:58:34 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
	{
        Bureaucrat johnDoe("John Doe", 10);
        Form taxForm("Taxes", 5, 8);
        std::cout << "Initial state of the form:\n" << taxForm << std::endl;
        taxForm.signing(johnDoe);
        std::cout << "\nState of the form after signing attempt:\n" << taxForm << std::endl;
        Bureaucrat janeDoe("Jane Doe", 3);
        taxForm.signing(janeDoe);
        std::cout << "\nState of the form after Jane Doe's signing attempt:\n" << taxForm << std::endl;
        Form invalidForm("Invalid Form", 0, 160);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}   
	return 0;
}
