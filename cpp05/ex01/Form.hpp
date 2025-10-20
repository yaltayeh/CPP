/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:42:44 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/10/20 12:33:50 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include "Bureaucrat.hpp"

class Form
{
private:
	const std::string name;
	bool isSigned;
	int gradeToSign;
	int gradeToExecute;

public:
	Form();
	Form(std::string name, int gradeToSign, int gradeToExecute);
	~Form();
	Form &operator=(const Form &form);

	const std::string &getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	void beSigned(const Bureaucrat &bur);

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

std::ostream &operator<<(std::ostream &os, const Form &form);

#define __TRHOW_FORM_GRADETOOHIGH(name, grade) throw(Form::GradeTooHighException(__func__, name, grade, __FILE__, __LINE__))
#define __TRHOW_FORM_GRADETOOLOW(name, grade) throw(Form::GradeTooLowException(__func__, name, grade, __FILE__, __LINE__))

#define FORM_CHECK_GRADE(name, grade)               \
	{                                               \
		if (grade < 1)                              \
			__TRHOW_FORM_GRADETOOHIGH(name, grade); \
		if (grade > 150)                            \
			__TRHOW_FORM_GRADETOOLOW(name, grade);  \
	}\
