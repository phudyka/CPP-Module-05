/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:51:56 by phudyka           #+#    #+#             */
/*   Updated: 2024/01/22 15:46:47 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>

int main()
{
    std::cout << std::endl;
    std::cout << "CONSTRUCTING:" << std::endl;
    std::cout << "----------------------------" << std::endl;
    Bureaucrat bob("Bob", 1);
    Bureaucrat bill("Bill", 132);

    Form a("A13", 4, 6);
    Form b("B97", 146, 135);

    try {
        Form c("C46", 489, 1435);
    } catch (Form::Exception &e) {
        std::cout << "Constructor failure: " << e.what() << std::endl; 
    }

    try {
        Form c("D143", -583, -800);
    } catch (Form::Exception &e) {
        std::cout << "Constructor failure: " << e.what() << std::endl; 
    }
    std::cout << std::endl << std::endl;
    std::cout << std::endl;
    std::cout << "SIGN FORMS:" << std::endl;
    std::cout << "----------------------------" << std::endl;

    std::cout << "SIGN OK:" << std::endl;
    bob.signForm(a);
    std::cout << a << " just showed its current status" << std::endl;
    a.setSignature(false);
    std::cout << std::endl << std::endl;

    std::cout << "SIGN KO:" << std::endl;
    bill.signForm(a);
    std::cout << a << " just showed its current status" << std::endl;
    std::cout << std::endl << std::endl;

    std::cout << "SIGN OK:" << std::endl;
    bob.signForm(b);
    std::cout << b << " just showed its current status" << std::endl;
    b.setSignature(false);
    std::cout << std::endl << std::endl;

    std::cout << "SIGN OK:" << std::endl;
    bill.signForm(b);
    std::cout << b << " just showed its current status" << std::endl;
    std::cout << std::endl << std::endl;

    std::cout << std::endl;
    std::cout << "DESTRUCTORS:" << std::endl;
    std::cout << "----------------------------" << std::endl;

    return 0;
}

