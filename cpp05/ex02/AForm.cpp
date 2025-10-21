/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:33:04 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/10/20 18:27:06 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <sstream>
#include <iostream>

AForm::AForm() : name("default"),
				 isSigned(false),
				 gradeToSign(150),
				 gradeToExecute(150)
{
	FORM_CHECK_GRADE(name, gradeToSign);
	FORM_CHECK_GRADE(name, gradeToExecute);
}

AForm::AForm(std::string name,
			 int gradeToSign,
			 int gradeToExecute) : name(name),
								   isSigned(false),
								   gradeToSign(gradeToSign),
								   gradeToExecute(gradeToExecute)
{
	FORM_CHECK_GRADE(name, gradeToSign);
	FORM_CHECK_GRADE(name, gradeToExecute);
}

AForm::AForm(const AForm &form) : name(form.name),
								 isSigned(form.isSigned),
								 gradeToSign(form.gradeToSign),
								 gradeToExecute(form.gradeToExecute)
{
}

AForm::~AForm()
{
}

AForm &AForm::operator=(const AForm &form)
{
	if (this != &form)
	{
		this->isSigned = form.isSigned;
		this->gradeToSign = form.gradeToSign;
		this->gradeToExecute = form.gradeToExecute;
	}
	return (*this);
}

const std::string &AForm::getName() const
{
	return (name);
}

bool AForm::getIsSigned() const
{
	return (isSigned);
}

int AForm::getGradeToSign() const
{
	return (gradeToSign);
}

int AForm::getGradeToExecute() const
{
	return (gradeToExecute);
}

void AForm::beSigned(Bureaucrat const &bur)
{
	if (isSigned)
		throw(std::runtime_error("form " + name + " is already signed"));
	if (bur.getGrade() > gradeToSign)
		__THROW_AFORM_GRADETOOLOW(name, bur.getGrade());
	isSigned = true;
}

void AForm::execute(Bureaucrat const &executor)
{
	if (executor.getGrade() > gradeToExecute)
		__THROW_AFORM_GRADETOOLOW(name, executor.getGrade());
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
	std::cout << "Form (" << form.getName() << "):\n"
			  << "\tisSigned: " << form.getIsSigned() << "\n"
			  << "\tgradeToSign: " << form.getGradeToSign() << "\n"
			  << "\tgradeToExecute: " << form.getGradeToExecute() << "\n"
			  << std::endl;
	return (os);
}

AForm::GradeTooHighException::GradeTooHighException(const std::string msg, const std::string name, int grade)
{
	std::ostringstream oss;

	oss << msg << ": Grade " << grade << " is too high for '" << name << "' (minimum is 1)";
	GradeTooHighException::message = oss.str();
}

AForm::GradeTooHighException::GradeTooHighException(const std::string msg, const std::string name, int grade, const char *file, int line)
{
	std::ostringstream oss;

	oss << msg << ": Grade " << grade << " is too high for '" << name << "' (minimum is 1) at (" << file << ":" << line << ")";
	GradeTooHighException::message = oss.str();
}

AForm::GradeTooHighException::~GradeTooHighException() throw()
{
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return (message.c_str());
}

AForm::GradeTooLowException::GradeTooLowException(const std::string msg, const std::string name, int grade)
{
	std::ostringstream oss;

	oss << msg << ": Grade " << grade << " is too low for '" << name << "' (maximum is 150)";
	GradeTooLowException::message = oss.str();
}

AForm::GradeTooLowException::GradeTooLowException(const std::string msg, const std::string name, int grade, const char *file, int line)
{
	std::ostringstream oss;

	oss << msg << ": Grade " << grade << " is too low for '" << name << "' (maximum is 150) at (" << file << ":" << line << ")";
	GradeTooLowException::message = oss.str();
}

AForm::GradeTooLowException::~GradeTooLowException() throw()
{
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return (message.c_str());
}
