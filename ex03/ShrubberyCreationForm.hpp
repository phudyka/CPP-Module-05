/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 10:13:58 by phudyka           #+#    #+#             */
/*   Updated: 2024/01/24 09:44:37 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include <iomanip>
#include "AForm.hpp"

class AForm;

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	_target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &ref);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &ref);
		~ShrubberyCreationForm();

		std::string	getTarget(void) const;

		void	execute(Bureaucrat const &executor) const;

		class FailureException : public AForm::Exception
		{
			public:
					virtual const char	*what() const throw();
		};
};

#endif
