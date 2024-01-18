/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:51:56 by phudyka           #+#    #+#             */
/*   Updated: 2024/01/18 12:05:21 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

  #include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat highGradeBureaucrat("John Doe", 1);
        Bureaucrat lowGradeBureaucrat("Jane Doe", 150);

        std::cout << highGradeBureaucrat << std::endl;
        std::cout << lowGradeBureaucrat << std::endl;

        highGradeBureaucrat.incrementGrade();
        lowGradeBureaucrat.decrementGrade();

        std::cout << highGradeBureaucrat << std::endl;
        std::cout << lowGradeBureaucrat << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}