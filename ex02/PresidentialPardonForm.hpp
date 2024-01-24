/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phudyka <phudyka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 10:13:52 by phudyka           #+#    #+#             */
/*   Updated: 2024/01/24 09:43:49 by phudyka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <ctime>
#include <cstdlib>
#include "AForm.hpp"

class AForm;

class PresidentialPardonForm : public AForm
{
	private:
		std::string	_target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &ref);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &ref);
		~PresidentialPardonForm();

		std::string	getTarget(void) const;

		void	execute(Bureaucrat const &executor) const;

		class FailureException : public AForm::Exception
		{
			public:
					virtual const char	*what() const throw();
		};
};

#endif