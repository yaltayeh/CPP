/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 06:42:23 by yaltayeh          #+#    #+#             */
/*   Updated: 2025/10/20 08:06:49 by yaltayeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <sstream>
#include <iostream>

Bureaucrat::Bureaucrat() : name("Default"), grade(150)
{
	BUREAUCRAT_CHECK_GRADE(name, grade);
	std::cout << GREEN << "✓ New bureaucrat '" << name << "' hired with grade " << grade << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bur) : name(bur.name), grade(bur.grade)
{
	BUREAUCRAT_CHECK_GRADE(name, grade);
	std::cout << GREEN << "✓ New bureaucrat '" << name << "' hired with grade " << grade << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade)
	: name(name),
	  grade(grade)
{
	BUREAUCRAT_CHECK_GRADE(name, grade);
	std::cout << GREEN << "✓ New bureaucrat '" << name << "' hired with grade " << grade << RESET << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->grade = other.grade;
		BUREAUCRAT_CHECK_GRADE(this->name, this->grade);
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << YELLOW << "⚠ Bureaucrat '" << name << "' has left the company." << RESET << std::endl;
}

const std::string &Bureaucrat::getName() const
{
	return (name);
}

int Bureaucrat::getGrade() const
{
	return (grade);
}

void Bureaucrat::promotion()
{
	int	new_grade;

	new_grade = grade - 1;
	BUREAUCRAT_CHECK_GRADE(name, new_grade);
	grade = new_grade;
	std::cout << CYAN << "↑ '" << name << "' has been promoted to grade " << grade << RESET << std::endl;
}

void Bureaucrat::demoted()
{
	int	new_grade;

	new_grade = grade + 1;
	BUREAUCRAT_CHECK_GRADE(name, new_grade);
	grade = new_grade;
	std::cout << MAGENTA << "↓ '" << name << "' has been demoted to grade " << grade << RESET << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bur)
{
	os << bur.name << ", bureaucrat grade " << bur.grade;
	return (os);
}







Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string msg, const std::string name, int grade)
{
	std::ostringstream oss;

	oss << msg << ": Grade " << grade << " is too high for '" << name << "' (minimum is 1)";
	GradeTooHighException::message = oss.str();
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string msg, const std::string name, int grade, const char *file, int line)
{
	std::ostringstream oss;

	oss << msg << ": Grade " << grade << " is too high for '" << name << "' (minimum is 1) at (" << file << ":" << line << ")";
	GradeTooHighException::message = oss.str();
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{
}

const char *Bureaucrat::GradeTooHighException::what() const throw() 
{
	return (message.c_str());
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string msg, const std::string name, int grade)
{
	std::ostringstream oss;

	oss << msg << ": Grade " << grade << " is too low for '" << name << "' (maximum is 150)";
	GradeTooLowException::message = oss.str();
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string msg, const std::string name, int grade, const char *file, int line)
{
	std::ostringstream oss;

	oss << msg << ": Grade " << grade << " is too low for '" << name << "' (maximum is 150) at (" << file << ":" << line << ")";
	GradeTooLowException::message = oss.str();
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{
}

const char *Bureaucrat::GradeTooLowException::what() const throw() 
{
	return (message.c_str());
}
