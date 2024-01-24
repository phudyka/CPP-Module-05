/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 10:14:04 by phudyka           #+#    #+#             */
/*   Updated: 2024/01/24 09:44:21 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <ctime>
#include <cstdlib>
#include "AForm.hpp"

class AForm;

class RobotomyRequestForm : public AForm
{
	private:
		std::string	_target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &ref);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &ref);
		~RobotomyRequestForm();

		std::string	getTarget(void) const;

		void	execute(Bureaucrat const &executor) const;

		class FailureException : public AForm::Exception
		{
			public:
					virtual const char	*what() const throw();
		};
};

#endif