/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:42:44 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/10/20 08:28:55 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Form
{
private:
    std::string	name;
    bool		isSigned;
	int			gradeToSign;
	int			gradeToExecute;
public:
    Form();
    ~Form();

	std::string	getName() const;
	bool 		getIsSigned() const;
	int			getGradeToSign() const;
	int			getGradeToExecute() const;

	class GradeTooHighException : public std::exception
	{
	private:
		std::string message;
	public:
		GradeTooHighException(const std::string msg, const std::string name, int grade);
		GradeTooHighException(const std::string msg, const std::string name, int grade, const char *file, int line);
		~GradeTooHighException() throw();
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	private:
		std::string message;
	public:
		GradeTooLowException(const std::string msg, const std::string name, int grade);
		GradeTooLowException(const std::string msg, const std::string name, int grade, const char *file, int line);
		~GradeTooLowException() throw();
		const char* what() const throw();
	};
};
