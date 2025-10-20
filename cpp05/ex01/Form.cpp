/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:33:04 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/10/20 18:17:51 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <sstream>
#include <iostream>

Form::Form() : name("default"),
			   isSigned(false),
			   gradeToSign(150),
			   gradeToExecute(150)
{
	FORM_CHECK_GRADE(name, gradeToSign);
	FORM_CHECK_GRADE(name, gradeToExecute);
}

Form::Form(std::string name,
		   int gradeToSign,
		   int gradeToExecute) : name(name),
								 isSigned(false),
								 gradeToSign(gradeToSign),
								 gradeToExecute(gradeToExecute)
{
	FORM_CHECK_GRADE(name, gradeToSign);
	FORM_CHECK_GRADE(name, gradeToExecute);
}

Form::~Form()
{
}

Form &Form::operator=(const Form &form)
{
	if (this != &form)
	{
		this->isSigned = form.isSigned;
		this->gradeToSign = form.gradeToSign;
		this->gradeToExecute = form.gradeToExecute;
	}
	return (*this);
}

const std::string &Form::getName() const
{
	return (name);
}

bool Form::getIsSigned() const
{
	return (isSigned);
}

int Form::getGradeToSign() const
{
	return (gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (gradeToExecute);
}

void Form::beSigned(Bureaucrat const &bur)
{
	if (isSigned)
		throw (std::runtime_error("form " + name + " is already signed"));
	if (bur.getGrade() > gradeToSign)
		__THROW_FORM_GRADETOOLOW(name, bur.getGrade());
	isSigned = true;
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

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	std::cout << "Form (" << form.getName() << "):\n"
			  << "\tisSigned: " << form.getIsSigned() << "\n"
			  << "\tgradeToSign: " << form.getGradeToSign() << "\n"
			  << "\tgradeToExecute: " << form.getGradeToExecute() << "\n"
			  << std::endl;
	return (os);
}
