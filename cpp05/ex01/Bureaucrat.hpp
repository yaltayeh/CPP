/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 21:45:03 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/10/20 18:19:00 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <exception>
#include <iostream>

// Forward declaration
class Form;

// Color codes
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define BOLD "\033[1m"

class Bureaucrat
{
private:
	const std::string name;
	int grade;

public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat &bur);
	Bureaucrat(const std::string name, int grade);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat();

	const std::string &getName() const;
	int getGrade() const;

	bool signForm(Form &form) const;

	void promotion();
	void demoted();

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

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bur);

#define __THROW_BUREAUCRAT_GRADETOOHIGH(name, grade) throw(Bureaucrat::GradeTooHighException(__func__, name, grade, __FILE__, __LINE__))
#define __THROW_BUREAUCRAT_GRADETOOLOW(name, grade) throw(Bureaucrat::GradeTooLowException(__func__, name, grade, __FILE__, __LINE__))

#define BUREAUCRAT_CHECK_GRADE(name, grade)               \
	{                                                     \
		if (grade < 1)                                    \
			__THROW_BUREAUCRAT_GRADETOOHIGH(name, grade); \
		if (grade > 150)                                  \
			__THROW_BUREAUCRAT_GRADETOOLOW(name, grade);  \
	}\
