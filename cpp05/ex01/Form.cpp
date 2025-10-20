/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:33:04 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/10/15 17:50:42 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <sstream>
#include <iostream>

Form::Form()
{
}

Form::~Form()
{
}
























Form::GradeTooHighException::GradeTooHighException(const std::string msg, const std::string name, int grade)
{
	std::ostringstream oss;

	oss << msg << ": Grade " << grade << " is too high for '" << name << "' (minimum is 1)";
	GradeTooHighException::message = oss.str();
}

Form::GradeTooHighException::GradeTooHighException(const std::string msg, const std::string name, int grade, const char *file, int line)
{
	std::ostringstream oss;

	oss << msg << ": Grade " << grade << " is too high for '" << name << "' (minimum is 1) at (" << file << ":" << line << ")";
	GradeTooHighException::message = oss.str();
}

Form::GradeTooHighException::~GradeTooHighException() throw()
{
}

const char *Form::GradeTooHighException::what() const throw() 
{
	return (message.c_str());
}

Form::GradeTooLowException::GradeTooLowException(const std::string msg, const std::string name, int grade)
{
	std::ostringstream oss;

	oss << msg << ": Grade " << grade << " is too low for '" << name << "' (maximum is 150)";
	GradeTooLowException::message = oss.str();
}

Form::GradeTooLowException::GradeTooLowException(const std::string msg, const std::string name, int grade, const char *file, int line)
{
	std::ostringstream oss;

	oss << msg << ": Grade " << grade << " is too low for '" << name << "' (maximum is 150) at (" << file << ":" << line << ")";
	GradeTooLowException::message = oss.str();
}

Form::GradeTooLowException::~GradeTooLowException() throw()
{
}

const char *Form::GradeTooLowException::what() const throw() 
{
	return (message.c_str());
}
