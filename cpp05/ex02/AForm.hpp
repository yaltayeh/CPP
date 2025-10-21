/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:42:44 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/10/20 18:24:50 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include "Bureaucrat.hpp"

class AForm
{
private:
	const std::string name;
	bool isSigned;
	int gradeToSign;
	int gradeToExecute;

public:
	AForm();
	AForm(std::string name, int gradeToSign, int gradeToExecute);
	AForm(const AForm &form);
	virtual ~AForm() = 0;
	virtual AForm &operator=(const AForm &form);

	const std::string &getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	void beSigned(Bureaucrat const &bur);
	virtual void execute(Bureaucrat const &executor) = 0;

	class GradeTooHighException : public std::exception
	{
	private:
		std::string message;

	public:
		GradeTooHighException(const std::string msg, const std::string name, int grade);
		GradeTooHighException(const std::string msg, const std::string name, int grade, const char *file, int line);
		~GradeTooHighException() throw();
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	private:
		std::string message;

	public:
		GradeTooLowException(const std::string msg, const std::string name, int grade);
		GradeTooLowException(const std::string msg, const std::string name, int grade, const char *file, int line);
		~GradeTooLowException() throw();
		const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#define __THROW_AFORM_GRADETOOHIGH(name, grade) throw(AForm::GradeTooHighException(__func__, name, grade, __FILE__, __LINE__))
#define __THROW_AFORM_GRADETOOLOW(name, grade) throw(AForm::GradeTooLowException(__func__, name, grade, __FILE__, __LINE__))

#define FORM_CHECK_GRADE(name, grade)               \
	{                                               \
		if (grade < 1)                              \
			__THROW_AFORM_GRADETOOHIGH(name, grade); \
		if (grade > 150)                            \
			__THROW_AFORM_GRADETOOLOW(name, grade);  \
	}\
